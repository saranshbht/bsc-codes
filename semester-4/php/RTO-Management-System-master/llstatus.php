<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>LL Status</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php require_once('header.php'); ?>
    <br>
    <div class="row">
        <div class="col-lg-6 m-auto d-block">
        <ul class="list-group">
        <li class="list-group-item text-muted" contenteditable="false">LL Status</li>
    <?php
        error_reporting(0);
        session_start();
        require_once('Connection.php');
        $rto = $_SESSION['rto'];
        $aadhar = $_SESSION['aadhar'];
        $obj = new Connection();
        $db = $obj->getNewConnection();
        $sql = "select * from ll where aadhar=$aadhar";
        $res = $db->query($sql);
        if (!$res)
            die($db->error);
        $row = $res->fetch_assoc();
        $status = $row['status'];
        $id = $row['id'];
        $examDate = $row['examDate'];
        $db->close();
        if ($status)
        {
            print("<li class='list-group-item text-right'><span class='pull-left'><strong class=''>Status:</strong></span>Approved</li>");
            session_destroy();
            // die();
        }
        else 
            print("<li class='list-group-item text-right'><span class='pull-left'><strong class=''>Status:</strong></span>Pending</li>
            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Test Date:</strong></span>$examDate</li>
            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>RTO Office:</strong></span>$rto</li>
            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Unique ID:</strong></span>$id</li>");
    ?>
    </ul>
    <?php echo "<br><center><a href='showllHelp.php'><button type='button' class='btn btn-warning'>Show LL</button>  </a> </center>";?>
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


