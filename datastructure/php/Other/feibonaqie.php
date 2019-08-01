<?php

function data($n) {

    $t1 = 0; $t2 = 1;

    for ($i=1;$i<=$n;$i++) {

        echo $t2 . "\n";

        $cur = $t1 + $t2;

        $t1 = $t2;
        $t2 = $cur;
    }
}


data(5);
