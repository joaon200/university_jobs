<?php
session_start();
include('conexao.php');
 
if(empty($_POST['usuario']) || empty($_POST['senha'])) {
	header('Location: index.php');
	exit();
}
 
$usuario = mysqli_real_escape_string($conexao, $_POST['usuario']);
$senha = mysqli_real_escape_string($conexao, $_POST['senha']);
 
$query = "select * from user1 where nome = '{$usuario}'";
 
$result = mysqli_query($conexao, $query);
 
$row = mysqli_num_rows($result);
 
if($row == 0) {
    $query1 = "insert into user1(nome,pass) value('$usuario','$senha')";
    $result1 = mysqli_query($conexao, $query1);

    $query = "select * from user1 where nome = '$usuario' and pass = '$senha'";

    $result = mysqli_query($conexao, $query);

    $row = mysqli_num_rows($result);

    $dado = $result->fetch_array();
    $_SESSION['usuario'] = $dado["ID"];
	header('Location: painel.php');
	exit();
} else {
	$_SESSION['existe'] = true;
	header('Location: indexregist.php');
	exit();
}