<?php
/**
 * socket select io模型 服务端程序  
 *  
 */

error_reporting(E_ALL);
set_time_limit(0);
//ob_implicit_flush();

$address = '127.0.0.1';
$port = 10006;
//创建端口
if( ($sock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) === false) {
    echo "socket_create() failed :reason:" . socket_strerror(socket_last_error()) . "\n";
}

//绑定
if (socket_bind($sock, $address, $port) === false) {
    echo "socket_bind() failed :reason:" . socket_strerror(socket_last_error($sock)) . "\n";
}

//监听
if (socket_listen($sock, 5) === false) {
    echo "socket_bind() failed :reason:" . socket_strerror(socket_last_error($sock)) . "\n";
}

//socket_set_nonblock($sock);

$read_array = array($sock);
$write_array = array();

$connected_socket = array();
$result_array = array();

//开始处理数据和连接
while (1) {
    $read_array = array_merge($connected_socket, array($sock));
    $write_array = $result_array ? $connected_socket : null;
    //$exception_array = array(STDOUT);
    $exception_array = null;

    $selected_count = socket_select($read_array, $write_array, $exception_array, 3);

    //sleep(1);
    print_r($connected_socket);
    print_r($read_array);
    print_r($write_array);
    print_r($result_array);
    echo "\ncount:", $selected_count, "\n";

    if ($selected_count) {

        //处理读
        if ($read_array) {
            foreach ($read_array as $item) {

                if ($item == $sock) {

                    $new_connect = socket_accept($item);
                    if ($new_connect) {
                        socket_set_nonblock($new_connect);//新链接设置为非阻塞的
                        $connected_socket[] = $new_connect;
                    }

                } else {
                    $temp_result = doRead($item);
                    $index = array_search($item, $connected_socket);

                    if ($temp_result === false) {
                        socket_close($item);
                        unset($connected_socket[$index]);
                    } elseif ($temp_result) {
                        $result_array[$index] = $temp_result;
                    }
                }
            }
        }

        //处理写
        if ($write_array) {
            foreach ($write_array as $item) {
                $index = array_search($item, $connected_socket);

                if ($index !== false && isset($result_array[$index]) && $result_array[$index]) {
                    if ( false === socket_write($item, $result_array[$index], strlen($result_array[$index]))) {
                        socket_close($item);
                    }

                    unset($result_array[$index]);
                }
            }
        }
    }
}

//关闭socket
socket_close($sock);

/******************************/
function doRead($connected_socket) {

    $buffer = "";

    do {

        $temp_buf = socket_read($connected_socket, 8192);

        $buffer .= $temp_buf;

    } while ($temp_buf);

    if ($temp_buf === "") {
        $str = "\n";
        socket_write($connected_socket, $str, strlen($str));
        $error_code = socket_last_error($connected_socket);
        //var_dump($error_code);
        //echo socket_strerror($error_code), "\n";
        //echo $error_code, "\txxxxxxxxxx\n";
        if (in_array($error_code, array(11, 32))) {//链接被关闭
            return false;
        }
    }

    $result = $buffer ? doAction($buffer) : "";

    return $result;

}

function doAction($str) {
    return strrev($str);
}



?>
/**
 *  
 */
