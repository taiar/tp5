<?php

$n = 500;
$cont = 1;
echo $n . "\n";
for($i = 0; $i < $n; $i += 1)
{
  echo mt_rand(0,49) . " ";
  if(mt_rand()&1) $cont += 1;
  echo $cont . "\n";
}

?>
