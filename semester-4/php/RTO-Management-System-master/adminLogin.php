<?php
    error_reporting(E_PARSE);
    session_start();
    if ($_SESSION['loggedin'])
    {
        header("Location: adminPanel.php");
    }
    if (isset($_POST['submit']))
    {
        require_once('Connection.php');
        $username = $_POST['username'];
        $pass = $_POST['password'];
        $obj = new Connection();
        $db = $obj->getNewConnection();
        $sql = "select * from admin where username='$username' AND password='$pass'";
        $res = $db->query($sql);
        if (!$res)
            die($db->error);
        $row = $res->fetch_assoc();
        $db->close();
        if ($row['username'] === $username AND $pass === $row['password'])
        {
            $_SESSION['loggedin'] = 1;
            header("Location: adminPanel.php");
            die();
        }
        else 
        {
            print("Invalid credentials");
        }
    }
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Admin Login</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php require_once('header.php'); ?>
    <br>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Admin Login </h1>
    <div class="container"><br>
        <div class="col-lg-6 m-auto d-block">
            <form method="POST" onsubmit="return validation()" class="bg-light">
                <div class="form-group">
					<label for="username" class="font-weight-bold"> Username:: </label>
					<input type="text" name="username" class="form-control" id="username">
					<span id="usernameerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="password" class="font-weight-bold"> Password: </label>
					<input type="password" name="password" class="form-control" id="password">
					<span id="passworderr" class="text-danger font-weight-bold"> </span>
				</div>
                <center><input type="submit" name="submit" value="LOGIN" class="btn btn-success"><center>
            </form>
            <br>
        </div>
    </div>
    <script type="text/javascript">
        function validation() {
            var username = document.getElementById('username').value;
            var password = document.getElementById('password').value;
            if (username == "") {
                document.getElementById('usernameerr').innerHTML =" ** Please fill the username field";
                return false;
            }
            if (password == "") {
                document.getElementById('passworderr').innerHTML =" ** Please fill the password field";
                return false;
            }
        }
    </script>
    <h1></h1>
    <?php require_once('footer.php'); ?>
    <!-- ##### All Javascript Script ##### -->
    <!-- jQuery-2.2.4 js -->
    <script src="js/jquery/jquery-2.2.4.min.js"></script>
    <!-- Popper js -->
    <script src="js/bootstrap/popper.min.js"></script>
    <!-- Bootstrap js -->
    <script src="js/bootstrap/bootstrap.min.js"></script>
    <!-- All Plugins js -->
    <script src="js/plugins/plugins.js"></script>
    <!-- Active js -->
    <script src="js/active.js"></script>
</body>
</html>