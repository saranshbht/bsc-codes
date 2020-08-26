<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Generate RC</title>
</head>
<body>
    <?php require_once('header.php'); ?>
    <br>
    <div class="row">
        <div class="col-lg-6 m-auto d-block">
        <ul class="list-group">
            <?php
                error_reporting(0);
                session_start();
                require_once('Connection.php');
                $vehicleNumber = $_SESSION['vehicleNumber'];
                $obj = new Connection();
                $db = $obj->getNewConnection();
                $sql = "select * from vehicle where vehicleNumber='$vehicleNumber'";
                $res = $db->query($sql);
                $row = $res->fetch_assoc();
                $name = $row['name'];
                $aadhar = $row['aadhar'];
                $chassisNo = $row['chassisNo'];
                $engineNo = $row['engineNo'];
                $vehicleClass = $row['vehicleClass'];
                $color = $row['color'];
                $fuelType = $row['fuelType'];
                $seatingType = $row['seatingType'];
                $rto = $row['rto'];
                $status =  $row['status'];
                if ($status)
                print("<li class='list-group-item text-muted' contenteditable='false'>Duplicate RC</li>

                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Vehicle Number:</strong></span>$vehicleNumber</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Name:</strong></span>$name</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Aadhar Number:</strong></span>$aadhar</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Chassis Number:</strong></span>$chassisNo</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Engine Number:</strong></span>$engineNo</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Vehicle Class:</strong></span>$vehicleClass</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Color:</strong></span>$color</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Fuel Type:</strong></span>$fuelType</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Seating Type:</strong></span>$seatingType</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>RTO:</strong></span>$rto</li>
                ");
                else 
                print("
                <h1>Vehicle Registration Status</h1> <br>
                <h2>Status : Pending <br></h2>
            ");
                session_destroy();
                $db->close();
            ?>
            </ul>
        </div>
    </div>
    <br>
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