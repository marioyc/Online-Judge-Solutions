<?php

function getJudgesNames(){
    $ret = array();
    $query = "SELECT * FROM judge";
    $res = mysql_query($query);
    
    while($oj = mysql_fetch_array($res)){
        $ret[] = $oj['short_name'];
    }
    
    return $ret;
}

function getPositions($T, $P){
    $ret = array();
    $n = strlen($P);
    $L = strlen($T);
    $k = 0;
    
    for($i = 0;$i<$L;++$i){
        if($P[$k]!=$T[$i]) $k = 0;
        if($P[$k]==$T[$i]) ++$k;
        
        if($k==$n){
            $ret[] = $i-$n+1;
            $k = 0;
        }
    }
    
    return $ret;
}

function getTableEnd($T, $start){
    $P = '</table>';
    $n = strlen($P);
    $L = strlen($T);
    $k = 0;
    
    for($i = $start;$i<$L;++$i){
        if($P[$k]!=$T[$i]) $k = 0;
        if($P[$k]==$T[$i]) ++$k;
        
        if($k==$n) return $i-$n+1;
    }
    
    return -1;
}

function explodeX($delimiters,$string){
    $return_array = array($string); // The array to return
    $d_count = 0;
    
    while (isset($delimiters[$d_count])){ // Loop to loop through all delimiters
        $new_return_array = array();
        
        foreach($return_array as $el_to_split){ // Explode all returned elements by the next delimiter
            $put_in_new_return_array = explode($delimiters[$d_count],$el_to_split);
            
            foreach($put_in_new_return_array as $substr){ // Put all the exploded elements in array to return
                $new_return_array[] = $substr;
            }
        }
        
        $return_array = $new_return_array; // Replace the previous return array by the next version
        $d_count++;
    }
    
    return $return_array; // Return the exploded elements
}

?>
