<?php
session_start();
include('conexao.php');

if(empty($_POST['usuario'])|| empty($_POST['senha'])){
    header('Location: indexlog.php');
    exit();
}

$usuario =mysqli_real_escape_string($conexao,$_POST['usuario']);
$senha =mysqli_real_escape_string($conexao,$_POST['senha']);

$query = "select * from user1 where nome = '$usuario' and pass = '$senha'";

$result = mysqli_query($conexao, $query);

$row = mysqli_num_rows($result);

$dado = $result->fetch_array();

if($row == 1){
    $_SESSION['usuario'] = $dado["ID"];
    header('Location: painel.php');
    exit;
}else{
    $_SESSION['nao_autenticado'] = true;
    header('Location : indexlog.php');
    die;    
}
