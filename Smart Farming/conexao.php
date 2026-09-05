<?php
define('HOST','127.0.0.1');
define('USUARIO','root');
define('SENHA','J0@02001');
define('DB','smartfarming');

$conexao = new mysqli(HOST, USUARIO, SENHA, DB) or die ('nao foi possivel conectar');