<?php
    if (isset($_POST['submit']))
    {
        require_once('Connection.php');
        session_start();
        $llno = $_POST['llno'];
        $aadhar = $_POST['aadhar'];
        $obj = new Connection();
        $db = $obj->getNewConnection();
        $sql = "select llno, aadhar from ll where llno=$llno AND aadhar=$aadhar";
        $res = $db->query($sql);
        $row = $res->fetch_assoc();
        $db->close();
        if ($row['llno'] === $llno AND $row['aadhar'] === $aadhar)
        {
            $_SESSION['llno'] = $llno;
            $_SESSION['aadhar'] = $aadhar;
            header("Location: showll.php");
            die();
        }
    }
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Show LL Help</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php require_once('header.php'); ?>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Generate LL </h1>
    <div class="container"><br>
        <div class="col-lg-6 m-auto d-block">
            <form method="POST" onsubmit="return validation()" class="bg-light">
                <div class="form-group">
					<label for="llno" class="font-weight-bold"> Enter LL NO: </label>
					<input type="number" name="llno" class="form-control" id="llno">
					<span id="llnoerr" class="text-danger font-weight-bold"> </span>
                </div>
                <div class="form-group">
					<label for="llno" class="font-weight-bold"> Enter Aadhar NO: </label>
					<input type="number" name="aadhar" class="form-control" id="aadhar">
					<span id="aadharerr" class="text-danger font-weight-bold"> </span>
                </div>
                <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
        </div>
    </div>

    <script type="text/javascript">
        function validation() {
            var llno = document.getElementById('llno').value;
            if (llno == "") {
                document.getElementById('llnoerr').innerHTML =" ** Please fill the llno field";
                return false;
            }
            var aadhar = document.getElementById('aadhar').value;
            if (aadhar == "") {
                document.getElementById('aadharerr').innerHTML =" ** Please fill the aadhar field";
                return false;
            }
            else if(aadhar.toString().length != 10) {
				document.getElementById('aadharerr').innerHTML =" ** Aadhar No should be of 10 digits";
				return false;	
			}
            return true;
        }
    </script>
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