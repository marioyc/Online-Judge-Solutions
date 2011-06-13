<?php
    include("header.php");
    include("functions.php");
    include("classes/Problem.class.php");
?>

<?php

$vols = array(3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 78, 117, 226, );
$problems = array();

foreach($vols as $vol){
    $body = file_get_contents("http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=$vol");
    
    $count = preg_match_all('/<td><a [^<>]+>([0-9]+)&nbsp;-&nbsp;([^<>]+)<\/a><\/td>[^<>]+<td [^<>]+>[0-9]+<\/td>[^<>]+<td>[^<>]+<div [^<>]+>[^<>]+<div [^<>]+><\/div>[^<>]+<div [^<>]+>[0-9]+.[0-9]+%<\/div>[^<>]+<\/div>[^<>]+<\/td>[^<>]+<td [^<>]+>([0-9]+)<\/td>[^<>]+<td>[^<>]+<div [^<>]+>[^<>]+<div [^<>]+><\/div>[^<>]+<div [^<>]+>([0-9]+).([0-9]+)%<\/div>[^<>]+<\/div>[^<>]+<\/td>/', $body, $match,  PREG_SET_ORDER);
    
    for($i = 0;$i<$count;++$i)
        $problems[] = new Problem((int)$match[$i][1], $match[$i][2], round($match[$i][3]*($match[$i][4]/100+$match[$i][5]/10000)));
}

usort($problems, 'compProblems');

$users = array("17901" => array(), "735" => array(), "4110" => array(), "553" => array(), "29630" => array(), "3099" => array(), "223" => array(), );

foreach($users as $user=>$solved){
    $body = file_get_contents("http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_authorstats&userid=$user");
    
    preg_match('/<div class="componentheading">User Statistics<\/div>[^<>]+<div class="contentheading">[^<>]+<img [^<>]+>[^<>]+\(([^<>]+)\)<\/div>/',$body,$match);
    $users[$user]['name'] = $match[1];
    
    $count = preg_match_all('/<tr class="sectiontableentry[12]">[^<>]+<td [^<>]+><a [^<>]+>([0-9]+)<\/a><\/td>[^<>]+<td [^<>]+>[^<>]+<\/td>[^<>]+/', $body, $match,  PREG_SET_ORDER);
    
    for($i = 0;$i<$count;++$i)
        $users[$user][$match[$i][1]] = TRUE;
}

$total = count($problems);
echo "<h1>$total problemas</h1><br>";
?>

<style type="text/css">
tr.f {color:000000;font-size:medium;text-decoration:none;font-family: arial;}
a.g {color:000000;font-size:medium; text-decoration:none;font-family: arial;}
a.g:link { color:blue; font-family: sans-serif; font-size: medium; font-style: normal; font-variant: normal; text-decoration: none; }
a.g:visited { color: red; font-family: sans-serif; font-size: medium; font-style: normal; font-variant: normal; text-decoration: none; }
</style>


<table border=0 cellspacing=2 cellpadding=5 bgcolor=#000000 >
<tr bgcolor=#ffffff><th width=40>ID</th><th width=380>Title</th><th width=70>Users</th>

<?php
foreach($users as $user=>$solved){
    $name = $users[$user]['name'];
    $solved = count($users[$user]);
    echo "<th style='font-size: 13px'>$name<br>($solved)</th>";
}
?>

</tr>

<?php
for($i = count($problems)-1,$even = 1;$i>=0;--$i){
    $id = $problems[$i]->id;
    $vol = floor($id/100);
    $name = $problems[$i]->name;
    $AC = $problems[$i]->AC;
    
    $bgcolor = ($even==1? "bgcolor=#ddf3ff" : "bgcolor=#ffffff");
    $even = 1-$even;
    
    echo "\n<tr class=\"f\" align=center cellspacing=\"0\">";
    
    echo "<td $bgcolor>".$id."</td>";
    echo "<td $bgcolor align=left><a class=\"g\" href=\"http://uva.onlinejudge.org/external/".$vol."/$id.html\">".$name."</a></td>";
    echo "<td $bgcolor>".$AC."</td>";
    
    
    foreach($users as $user=>$solved){
        $state = "";
        if(array_key_exists($id,$users[$user])) $state = "AC";
        
        echo "<td align=center $bgcolor><font color=red>$state</font></td>";
    }
    
    echo "</tr>";
}
?>

</table>

<?php
    include("footer.php");
?>
