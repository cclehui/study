<?php

class BaseList {

    public function getRandomData($data_num) {

        $result = [];

        for ($i = 0; $i <= $data_num ; $i++) {
            $result[] = mt_rand(1, 10000);
        }

        return $result;
    
    }
    
}

