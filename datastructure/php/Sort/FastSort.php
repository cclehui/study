<?php
include "./Sort.php";

//namespace Cclehui\Study\Sort


class FastSort extends Sort {

    public function sort(&$data_set, $start_index = null, $end_index = null) {
        if (!$data_set || !is_array($data_set)) {
            return $data_set;
        }

        if ($start_index === null && $end_index === null) {
            $start_index = 0;
            $end_index = count($data_set) - 1;
        } else {
            $start_index = intval($start_index);
            $end_index = intval($end_index);
        }

        if (($end_index - $start_index) < 1) {
            return ;
        }

        $base_value = $data_set[$start_index];
        $temp_index = $start_index;
        $i = $start_index + 1;

        for ($j = $end_index;$j>= $i;$j--) {

            if ($data_set[$j] < $base_value) {
                $data_set[$temp_index] = $data_set[$j];

                $temp_index = $j;

                for(;$i<$j;$i++) {
                    if ($data_set[$i] > $base_value) {
                        $data_set[$temp_index] = $data_set[$i];
                        $temp_index = $i;
                        break;
                    }
                }
            }
        }

        $data_set[$temp_index] = $base_value;

        $this->sort($data_set, $start_index, $temp_index - 1);
        $this->sort($data_set, $temp_index + 1, $end_index);

        return $data_set;
    }
    
}


$sort_obj  = new FastSort();
$data_set = $sort_obj->getRandomData(mt_rand(1, 25));

$sort_obj->showData($data_set);

$sort_obj->showData($sort_obj->sort($data_set));



