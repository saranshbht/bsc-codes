<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Vehicle Registration Result</title>
</head>
<body>
<?php require_once('header.php'); ?>
<?php
    error_reporting(0);
    session_start();
    require_once('Connection.php');
    $tempNo = $_SESSION['tempNo'];
    $status = $_SESSION['status'];
    if ($status)
        $displayStatus = "Accepted";
    else
        $displayStatus = "Pending";
    print("
        <h1>Vehicle Registration Status</h1> <br>
        <h2>Status : $displayStatus <br></h2>
    ");
    if ($status)
    {
        $obj = new Connection();
        $db = $obj->getNewConnection();
        $q = "select vehicleNumber from vehicle where tempNo='$tempNo'";
        $result = $db->query($q);
        $row = $result->fetch_array();
        $vehicleNo = $row[0];
        print("<h2>Permanent Vehicle Number: $vehicleNo</h2></br>");
        $db -> close();
    }
    session_destroy();
?>
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