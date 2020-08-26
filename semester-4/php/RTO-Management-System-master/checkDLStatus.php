<?php
    $aadhar = '';
    $aadharerr = '';
    if (isset($_POST['submit']))
    {
        require_once('Connection.php');
        session_start();
        $aadhar = $_POST['aadhar'];
        $obj = new Connection();
        $db = $obj->getNewConnection();
        $sql = "select aadhar, rto from dl where aadhar=$aadhar";
        $res = $db->query($sql);
        $row = $res->fetch_array();
        $db-> close();
        if ($row[0] != $aadhar)
            $aadharerr = "Invalid Aadhar Number";
        if ($row[0] == $aadhar)
        {
            $_SESSION['aadhar'] = $aadhar;
            $_SESSION['rto'] = $row[1];
            header("Location: dlstatus.php");
            die();
        }
    }

?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Check LL Status</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php require_once('header.php'); ?>
    <br>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Check DL Status </h1>
    <div class="container"><br>
        <div class="col-lg-6 m-auto d-block">
            <form method="POST" onsubmit="return validation()" class="bg-light">
                <div class="form-group">
					<label for="aadhar" class="font-weight-bold"> Enter Aadhar Number: </label>
					<input type="number" name="aadhar" class="form-control" id="aadhar" value="<?php echo $aadhar; ?>">
					<span id="aadharerr" class="text-danger font-weight-bold"> <?php echo $aadharerr; ?> </span>
				</div>
                <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
            </form>
            <br>
        </div>
    </div>
    <script type="text/javascript">
        function validation() {
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