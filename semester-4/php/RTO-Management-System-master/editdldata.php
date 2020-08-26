
<?php
    session_start();
    require_once('Connection.php');
    $aadhar = $_SESSION['aadhar'];
    // echo $aadhar;
    // die();
    $obj = new Connection();
    $db = $obj->getNewConnection();
    $sql = "select * from dl where aadhar=$aadhar";
    $res = $db->query($sql);
    $row = $res->fetch_assoc();
    if (isset($_POST['submit']))
    {
        $name = $_POST['name'];$dlno = $_POST['dlno'];
        $fatherName = $_POST['fatherName'];$dob = $_POST['dob'];
        $bloodGroup = $_POST['bloodGroup'];$address = $_POST['address'];
        $gender = $_POST['gender'];$mobileNumber = $_POST['mobileNumber'];
        $email = $_POST['email'];$rto = $_POST['rto'];
        $status = $_POST['status'];$validity = $_POST['validity'];
        $issueDate = $_POST['issueDate'];
        $q = "update dl 
        set name='$name', dlno=$dlno, fatherName='$fatherName', 
        dob='$dob', bloodGroup='$bloodGroup', address='$address', gender='$gender', 
        mobileNumber=$mobileNumber, email='$email', rto='$rto', status=$status, validity='$validity', issueDate='$issueDate' where aadhar=$aadhar"; 
        $res1 = $db->query($q);
        if (!$res1)
            die($db->error);
        $db->close();
        header("Location: viewdlData.php");
        die();
        $db->close();
    }
?>

<html>
    <?php require_once('header.php'); ?>
    <br>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Edit DL Data </h1>
    <div class="container"><br>
        <div class="col-lg-6 m-auto d-block">
            <form method="POST" onsubmit="return validation()" class="bg-light">
                <div class="form-group">
					<label for="name" class="font-weight-bold"> Name: </label>
					<input type="text" name="name" class="form-control" id="name" value="<?php echo $row['name'] ?>">
					<span id="nameerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="dlno" class="font-weight-bold"> DL No: </label>
					<input type="number" name="dlno" class="form-control" id="dlno" value="<?php echo $row['dlno'] ?>">
					<span id="dlnoerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="fatherName" class="font-weight-bold"> Father's Name: </label>
					<input type="text" name="fatherName" class="form-control" id="fatherName" value="<?php echo $row['fatherName'] ?>">
					<span id="fatherNameerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="dob" class="font-weight-bold"> DL No: </label>
					<input type="text" name="dob" class="form-control" id="dob" value="<?php echo $row['dob'] ?>">
					<span id="doberr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="bloodGroup" class="font-weight-bold"> Blood Group: </label>
					<input type="text" name="bloodGroup" class="form-control" id="bloodGroup" value="<?php echo $row['bloodGroup'] ?>">
					<span id="bloodGrouperr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="address" class="font-weight-bold"> Address: </label>
					<input type="text" name="address" class="form-control" id="address" value="<?php echo $row['address'] ?>">
					<span id="addresserr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="gender" class="font-weight-bold"> Gender: </label>
					<input type="text" name="gender" class="form-control" id="gender" value="<?php echo $row['gender'] ?>">
					<span id="gendererr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="mobileNumber" class="font-weight-bold"> Mobile Number: </label>
					<input type="number" name="mobileNumber" class="form-control" id="mobileNumber" value="<?php echo $row['mobileNumber'] ?>">
					<span id="mobileNumbererr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="email" class="font-weight-bold"> Email: </label>
					<input type="email" name="email" class="form-control" id="email" value="<?php echo $row['email'] ?>">
					<span id="emailerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="rto" class="font-weight-bold"> RTO: </label>
					<input type="text" name="rto" class="form-control" id="rto" value="<?php echo $row['rto'] ?>">
					<span id="rtoerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="status" class="font-weight-bold"> Status (0-pending, 1- approved): </label>
					<input type="number" name="status" class="form-control" id="status" value="<?php echo $row['status'] ?>">
					<span id="statuserr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="validity" class="font-weight-bold"> Validity </label>
					<input type="date" name="validity" class="form-control" id="validity" value="<?php echo $row['validity'] ?>">
					<span id="validityerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="issueDate" class="font-weight-bold"> Issue Date </label>
					<input type="date" name="issueDate" class="form-control" id="issueDate" value="<?php echo $row['issueDate'] ?>">
					<span id="issueDateerr" class="text-danger font-weight-bold"> </span>
				</div>
                <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
            </form>
            <br>
        </div>
    </div>
    <script type="text/javascript">
        function validation() {
            var name = document.getElementById('name').value;
            if (name == "") {
                document.getElementById('nameerr').innerHTML =" ** Please fill the name field";
                return false;
            }
            var dlno = document.getElementById('dlno').value;
            if (dlno == "") {
                document.getElementById('dlnoerr').innerHTML =" ** Please fill the dlno field";
                return false;
            }
            var fatherName = document.getElementById('fatherName').value;
            if (fatherName == "") {
                document.getElementById('fatherNameerr').innerHTML =" ** Please fill the fatherName field";
                return false;
            }
            var dob = document.getElementById('dob').value;
            if (dob == "") {
                document.getElementById('doberr').innerHTML =" ** Please fill the dob field";
                return false;
            }
            var bloodGroup = document.getElementById('bloodGroup').value;
            if (bloodGroup == "") {
                document.getElementById('bloodGrouperr').innerHTML =" ** Please fill the bloodGroup field";
                return false;
            }
            var address = document.getElementById('address').value;
            if (address == "") {
                document.getElementById('addresserr').innerHTML =" ** Please fill the address field";
                return false;
            }
            var gender = document.getElementById('gender').value;
            if (gender == "") {
                document.getElementById('gendererr').innerHTML =" ** Please fill the gender field";
                return false;
            }
            var mobileNumber = document.getElementById('mobileNumber').value;
            if (mobileNumber == "") {
                document.getElementById('mobileNumbererr').innerHTML =" ** Please fill the mobileNumber field";
                return false;
            }
            var email = document.getElementById('email').value;
            if (email == "") {
                document.getElementById('emailerr').innerHTML =" ** Please fill the email field";
                return false;
            }
            var rto = document.getElementById('rto').value;
            if (rto == "") {
                document.getElementById('rtoerr').innerHTML =" ** Please fill the rto field";
                return false;
            }
            var status = document.getElementById('status').value;
            if (status == "") {
                document.getElementById('statuserr').innerHTML =" ** Please fill the status field";
                return false;
            }
            var validity = document.getElementById('validity').value;
            if (validity == "") {
                document.getElementById('validityerr').innerHTML =" ** Please fill the validity field";
                return false;
            }
            var issueDate = document.getElementById('issueDate').value;
            if (issueDate == "") {
                document.getElementById('issueDateerr').innerHTML =" ** Please fill the issueDate field";
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
</html>