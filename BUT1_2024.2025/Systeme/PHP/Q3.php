<?php
    $feur = file("./murphy");
    $jd = 0;
    
    foreach ($feur as $jaaj) {
        $juuj = explode(" ", $jaaj);
        $jd = count($juuj);
        echo $jd . "\n";
    }
?>