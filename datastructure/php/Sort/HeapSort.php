<?php
include "./Sort.php";

//namespace Cclehui\Study\Sort


//https://blog.csdn.net/u013384984/article/details/79496052
class HeapSort extends Sort {

    public function sort($data_set, $start_index = null, $end_index = null) {
        if (!$data_set || !is_array($data_set)) {
            return $data_set;
        }

        $data_length = count($data_set);

        for ($i= intval($data_length / 2) - 1  ;$i>=0;$i--) {
            $this->adjustHeap($data_set, $i, $data_length);
        }

        for ($i=0; $i<$data_length; $i++) {
            $j = $data_length - 1 - $i;
            if ($j == 0) {
                break;
            }

            $data_set[0] += $data_set[$j];
            $data_set[$j] = $data_set[0] - $data_set[$j];
            $data_set[0] = $data_set[0] - $data_set[$j];


            $this->adjustHeap($data_set, 0, $j);
        }

        return $data_set;
    }

    protected function adjustHeap(&$data_set, $i, $data_length) {

        
        for ($j = $i * 2; $j < $data_length ; ) {

            if ($j + 1 < $data_length) {
                if ($data_set[$j] < $data_set[$j + 1]) {
                    $j++;
                }
            }

            if ($data_set[$j] > $data_set[$i]) {
                $data_set[$i] += $data_set[$j];
                $data_set[$j] = $data_set[$i] - $data_set[$j];
                $data_set[$i] = $data_set[$i] - $data_set[$j];
            } else {
                break;
            }
        }
        
    }
}


$sort_obj  = new HeapSort();
$data_set = $sort_obj->getRandomData(mt_rand(1, 25));

$sort_obj->showData($data_set);

$sort_obj->showData($sort_obj->sort($data_set));



