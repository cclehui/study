<?php

function calcMaxYueNumber(int $a, int $b) {
    if ($a < 0 || $b < 0) {
        return false;
    }

    if ($a < $b) {
        $a = $a + $b;
        $b = $a - $b;
        $a = $a - $b;
    }

    do {

        $c = $a % $b;

        if ($c == 0) {
            return $b;
        }

        $a = $b;
        $b = $c;
    
    } while (true);
}

$a = mt_rand();
$b = mt_rand();

echo "$a, $b, ",  calcMaxYueNumber($a, $b) . "\n";
