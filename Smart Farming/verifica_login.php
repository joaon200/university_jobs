<?php
session_start();
if(!$_SESSION['usuario']){
    header('Location: indexlog.php');
    exit();
}