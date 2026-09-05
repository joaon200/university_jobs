<?php
include('verifica_login.php');
$id = $_SESSION['usuario'];
?>

<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"> 
    <meta charset="utf8">
    <title>Smart Farming  </title>
    <link rel="stylesheet" href="style.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@100;200;300;400;600;700&display=swap" rel="stylesheet">
    <!--link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/@fortawesome/fontawesome-free@5.15.4/css/fontawesome.min.css" integrity="sha384-jLKHWM3JRmfMU0A5x5AkjWkw/EYfGUAGagvnfryNV3F9VqM98XiIH7VBGVoxVSc7" crossorigin="anonymous"-->
    <!--link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/@fortawesome/fontawesome-free@5.15.4/css/fontawesome.min.css"-->
    <script src="https://kit.fontawesome.com/52eee75f26.js" crossorigin="anonymous"></script>



</head>
<body>
<section class="farm-header">
        <nav>
            <a href="index.php"><img src="images/Logo3.png" alt=""></a>
            <div class="nav-links" id="navLinks">
                <i class="fa fa-xmark" onclick="hideMenu()"></i>
                <ul>
                    <li><a href="painel.php"><i class="fa-solid fa-wheat-awn"></i>     My Farm</a></li>
                    <li><a href="addplaca.php"><i class="fa-solid fa-microchip"></i>     Add Board</a></li>
                    <li><a href="logout.php"><i class="fa-solid fa-user-slash"></i>     LOG OUT</a></li>
                </ul>

            </div>
            <i class="fa fa-bars" onclick="showMenu()"></i>
        </nav>

        <h1>My Farm</h1>

    </section>
    <?php
        $host = "127.0.0.1";
        $usuario = "root";
        $senha = "J0@02001";
        $bd = "smartfarming";

        $mysqli = new mysqLi($host, $usuario, $senha, $bd);

        if($mysqli->connect_errno)
            echo "falha na conexao: (".$mysqli->connect_errno.") " .$mysqli->connect_error;
             
    ?>


    <table class="content-table" >
        <thead>
        <tr>
            <th>Humidade</th>
            <th>Luz</th>
            <th>Temperatura</th>
            <th>Data/Hora</th>
            <th>ID</th>   
        </tr>
        </thead>
        <?php
            $consulta = "SELECT a.* FROM amostra a, sensores s where a.ID_PLACA = s.ID_P and s.ID_USER = '$id'";
            $con = $mysqli->query($consulta) or die ($mysqli->error);  
            while($dado = $con->fetch_array()){        
        ?>
        <tbody> 
        <tr>
            <td><?php echo $dado["humidade"]; ?></td>
            <td><?php echo $dado["luz"]; ?></td>
            <td><?php echo $dado["temp"]; ?></td>
            <td><?php 
                $dado1 = str_replace("-",":",$dado["datahora"]);
                $dado2 = str_replace("/"," ",$dado1);
                echo date("d/m/Y - H:i:s", strtotime($dado2)); 
            ?></td>
            <td><?php echo $dado["ID_PLACA"]; ?></td>
        </tr>
        </tbody>
        <?php
            }          
        ?>
    </table>

    <section class="hero is-success is-fullheight">
        <div class="hero-body">
                    <?php
                    if(isset($_SESSION['nao_existe'])):
                    ?>
                    <div class="notification is-danger">
                      <p>ERRO: placa invalida.</p>
                    </div>
                    <?php
                    endif;
                    unset($_SESSION['nao_existe']);
                    ?>
                <div class="placa-box">
                    <div class="placa-col">
                        <form action="startstopbuton.php" method="POST">
                            <div class="field-placa">
                                <div class="control">
                                    <input name="id" name="text" class="input is-large" placeholder="Placa" autofocus="">
                                </div>
                            </div>
                            <section id="container"class="servbtn">
                                <button type="submit" class="blue-btn">START/STOP</button>
                            </section>
                        </form>
                    </div>
                </div>
        </div>
    </section>


<!--<section id="container" class="servbtn">
        <a href="btnclick.php" class="blue-btn">start</a>
        <a href="btnclick1.php" class="blue-btn">stop</a>-->

</body>
</html>