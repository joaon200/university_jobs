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
    <section class="sub-header">
        <nav>
            <a href="index.php"><img src="images/Logo3.png" alt=""></a>
            <div class="nav-links" id="navLinks">
                <i class="fa fa-xmark" onclick="hideMenu()"></i>
                <ul>
                    <li><a href="index.php"><i class="fa-solid fa-house"></i>     HOME</a></li>
                    <li><a href="servidor.php"><i class="fa-solid fa-wheat-awn"></i>     FARM</a></li>
                    <li><a href="Contact.php"><i class="fa-solid fa-comment-sms"></i>       CONTACT</a></li>
                    <li><a href="login.php"><i class="fa-solid fa-user"></i>     LOG IN</a></li>
                </ul>

            </div>
            <i class="fa fa-bars" onclick="showMenu()"></i>
        </nav>

        <h1>Contact Us</h1>

    </section>

    <!--Contact us-->
<section class="location">
<iframe src="https://www.google.com/maps/embed?pb=!1m14!1m8!1m3!1d11961.884177512591!2d-8.2934876!3d41.4506978!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x0%3A0x3048fe13f1faee11!2sUniversidade%20do%20Minho!5e0!3m2!1sen!2spt!4v1652966974771!5m2!1sen!2spt" width="600" height="450" style="border:0;" allowfullscreen="" loading="lazy" referrerpolicy="no-referrer-when-downgrade"></iframe>
</section>
<section class="contact-us">
    <div class="row">
        <div class="contact-col">
            <div>
                <i class="fa-solid fa-home"></i>
                <span>
                    <h5>University of Minho</h5>
                    <p>Azurém campus</p>
                </span>
            </div>
            <div>
                <i class="fa-solid fa-phone"></i>
                <span>
                    <h5>+351 123456789</h5>
                    <p>Monday to Friday, 9AM to 6PM</p>
                </span>
            </div>
            <div>
                <i class="fa-solid fa-envelope"></i>
                <span>
                    <h5>exemploemail@gmail.com</h5>
                    <p>24/7 with due delay</p>
                </span>
            </div>
        </div>
        <div class="contact-col">
            <form action="form-handler.php" method="post">
                <input type="text" name="name"  placeholder="Enter your name" required>
                <input type="email" name="email" placeholder="Enter email adress" required>
                <input type="text" name="subject" placeholder="Enter your subject" required>
                <textarea rows="8" name="message" placeholder="Message"required></textarea>
                <button type="submit" class="red-btn" >Send Message</button>
            </form>

        </div>
        <div class="contact-col">
            <form action="dbh.inc.php" method="post">
                

            </form>
        </div>




    </div>
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
