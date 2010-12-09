<?php
    include("header.php");
    include("functions.php");
    include("classes/Problem.class.php");
?>

<?php

$problems = array();

for($vol = 1;$vol<=5;++$vol){
    $body = file_get_contents("http://acm.sgu.ru/problemset.php?contest=0&volume=$vol");

    $count = preg_match_all('/<tr class=[^<>]+><td><a [^<>]+>([0-9]{3})<\/a><\/td><td>&nbsp;([^<>]+)<\/td><td><a [^<>]+>([0-9]+)/', $body, $match,  PREG_SET_ORDER);
    // <\/a><\/td><td> <tr>
    
    for($i = 0;$i<$count;++$i)
        $problems[] = new Problem((int)$match[$i][1], $match[$i][2], (int)$match[$i][3]);
}

usort($problems, 'compProblems');

$users = array("019327" => array(), "041309" => array(), "037363" => array(), "019731" => array(), "038323" => array(), "018947" => array(), "017401" => array(), );

foreach($users as $user=>$solved){
    $body = file_get_contents("http://acm.sgu.ru/teaminfo.php?id=$user");
    
    preg_match('/<tr><td>Name<\/td><td>:&#160;([^<>]+)<\/td><\/tr>/',$body,$match);
    $users[$user]['name'] = $match[1];
    
    $count = preg_match_all('/<font color=#[0-9]{6}>([0-9]{3})&#160<\/font>/', $body, $match,  PREG_SET_ORDER);
    
    for($i = 0;$i<$count;++$i)
        $users[$user][$match[$i][1]] = TRUE;
}

$total = count($problems);
echo "<h1>$total problemas</h1><br>";

echo "\n<table cellpadding=5 style='border-collapse: collapse; font-size: 11pt' align=center><thead>";
echo "<tr bgcolor=#6587b9>";
echo "<th width=50>ID</th>";
echo "<th width=320>Title</th>";
echo "<th width=70>AC</th>";

foreach($users as $user=>$solved){
    $solved = count($users[$user]);
    echo "<th width=150>".$users[$user]['name']."<br>(".$solved.")</th>";
}
echo "</tr></thead><tbody>"; 

for($i = count($problems)-1,$even = 1;$i>=0;--$i){
    $id = $problems[$i]->id;
    $name = $problems[$i]->name;
    $AC = $problems[$i]->AC;
    
    if($even==1) echo "\n<tr align=center bgcolor=#F3F8FF>";
    else echo "\n<tr align=center bgcolor=#E0E5EF>";
    $even = 1-$even;
    
    echo "<td><font color=#224488>".$id."</font></td>";
    echo "<td><a href=\"http://acm.sgu.ru/problem.php?contest=0&problem=$id\">".$name."</a></td>";
    echo "<td><font color=#224488>".$AC."</font></td>";
    
    foreach($users as $user=>$solved){
        $state = "";
        if(array_key_exists($id,$users[$user])) $state = "AC";
        
        echo "<td align=center><font color=red>$state</font></td>";
        //<IMG SRC="images/ok.gif" ALT="Ok">
    }
    
    echo "</tr>";
}
echo "\n</tbody></table>";

?>

<?php
    include("footer.php");
?>
