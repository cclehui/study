<?php
include "./Sort.php";

//namespace Cclehui\Study\Sort


class MergeSort extends Sort {

    public function sort($data_set, $start_index = null, $end_index = null) {
        if (!$data_set || !is_array($data_set)) {
            return $data_set;
        }

        if ($start_index === null || $end_index === null) {
            $start_index = 0;
            $end_index = count($data_set) - 1;
        }

        if ($end_index - $start_index < 1) {
            return [$data_set[$end_index]];
        }


        $middle_index = $start_index + intval(($end_index - $start_index) / 2);

        $data_set_left = $this->sort($data_set, $start_index, $middle_index);
        $data_set_right = $this->sort($data_set, $middle_index + 1, $end_index);

        //merge

        $result = [];
        $left_max_index = $middle_index - $start_index;
        //$left_max_index = count($data_set_left) - 1;
        $right_max_index = $end_index - $middle_index - 1;
        //$right_max_index = count($data_set_right) - 1;

        $i = $j = 0;

        while ($i <= $left_max_index && $j <= $right_max_index) {
            if ($data_set_left[$i] <= $data_set_right[$j]) {
                $result[] = $data_set_left[$i];
                $i++;
            } else {
                $result[] = $data_set_right[$j];
                $j++;
            }
        }
        

        while ($i <= $left_max_index) {
            $result[] = $data_set_left[$i];
            $i++;
        }

        while ($j <= $right_max_index) {
            $result[] = $data_set_right[$j];
            $j++;
        }

        return $result;
    }
    
}


$sort_obj  = new MergeSort();
$data_set = $sort_obj->getRandomData(mt_rand(1, 25));

$sort_obj->showData($data_set);

$sort_obj->showData($sort_obj->sort($data_set));



