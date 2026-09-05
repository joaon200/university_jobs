<?php
    session_start();
?>

<!DOCTYPE html>
<html>
    
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Smart Farming</title>
    <link rel="stylesheet" href="css/bulma.min.css" />
    <link rel="stylesheet" href="style.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@100;200;300;400;600;700&display=swap" rel="stylesheet">
    <!--link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/@fortawesome/fontawesome-free@5.15.4/css/fontawesome.min.css" integrity="sha384-jLKHWM3JRmfMU0A5x5AkjWkw/EYfGUAGagvnfryNV3F9VqM98XiIH7VBGVoxVSc7" crossorigin="anonymous"-->
    <!--link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/@fortawesome/fontawesome-free@5.15.4/css/fontawesome.min.css"-->
    <script src="https://kit.fontawesome.com/52eee75f26.js" crossorigin="anonymous"></script>
</head>

<body>
    <section class="header">
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
            <i class="fa fa-bars" oncl ick="showMenu()"></i>
        </nav>
        <div class="form-box">
                    <h6 class="title has-text-grey">Resgister new chip</h6>
                    <?php
                        if(isset($_SESSION['nao_autenticado'])):
                    ?>
                    <div class="notification is-danger">
                      <p>ERRO: placa invalida.</p>
                    </div>
                    <?php
                        unset($_SESSION['nao_autenticado']);
                        endif;
                    ?>
                    <div class="add-method">
                        <form action="addplacasql.php" method="POST">
                            <div class="field">
                                <div class="control">
                                    <input name="placa" name="text" class="input-field" placeholder="Board ID" autofocus="">
                                </div>
                            </div>
                            <div class="submit-btn">
                            <button type="submit" class="register-btn"><i class="fa-solid fa-plus"></i>REGISTER</button>
                            </div>
                        </form>
                    </div>
        </div>
    </section>
</body>

</html>