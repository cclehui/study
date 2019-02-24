<?php
include "./Sort.php";

//namespace Cclehui\Study\Sort


class InsertSort extends Sort {

    public function sort($data_set) {
        if (!$data_set || !is_array($data_set)) {
            return $data_set;
        }

        $i = $j = 0;

        $data_len = count($data_set);

        $bubble_max_index = $data_len - 1;

        for ($i = $data_len - 1;$i >= 0 ; ) {
            $switch_count = 0;
            $max_switch_index = 1;
            for ($j = 1;$j <= $i; $j++) {
                if ($data_set[$j - 1] > $data_set[$j]) {
                    $data_set[$j -1] += $data_set[$j];
                    $data_set[$j] = $data_set[$j - 1] - $data_set[$j];
                    $data_set[$j - 1] = $data_set[$j - 1] - $data_set[$j];

                    $switch_count++;
                    $max_switch_index = $j;

                    //$bubble_max_index = $temp_index;
                }
            }

            $i = $max_switch_index - 1;

            if ($max_switch_index < 2) {
                break;
            }
        }

        return $data_set;
    }
    
}


$sort_obj  = new InsertSort();
$data_set = $sort_obj->getRandomData(mt_rand(1, 30));

$sort_obj->showData($data_set);

$sort_obj->showData($sort_obj->sort($data_set));



