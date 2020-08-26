

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Confirm New DL</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php require_once('header.php'); ?>
    <div class="row">
        <div class="col-lg-6 m-auto d-block">
        <ul class="list-group">
    <?php
    session_start();
    require_once('Connection.php');
    $llno = $_SESSION['llno'];
    $aadhar = $_SESSION['aadhar'];
    $obj = new Connection();
    $db = $obj->getNewConnection();
    $sql = "select * from ll where llno=$llno AND aadhar=$aadhar";
    $res = $db->query($sql);
    $row = $res->fetch_assoc();
    $name = $row['name'];
    $fatherName = $row['fatherName'];
    $dob = $row['dob'];
    $bloodGroup = $row['bloodGroup'];
    $address = $row['address'];
    $aadhar = $row['aadhar'];
    $validity = $row['validity'];
    $issueDate = $row['issueDate'];
    $gender = $row['gender'];
    $mobileno = $row['mobileNumber'];
    $email = $row['email'];
    $rto = $row['rto'];
    print("<li class='list-group-item text-muted' contenteditable='false'>LL</li>

                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>LL Number:</strong></span>$llno</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Name:</strong></span>$name</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Aadhar Number:</strong></span>$aadhar</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Father's Name:</strong></span>$fatherName</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>DOB:</strong></span>$dob</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Blood Group:</strong></span>$bloodGroup</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Address:</strong></span>$address</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Issue Date:</strong></span>$issueDate</li>
                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Validity:</strong></span>$validity</li>
                ");
    if (isset($_POST['confirm']))
    {
        
        // die();
        // header("Location: checkDLStatus.php");
        echo "1";
        $Date = date("Y-m-d");
        $examDate = date('Y-m-d', strtotime($Date . ' + 15 days'));
        $q = "insert into dl(name, fatherName, dob, bloodGroup, address, aadhar, gender, mobileNumber, email, rto, examDate) 
        values('$name', '$fatherName', '$dob', '$bloodGroup', '$address', $aadhar, '$gender', $mobileno, '$email', '$rto', '$examDate')";
        $r = $db->query($q);
        echo "2";
        // $res1 = $db->query("update dl set status=0 where aadhar=$aadhar");
        $_SESSION['aadhar'] = $aadhar;
        $_SESSION['rto'] = $rto;
        header("Location: dlstatus.php");
        // die();
        if (!$r)
            $db->error;
        
        $db->close();
        echo "1";
        
        echo "1";
    }
    
    // print("DL NO: $llno <br> Name: $name <br> Father's Name: $fatherName <br>
    //     DOB: $dob <br> Blood Group: $bloodGroup <br> Address: $address <br>
    //     Aadhar Number: $aadhar <br> Issue Date: $issueDate <br> Validity: $validity <br>");
    
?>
</ul>
</div>
</div>
    <form method="post">
    <br><center><input class ="btn btn-success" type="submit" value="Confirm Details" name="confirm"></center><br>
    </form>
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