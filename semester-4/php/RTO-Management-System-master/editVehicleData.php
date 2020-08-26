
<?php
    session_start();
    require_once('Connection.php');
    $aadhar = $_SESSION['aadhar'];
    // echo $aadhar;
    // die();
    $obj = new Connection();
    $db = $obj->getNewConnection();
    $sql = "select * from vehicle where aadhar=$aadhar";
    $res = $db->query($sql);
    $row = $res->fetch_assoc();
    if (isset($_POST['submit']))
    {
        $name = $_POST['name'];$seatingType = $_POST['seatingType'];
        $vehicleNumber = $_POST['vehicleNumber'];$chassisNo = $_POST['chassisNo'];
        $engineNo = $_POST['engineNo'];$vehicleClass = $_POST['vehicleClass'];
        $color = $_POST['color'];$fuelType = $_POST['fuelType'];
        $status = $_POST['status'];$rto = $_POST['rto'];
        $q = "update vehicle 
        set name='$name', seatingType='$seatingType', vehicleNumber=$vehicleNumber, 
        chassisNo=$chassisNo, engineNo=$engineNo, vehicleClass='$vehicleClass', color='$color', 
        fuelType='$fuelType', status=$status, rto='$rto' where aadhar=$aadhar"; 
        $res1 = $db->query($q);
        if (!$res1)
            die($db->error);
        $db->close();
        header("Location: viewVehicleData.php");
        die();
        $db->close();
    }
?>

<html>
<?php require_once('header.php'); ?>
    <br>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Edit Vehicle Data </h1>
    <div class="container"><br>
        <div class="col-lg-6 m-auto d-block">
            <form method="POST" onsubmit="return validation()" class="bg-light">
                <div class="form-group">
					<label for="name" class="font-weight-bold"> Name: </label>
					<input type="text" name="name" class="form-control" id="name" value="<?php echo $row['name'] ?>">
					<span id="nameerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="chassisNo" class="font-weight-bold"> Chassis No: </label>
					<input type="number" name="chassisNo" class="form-control" id="chassisNo" value="<?php echo $row['chassisNo'] ?>">
					<span id="chassisNoerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="engineNo" class="font-weight-bold"> Engine No: </label>
					<input type="text" name="engineNo" class="form-control" id="engineNo" value="<?php echo $row['engineNo'] ?>">
					<span id="engineNoerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="vehicleClass" class="font-weight-bold"> Vehicle Class: </label>
					<input type="text" name="vehicleClass" class="form-control" id="vehicleClass" value="<?php echo $row['vehicleClass'] ?>">
					<span id="vehicleClasserr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="color" class="font-weight-bold"> Color: </label>
					<input type="text" name="color" class="form-control" id="color" value="<?php echo $row['color'] ?>">
					<span id="colorerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="fuelType" class="font-weight-bold"> Fuel Type: </label>
					<input type="text" name="fuelType" class="form-control" id="fuelType" value="<?php echo $row['fuelType'] ?>">
					<span id="fuelTypeerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="seatingType" class="font-weight-bold"> seatingType: </label>
					<input type="text" name="seatingType" class="form-control" id="seatingType" value="<?php echo $row['seatingType'] ?>">
					<span id="seatingTypeerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="rto" class="font-weight-bold"> Mobile Number: </label>
					<input type="text" name="rto" class="form-control" id="rto" value="<?php echo $row['rto'] ?>">
					<span id="rtoerr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="status" class="font-weight-bold"> status(0-Pending 1-Accepted): </label>
					<input type="number" name="status" class="form-control" id="status" value="<?php echo $row['status'] ?>">
					<span id="statuserr" class="text-danger font-weight-bold"> </span>
				</div>
                <div class="form-group">
					<label for="vehicleNumber" class="font-weight-bold"> Vehicle Number </label>
					<input type="number" name="vehicleNumber" class="form-control" id="vehicleNumber" value="<?php echo $row['vehicleNumber'] ?>">
					<span id="vehicleNumbererr" class="text-danger font-weight-bold"> </span>
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
            var chassisNo = document.getElementById('chassisNo').value;
            if (chassisNo == "") {
                document.getElementById('chassisNoerr').innerHTML =" ** Please fill the chassisNo field";
                return false;
            }
            var engineNo = document.getElementById('engineNo').value;
            if (engineNo == "") {
                document.getElementById('engineNoerr').innerHTML =" ** Please fill the engineNo field";
                return false;
            }
            var vehicleClass = document.getElementById('vehicleClass').value;
            if (vehicleClass == "") {
                document.getElementById('vehicleClasserr').innerHTML =" ** Please fill the vehicleClass field";
                return false;
            }
            var color = document.getElementById('color').value;
            if (color == "") {
                document.getElementById('colorerr').innerHTML =" ** Please fill the color field";
                return false;
            }
            var fuelType = document.getElementById('fuelType').value;
            if (fuelType == "") {
                document.getElementById('fuelTypeerr').innerHTML =" ** Please fill the fuelType field";
                return false;
            }
            var seatingType = document.getElementById('seatingType').value;
            if (seatingType == "") {
                document.getElementById('seatingTypeerr').innerHTML =" ** Please fill the seatingType field";
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
            }
            var vehicleNumber = document.getElementById('vehicleNumber').value;
            if (vehicleNumber == "") {
                document.getElementById('vehicleNumbererr').innerHTML =" ** Please fill the vehicleNumber field";
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
</html>