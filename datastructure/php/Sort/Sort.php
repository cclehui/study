<?php



class Sort {

    public function getRandomData($data_num) {

        $result = [];

        for ($i = 0; $i <= $data_num ; $i++) {
            $result[] = mt_rand(1, 10000);
        }

        return $result;
    
    }

    public function showData($data_set) {
        if (!$data_set || !is_array($data_set)) {
            echo "数据为空\n";
        }

        echo implode(",", $data_set) . "\n"; 
    }
    
}
