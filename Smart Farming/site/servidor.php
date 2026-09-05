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
                    <li><a href="index.php"><i class="fa-solid fa-house"></i>     HOME</a></li>
                    <li><a href="servidor.php"><i class="fa-solid fa-wheat-awn"></i>    FARM</a></li>
                    <li><a href="Contact.php"><i class="fa-solid fa-comment-sms"></i>      CONTACT</a></li>
                    <li><a href="indexlog.php"><i class="fa-solid fa-user"></i>     LOG IN</a></li>
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
        else
            $consulta = "SELECT * FROM amostra";
            $con = $mysqli->query($consulta) or die ($mysqli->error);     
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
<style>
.blue-btn{
    display: inline-block;
    text-decoration: none;
    color: #009879;
    border: 3px solid #009879;
    padding: 12px 34px;
    font-size: 13px;
    background: transparent;
    position: relative;
    cursor: pointer;
    font-weight: bold;
    margin-top: 35px;
    align-items: center;
 }
 #container{
    text-align: center;
}
.blue-btn:hover{
    color: #fff;
    border: 3px solid #009879;
    background: #009879;
    transition: 0.5s;
}
    </style>
</section>

</body>
</html>
