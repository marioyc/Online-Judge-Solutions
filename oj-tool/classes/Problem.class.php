<?php

class Problem {
    public $id,$name,$AC;

    public function __construct($id, $name, $AC) {
        $args = func_get_args();
        $this->id = $id;
        $this->name = $name;
        $this->AC = $AC;
    }
}

function compProblems($a, $b){
  if($a->AC == $b->AC) return 0;
  return ($a->AC < $b->AC)? -1 : 1;
}

?>
