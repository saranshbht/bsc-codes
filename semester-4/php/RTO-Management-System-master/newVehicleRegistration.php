<?php
    session_start();
    $tempNo=''; $tempNoerr='';
    if (isset($_POST['submit']))
    {
        require_once('Connection.php');
        $obj = new Connection();
        $db = $obj->getNewConnection();
        $tempNo = $_POST['tempNo'];
        $name = $_POST['name'];
        $aadhar = $_POST['aadhar'];
        $chassisNo = $_POST['chassisNo'];
        $engineNo = $_POST['engineNo'];
        $vehicleClass = $_POST['vehicleClass'];
        $color = $_POST['color'];
        $fuelType = $_POST['fuelType'];
        $seatingType = $_POST['seatingType'];
        $rto = $_POST['rto'];
        $tquery = "select * from vehicle where tempNo=$tempNo";
        $tres = $db->query($tquery);
        if ($tres -> num_rows > 0)
        {
            $tempNoerr = "**Vehicle already registered";
            // die();
        }
        else 
        {
            $sql = "insert into vehicle(tempNo, name, aadhar, chassisNo, engineNo, vehicleClass, color, fuelType, seatingType, rto) 
            values('$tempNo', '$name', '$aadhar', '$chassisNo', '$engineNo', '$vehicleClass', '$color', '$fuelType', '$seatingType', '$rto')";
            $res = $db -> query($sql);
            if ($res)
            {
                $db -> close();
                $_SESSION['tempNo'] = $tempNo;
                $_SESSION['status'] = 0;
                header("Location: vehicleRegResult.php");
                die();
                
            }
            else 
                echo "not in res";
        }
    }
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>New Vehicle Registration</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php require_once('header.php'); ?>
    <br>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> New Vehicle Registration </h1>
    <div class="container"><br>
        <div class="col-lg-6 m-auto d-block">
            <form method="POST" onsubmit="return validation()" class="bg-light">
                <div class="form-group">
					<label for="tempNo" class="font-weight-bold"> Temporary Number: </label>
					<input type="number" name="tempNo" class="form-control" id="tempNo" value="<?php echo $tempNo;?>"> 
					<span id="tempNoerr" name="tempNoerr" class="text-danger font-weight-bold"> <?php echo $tempNoerr;?> </span>
				</div>

                <div class="form-group">
					<label for="name" class="font-weight-bold"> Name: </label>
					<input type="text" name="name" class="form-control" id="name" value="<?php echo $name;?>">
					<span id="nameerr" class="text-danger font-weight-bold"> </span>
				</div>

                <div class="form-group">
					<label for="aadhar" class="font-weight-bold"> Aadhar Number: </label>
					<input type="number" name="aadhar" class="form-control" id="aadhar" value="<?php echo $aadhar;?>">
					<span id="aadharerr" class="text-danger font-weight-bold"> </span>
				</div>

                <div class="form-group">
					<label for="chassisNo" class="font-weight-bold"> Chassis Number: </label>
					<input type="number" name="chassisNo" class="form-control" id="chassisNo" value="<?php echo $chassisNo;?>">
					<span id="chassisNoerr" class="text-danger font-weight-bold"> </span>
				</div>

                <div class="form-group">
					<label for="engineNo" class="font-weight-bold"> Engine Number: </label>
					<input type="number" name="engineNo" class="form-control" id="engineNo" value="<?php echo $engineNo;?>">
					<span id="engineNoerr" class="text-danger font-weight-bold"> </span>
				</div>

                <div class="form-group">
					<label for="vehicleClass" class="font-weight-bold"> Vehicle Class: </label>
					<input type="text" name="vehicleClass" class="form-control" id="vehicleClass" value="<?php echo $vehicleClass;?>">
					<span id="vehicleClasserr" class="text-danger font-weight-bold"> </span>
				</div>

                <div class="form-group">
					<label for="color" class="font-weight-bold"> Color: </label>
					<input type="text" name="color" class="form-control" id="color" value="<?php echo $color;?>">
					<span id="colorerr" class="text-danger font-weight-bold"> </span>
				</div>

                <div class="form-group">
					<label for="fuelType" class="font-weight-bold"> Fuel Type: </label>
					<input type="text" name="fuelType" class="form-control" id="fuelType" value="<?php echo $fuelType;?>">
					<span id="fuelTypeerr" class="text-danger font-weight-bold"> </span>
				</div>

                <div class="form-group">
					<label for="seatingType" class="font-weight-bold"> Seating Type: </label>
					<input type="text" name="seatingType" class="form-control" id="seatingType" value="<?php echo $seatingType;?>">
					<span id="seatingTypeerr" class="text-danger font-weight-bold"> </span>
				</div>

                <div class="form-group">
					<label for="rto" class="font-weight-bold"> RTO: </label>
					<input type="text" name="rto" class="form-control" id="rto" value="<?php echo $rto;?>">
					<span id="rtoerr" class="text-danger font-weight-bold"> </span>
				</div>
                <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
            </form>
            <br>
        </div>
    </div>

    <script type="text/javascript">
        function validation() {
            var tempNo = document.getElementById('tempNo').value;
            var name = document.getElementById('name').value;
            var aadhar = document.getElementById('aadhar').value;
            var chassisNo = document.getElementById('chassisNo').value;
            var engineNo = document.getElementById('engineNo').value;
            var vehicleClass = document.getElementById('vehicleClass').value;
            var color = document.getElementById('color').value;
            var fuelType = document.getElementById('fuelType').value;
            var seatingType = document.getElementById('seatingType').value;
            var rto = document.getElementById('rto').value;

            if (tempNo == "") {
                document.getElementById('tempNoerr').innerHTML =" ** Please fill the tempNo field";
                return false;
            }
            else if(tempNo.toString().length != 10) {
				document.getElementById('tempNoerr').innerHTML =" ** Temp No should be of 10 digits";
				return false;	
			}
            else 
            {
                document.getElementById('tempNoerr').innerHTML ="";
            }
            if (name == "") {
                document.getElementById('nameerr').innerHTML =" ** Please fill the name field";
                return false;
            }
            else if (!(/^[a-zA-z]+$/.test(name)))
            {
                document.getElementById('nameerr').innerHTML =" ** Name cannot contain anything other than characters";
                return false;
            }
            else 
            {
                document.getElementById('nameerr').innerHTML ="";
            }
            if (aadhar == "") {
                document.getElementById('aadharerr').innerHTML =" ** Please fill the aadhar field";
                return false;
            }
            else if(aadhar.toString().length != 10) {
				document.getElementById('aadharerr').innerHTML =" ** Aadhar No should be of 10 digits";
				return false;	
			}
            else 
            {
                document.getElementById('aadharerr').innerHTML ="";
            }
            if (chassisNo == "") {
                document.getElementById('chassisNoerr').innerHTML =" ** Please fill the chassisNo field";
                return false;
            }
            else if(chassisNo.toString().length != 6) {
				document.getElementById('chassisNoerr').innerHTML =" ** Chassis No should be of 6 digits";
				return false;	
			}
            else 
            {
                document.getElementById('chassisNoerr').innerHTML ="";
            }
            if (engineNo == "") {
                document.getElementById('engineNoerr').innerHTML =" ** Please fill the engineNo field";
                return false;
            }
            else if(engineNo.toString().length != 10) {
				document.getElementById('engineNoerr').innerHTML =" ** Engine No should be of 10 digits";
				return false;	
			}
            else 
            {
                document.getElementById('engineNoerr').innerHTML ="";
            }
            if (vehicleClass == "") {
                document.getElementById('vehicleClasserr').innerHTML =" ** Please fill the vehicleClass field";
                return false;
            }
            else 
            {
                document.getElementById('vehicleClasserr').innerHTML ="";
            }
            if (color == "") {
                document.getElementById('colorerr').innerHTML =" ** Please fill the color field";
                return false;
            }
            else 
            {
                document.getElementById('colorerr').innerHTML ="";
            }
            if (fuelType == "") {
                document.getElementById('fuelTypeerr').innerHTML =" ** Please fill the fuelType field";
                return false;
            }
            else 
            {
                document.getElementById('fuelTypeerr').innerHTML ="";
            }
            if (seatingType == "") {
                document.getElementById('seatingTypeerr').innerHTML =" ** Please fill the seatingType field";
                return false;
            }
            else 
            {
                document.getElementById('seatingTypeerr').innerHTML ="";
            }
            if (rto == "") {
                document.getElementById('rtoerr').innerHTML =" ** Please fill the rto field";
                return false;
            }
            else 
            {
                document.getElementById('rtoerr').innerHTML ="";
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