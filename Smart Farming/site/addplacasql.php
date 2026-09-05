<?php
session_start();
$id = $_SESSION['usuario'];
include('conexao.php');

if(empty($_POST['placa'])){
    header('Location: addplaca.php');
    exit();
}

$placa =mysqli_real_escape_string($conexao,$_POST['placa']);


$query = "select * from sensores where ID_P = '$placa'";

$result = mysqli_query($conexao, $query);

$row = mysqli_num_rows($result);

if($row == 0 ){
    $query1 = "insert into sensores values ('$placa','$id')";
    $result1 = mysqli_query($conexao, $query1);
    header('Location: painel.php');
    exit();
}else{
    $_SESSION['nao_disponivel'] = true;
    header('Location : addplaca.php');
    exit();
}
