<?php
    session_start();
?>

<!DOCTYPE html>
<html>
    
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"> 
    <meta charset="utf-8"><!--neto-->
    <meta http-equiv="X-UA-Compatible" content="IE=edge"><!--neto-->
    <title>Smart Farming  </title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="css/bulma.min.css" /><!--neto-->
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
                    <li><a href="index.php"><i class="fa-solid fa-house"></i>     HOME</a></li>
                    <li><a href="servidor.php"><i class="fa-solid fa-wheat-awn"></i>     FARM</a></li>
                    <li><a href="Contact.php"><i class="fa-solid fa-comment-sms"></i>     CONTACT</a></li>
                    <li><a href="login.php"><i class="fa-solid fa-user"></i>     LOG IN</a></li>
                </ul>
                
            </div>
            <i class="fa fa-bars" oncl ick="showMenu()"></i>
        </nav>
    <div class="form-box">
                    <h5 class="title has-text-grey"><i class="fa-solid fa-user"></i> Log In</h5>
                    <?php
                        if(isset($_SESSION['nao_autenticado'])):
                    ?>
                    <div class="notification is-danger">
                      <h3>ERRO: Usuário ou senha inválidos.</h3>
                    </div>
                    <?php
                        unset($_SESSION['nao_autenticado']);
                        endif;
                    ?>
                    <div class="login-method">
                        <form action="login.php" method="POST">
                            <div class="field">
                            <div class="input-box">
                                <input name="usuario" name="text" class="input-field" placeholder="Username" autofocus="">
                            </div>
                            </div>

                            <div class="field">
                            <div class="input-box">
                                <input name="senha" class="input-field" type="password" placeholder="Password" id="myInput">
                                <span class="eye" onclick="myFunction()">
                                    <i id="hide1" class="fa-solid fa-eye"></i>
                                    <i id="hide2" class="fa-solid fa-eye-slash"></i>
                                </span>
                            </div>
                            </div>
                            <div class="submit-btn">
                                <button type="submit" class="login-btn"><i class="fa-solid fa-arrow-right-to-bracket"></i>Log In</button>
                            </div>
                            <div class="signin-btn">
                                <div class="child"><h2>Don't have an account?</h2></div>
                                <div class="child"><a href="indexregist.php" class="child1"><i class="fa-solid fa-user-plus"></i>                         Sign In</a></div>
                            </div>
                           
                        </form>
                    </div>
    </div>
    </section>

<script>
    function myFunction(){
        var x = document.getElementById("myInput");
        var y = document.getElementById("hide1");
        var z = document.getElementById("hide2");

        if(x.type === 'password'){
            x.type = "text";
            y.style.display = "block";
            z.style.display = "none";
        }
        else{
            x.type = "password";
            y.style.display = "none";
            z.style.display = "block";
        }
    }
</script>


</body>

</html>