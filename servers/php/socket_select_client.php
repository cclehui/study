<?php
/**
 *  
 * socket select io模型 客户端程序  
 *  
 */

$service_port = 10006;
$address = '127.0.0.1';

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($socket === false) {
    echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "\n";
}

$result = socket_connect($socket, $address, $service_port);
//var_dump(socket_set_nonblock($socket));
if($result === false) {
    echo "socket_connect() failed.\nReason: ($result) " . socket_strerror(socket_last_error($socket)) . "\n";
}

echo "connected source $result\n";

$count = 1;


do{
    $out = "";



    //$in = "test string " . date("Y-m-d H:i:s") ;

    echo "please input you data:\n";
    $console_input = trim(fgets(STDIN), "\r\n");
    //$console_input .= "\t" . time();

    //echo "aaaa:", $console_input, "\n";

    socket_write($socket, $console_input, strlen($console_input));

    $out = socket_read($socket, 8192);
    echo $count, "\t", $out, "\n";

    $out = $out ? $out : 1;
    //sleep(2);

    $count++;

} while ($out);

socket_close($socket);
