<?php
        session_start();
        $idplaca = $_SESSION['id'];
        $host    = "192.168.1.56";
        $port    = 8090;
        $message = "ST ".$idplaca;
        echo "Message To server :".$message;
        // create socket
        $socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("nao pode criar o socket\n");
        // connect to server
        $result = socket_connect($socket, $host, $port) or die("nao consegue conectar ao server\n");  
        // send string to server
        socket_write($socket, $message, strlen($message)) or die("nao consegue enviar dados para o server\n");
        // close socket
        socket_close($socket);
        header('Location: painel.php');
        exit();
?>
