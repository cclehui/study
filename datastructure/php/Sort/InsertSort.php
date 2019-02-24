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

        for ($j = 1;$j <$data_len; $j++) {
            $cur_index = $j;
            for ($i = $j - 1;$i>=0; $i-- ) {
                if ($data_set[$i] <= $data_set[$cur_index]) {
                    break;
                }

                $data_set[$i] += $data_set[$cur_index];
                $data_set[$cur_index] = $data_set[$i] - $data_set[$cur_index];

                $data_set[$i] = $data_set[$i] - $data_set[$cur_index];

                $cur_index = $i;
            }
        }

        return $data_set;
    }
    
}


$sort_obj  = new InsertSort();
$data_set = $sort_obj->getRandomData(10);

$sort_obj->showData($data_set);

$sort_obj->showData($sort_obj->sort($data_set));



