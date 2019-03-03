<?php
require_once "BaseList.php";

class ListNode {
    public $value;
    public $next_obj;

    public function __construct($value, $next_obj) {
        $this->value = $value;
        $this->next_obj = $next_obj;
        
    }
}

class SingleList extends BaseList{
    public $head = null;

    public function addNode($value) {
        $node = new ListNode($value, null);

        if ($this->head === null) {
            $this->head = $node;
        } else {
            $node->next_obj = $this->head;
            $this->head = $node;
        }
    }

    //翻转
    public function reverse() {
        if (!$this->head) {
            return;
        }

        $new_head = null;
        $cur_node = $this->head;
        $next_node = null;

        while ($cur_node->next_obj) {

            $next_node = $cur_node->next_obj;
            $cur_node->next_obj = $new_head;
            $new_head = $cur_node;

            $cur_node = $next_node;
        }

        $cur_node->next_obj = $new_head;

        $this->head = $cur_node;

    }


    public function bianli() {

        $temp_node = $this->head;

        $result = [];

        while ($temp_node) {
            $result[] = $temp_node->value;
            $temp_node = $temp_node->next_obj;
        }

        echo implode(",", $result) . "\n";

    }
}

$list_obj  = new SingleList();


$data = $list_obj->getRandomData(mt_rand(1, 25));

foreach ($data as $value) {
    $list_obj->addNode($value);
}

$list_obj->bianli();

$list_obj->reverse();

$list_obj->bianli();


