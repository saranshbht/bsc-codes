<?php
    error_reporting(0);
    $vehicleNumber = '';
    $vehicleNumbererr = '';
    $chassisNumber = '';
    $chassisNumbererr = '';
    $engineNumber = '';
    $engineNumbererr = '';
    $aadharNumber = '';
    $aadharNumbererr = '';
    if (isset($_POST['submit']))
    {
        require_once('Connection.php');
        session_start();
        $vehicleNumber = $_POST['vehicleNumber'];
        $chassisNumber = $_POST['chassisNumber'];
        $engineNumber = $_POST['engineNumber'];
        $aadharNumber = $_POST['aadharNumber'];
        $obj = new Connection();
        $db = $obj -> getNewConnection();
        $sql = "select vehicleNumber, chassisNo, engineNo, aadhar from vehicle where
            vehicleNumber='$vehicleNumber' AND chassisNo='$chassisNumber' AND 
            engineNo='$engineNumber' AND aadhar='$aadharNumber'";
        $res = $db->query($sql);
        if (!$res)
            die($db->error);
        $row = $res->fetch_assoc();
        if ($row['vehicleNumber'] !== $vehicleNumber)
            $vehicleNumbererr = "Invalid Vehicle Number";
        if ($row['chassisNo'] !== $chassisNo)
            $chassisNoerr = "Invalid Chassis Number";
        if ($row['engineNo'] !== $engineNo)
            $engineNoerr = "Invalid Engine Number";
        if ($row['aadharNumber'] !== $aadharNumber)
            $aadharNumbererr = "Invalid Aadhar Number";
        if ($row['vehicleNumber'] === $vehicleNumber AND $row['chassisNo'] === $chassisNumber AND $row['engineNo'] === $engineNumber AND $row['aadhar'] === $aadharNumber)
        {
            $db->close();
            $_SESSION['vehicleNumber'] = $vehicleNumber;
            header("Location: generateRC.php");
        }
        $db->close();
    }
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Generate Duplicate RC</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php require_once('header.php'); ?>
    <br>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Duplicate RC </h1>
    <div class="container"><br>
        <div class="col-lg-6 m-auto d-block">
            <form method="POST" onsubmit="return validation()" class="bg-light">
                <div class="form-group">
					<label for="vehicleNumber" class="font-weight-bold"> Enter Vehicle Number: </label>
					<input type="number" name="vehicleNumber" class="form-control" id="vehicleNumber" value="<?php echo $vehicleNumber;?>">
					<span id="vehicleNumbererr" class="text-danger font-weight-bold"> <?php echo $vehicleNumbererr; ?> </span>
				</div>
                <div class="form-group">
					<label for="chassisNumber" class="font-weight-bold"> Enter Chassis Number: </label>
					<input type="number" name="chassisNumber" class="form-control" id="chassisNumber" value="<?php echo $chassisNumber;?>">
					<span id="chassisNumbererr" class="text-danger font-weight-bold"> <?php echo $chassisNumbererr; ?> </span>
				</div>
                <div class="form-group">
					<label for="engineNumber" class="font-weight-bold"> Enter Engine Number: </label>
					<input type="number" name="engineNumber" class="form-control" id="engineNumber" value="<?php echo $engineNumber;?>">
					<span id="engineNumbererr" class="text-danger font-weight-bold"> <?php echo $engineNumbererr; ?> </span>
				</div>
                <div class="form-group">
					<label for="aadharNumber" class="font-weight-bold"> Enter Aadhar Number: </label>
					<input type="number" name="aadharNumber" class="form-control" id="aadharNumber" value="<?php echo $aadharNumber;?>">
					<span id="aadharNumbererr" class="text-danger font-weight-bold"> <?php echo $aadharNumbererr; ?> </span>
				</div>
                <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
            </form>
            <br>
        </div>
    </div>
    <script type="text/javascript">
        function validation() {
            var vehicleNumber = document.getElementById('vehicleNumber').value;
            if (vehicleNumber == "") {
                document.getElementById('vehicleNumbererr').innerHTML =" ** Please fill the vehicleNumber field";
                return false;
            }
            var chassisNumber = document.getElementById('chassisNumber').value;
            if (chassisNumber == "") {
                document.getElementById('chassisNumbererr').innerHTML =" ** Please fill the chassisNumber field";
                return false;
            }
            var engineNumber = document.getElementById('engineNumber').value;
            if (engineNumber == "") {
                document.getElementById('engineNumbererr').innerHTML =" ** Please fill the engineNumber field";
                return false;
            }
            var aadharNumber = document.getElementById('aadharNumber').value;
            if (aadharNumber == "") {
                document.getElementById('aadharNumbererr').innerHTML =" ** Please fill the aadharNumber field";
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