<?php
    $tempNo = '';
    $tempNoerr = '';
    if (isset($_POST['submit']))
    {
        session_start();
        require_once('Connection.php');
        $tempNo = $_POST['tempNo'];
        $obj = new Connection();
        $db = $obj->getNewConnection();
        $sql = "select status from vehicle where tempNo='$tempNo'";
        $res = $db->query($sql);
        if (!$res)
        {
            die($db->error);
        }
        if ($res->num_rows == 0)
        {
            $tempNoerr = "Invalid Temp Number";
        }
        else if ($res)
        {
            $row = $res->fetch_array();
            $db->close();
            $_SESSION['tempNo'] = $tempNo;
            $_SESSION['status'] = $row[0];
            header("Location: vehicleRegResult.php");
            die();
        }
    }

?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Check Vehicle Registration Status</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php require_once('header.php'); ?>
    <br>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Check Vehicle Registration Status </h1>
    <div class="container"><br>
        <div class="col-lg-6 m-auto d-block">
            <form method="POST" onsubmit="return validation()" class="bg-light">
                <div class="form-group">
					<label for="tempNo" class="font-weight-bold"> Enter Temp Number: </label>
					<input type="number" name="tempNo" class="form-control" id="tempNo" value="<?php echo $tempNo;?>">
					<span id="tempNoerr" class="text-danger font-weight-bold"> <?php echo $tempNoerr;?> </span>
				</div>
                <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
            </form>
            <br>
        </div>
    </div>
    <script type="text/javascript">
        function validation() {
            var tempNo = document.getElementById('tempNo').value;
            if (tempNo == "") {
                document.getElementById('tempNoerr').innerHTML =" ** Please fill the tempNo field";
                return false;
            }
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