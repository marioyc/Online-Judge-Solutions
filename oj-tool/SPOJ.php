<?php
    include("header.php");
    include("functions.php");
    include("classes/Problem.class.php");
?>

<?php

$problems = array();

for($lim = 0;$lim<50;$lim += 50){
    $body = file_get_contents("http://www.spoj.pl/problems/classical/sort=-6,start=$lim");
    
    $count = preg_match_all('/<tr class="problemrow">\s<td>[0-9]+<\/td>\s<td [^<>]+>&nbsp;\s<a [^<>]+>&nbsp;<b>(.*)<\/b><\/a><\/td>\s<td><a [^<>]+>\s(.*)<\/a><\/td>\s<td><a [^<>]+>([0-9]+)<\/a><\/td>\s<td><a [^<>]+>[0-9]+\.[0-9]+<\/a><\/td>\s<\/tr>/', $body, $match,  PREG_SET_ORDER);
    
    if($count==0) break;
    
    for($i = 0;$i<$count;++$i)
        $problems[] = new Problem($match[$i][2], $match[$i][1], (int)$match[$i][3]);
}

$users = array( "marioyc" => array(), "trulo_17" => array(), "hamlet_fiis" => array(), "roypalacios" => array(), "a20012251" => array(),);

foreach($users as $user=>$solved){
    $body = file_get_contents("http://www.spoj.pl/users/$user/");
    
    preg_match('/<tr class="lightrow">\s<td><b>([0-9]+)<\/b>\<\/td>/',$body,$match);
    $AC = (int)$match[1];
    
    $count = preg_match_all('/<a [^<>]+>([A-Z0-9]+)<\/a>/', $body, $match,  PREG_SET_ORDER);
    
    for($i = 0;$i<$AC;++$i)
        $users[$user][$match[$i][1]] = TRUE;
}

echo "\n<table width=100% border=1 bordercolor=lightgrey bordercolordark=gray cellpadding=5 style='border-collapse: collapse'><thead><tr>";
echo "<th><font color=blue>ID</font></th>";
echo "<th><font color=green>Title</font></th>";
echo "<th><font color=red>AC</font></th>";

foreach($users as $user=>$solved) echo "<th>$user</th>";
echo "</tr></thead>";

$NUM_PROB = count($problems);

for($i = 0;i<$NUM_PROB;++$i){
    $id = $problems[$i]->id;
    $name = $problems[$i]->name;
    $AC = $problems[$i]->AC;
    
    if($even==1) echo "\n<tr align=center bgcolor=#F0F0F0>";
    else echo "\n<tr align=center>";
    $even = 1-$even;
    
    echo "<td>".$id."</td>";
    echo "<td><a href=\"http://www.spoj.pl/problems/$id/\">".$name."</a></td>";
    echo "<td>".$AC."</td>";
    
    foreach($users as $user=>$solved){
        $state = "";
        if(array_key_exists($id,$users[$user])) $state = "AC";
        
        echo "<td align=center><font color=red>$state</font></td>";
    }
    
    echo "</tr>";
}
echo "\n</table>";

?>

<?php
    include("footer.php");
?>
