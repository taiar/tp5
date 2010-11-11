<?php

$nCamadas = 5;
$capCamInicial = 30000;
$totalReq = 100000;
$counterzao = 1;
$politicas = array("lru", "mru", "lfu", "fifo");

echo $nCamadas . " ";

for($i = 0; $i < $nCamadas; $i += 1)
  echo rand(10, 10000) . " " . rand(10, 1000) . " " . $politicas[rand(0,3)] . " ";

echo $capCamInicial . "\n";

echo $totalReq . "\n";

for($i = 0; $i < $totalReq; $i += 1)
{
  echo rand(1,$capCamInicial) . " ";
  if(rand(0,1) == 1)
    $counterzao += 1;
  echo $counterzao . "\n";

}

?>
