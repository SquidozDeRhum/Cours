<?php
    $feur = file("./murphy");
    foreach ($feur as $jaaj) {
        $len = strlen($jaaj);
        if ($len <= 60) {
            echo $jaaj;
        }
    }
?>