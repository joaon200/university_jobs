<?php
session_start();

if(empty($_POST['id'])) {
	header('Location: painel.php');
	exit();
}

$id1 = $_SESSION['usuario'];

$host = "127.0.0.1";
$usuario = "root";
$senha = "J0@02001";
$bd = "smartfarming";

$mysqli = new mysqLi($host, $usuario, $senha, $bd);

$consulta1 = "SELECT ID_P FROM sensores where ID_USER = '$id1'";
$con1 = $mysqli->query($consulta1) or die ($mysqli->error); 

$id = $_POST['id'];
$val = false;

$ids = array();
while($dado1 = $con1->fetch_array()){   
    if($dado1["ID_P"]==$id){
        $val = true;
    }
}  


if($val) {
	$_SESSION['id'] = $id;
	header('Location: btnclick.php');
	die;
} else {
	$_SESSION['nao_existe'] = true;
	header('Location: painel.php');
	die;
}
?>
