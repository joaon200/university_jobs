<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"> 
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
    <section class="header">
        <nav>
            <a href="index.php"><img src="images/Logo3.png" alt=""></a>
            <div class="nav-links" id="navLinks">
                <i class="fa fa-xmark" onclick="hideMenu()"></i>
                <ul>
                    <li><a href="index.php"><i class="fa-solid fa-house"></i>     HOME</a></li>
                    <li><a href="servidor.php"><i class="fa-solid fa-wheat-awn"></i>     FARM</a></li>
                    <li><a href="Contact.php"><i class="fa-solid fa-comment-sms"></i>     CONTACT</a></li>
                    <li><a href="indexlog.php"><i class="fa-solid fa-user"></i>     LOG IN</a></li>
                </ul>
                
            </div>
            <i class="fa fa-bars" onclick="showMenu()"></i>
        </nav>
<div class="text-box">
    <h1>Smart Farming</h1>
    <p>Welcome to our project Smart Farming <br> <!--br é para mudar de linha--> where you can manage your amazing farm
    </p>
    <a href="login.php" class="hero-btn">Check your Farm</a>
</div>
    </section>
<!-------------------------------------course--------------------------------------->
<section class="course">
    <h1>What we measure</h1>
    <p>We offer a system to monitor your "farm" where you can check and manage:</p>
    <div class="row">
        <div class="course-col">
            <h3>Temperatura</h3>
            <p>Temperature sensor to check how hot it is the soil and inside your farm.</p>
        </div>
        <div class="course-col">
            <h3>Humidade</h3>
            <p>Humidity sensor to make sure your farm's soil has enough moisture.</p>
        </div>
        <div class="course-col">
            <h3>Luminosidade</h3>
            <p>Luminosity sensor to make sure your farm's plants get enough light.</p>
        </div>
    </div>
</section>
<!------------Call to action----------------->
<section class="cta">
    <h1>If you need any help please contact us via phone or email</h1>
    <a href="Contact.php" class="hero-btn">CONTACT US</a>
</section>
<!-- footer -->
<section class="footer">
    <h4>About Us</h4>
    <p>This is the website created by 3 LETI students in Universidade do Minho and here we present to you our work and project: <br> Smart Farming</p>
</section>
 <!-----------------------------JavaScript Toggle Menu------------------------------>
<script>
    var navLinks = document.getElementById("navLinks");
    function showMenu(){
        navLinks.style.right = "0";
    }
    function hideMenu(){
        navLinks.style.right = "-200px";
    }
</script>
</body>
</html>
<!--   <>   37 00 -->
