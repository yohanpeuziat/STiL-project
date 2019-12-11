<?php
$myfile = fopen("../../data/light_state.txt", "r") or die("Unable to open file!");
echo fread($myfile,filesize("../../data/light_state.txt"));
fclose($myfile);
?>