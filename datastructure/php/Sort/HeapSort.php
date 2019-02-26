<?php
include "./Sort.php";

//namespace Cclehui\Study\Sort


class HeapSort extends Sort {

    public function sort($data_set, $start_index = null, $end_index = null) {
        if (!$data_set || !is_array($data_set)) {
            return $data_set;
        }

        return $result;
    }
    
}


$sort_obj  = new HeapSort();
$data_set = $sort_obj->getRandomData(mt_rand(1, 25));

$sort_obj->showData($data_set);

$sort_obj->showData($sort_obj->sort($data_set));



