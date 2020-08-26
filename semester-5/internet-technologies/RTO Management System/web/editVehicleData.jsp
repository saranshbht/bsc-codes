<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:set var="aadhar" value="${sessionScope.aadhar}" />
<sql:query dataSource="${con}" var="res" sql="select * from vehicle where aadhar='${aadhar}'" />
<c:if test="${param.submit != null}"> 
    <c:set var="name" value="${param.name}" />
    <c:set var="seating" value="${param.seatingType}" />
    <c:set var="vehicleNumber" value="${param.vehicleNumber}" />
    <c:set var="chassisNo" value="${param.chassisNo}" />
    <c:set var="engineNo" value="${param.engineNo}" />
    <c:set var="vehicleClass" value="${param.vehicleClass}" />
    <c:set var="color" value="${param.color}" />
    <c:set var="status" value="${param.status}" />
    <c:set var="fuelType" value="${param.fuelType}" />
    <c:set var="rto" value="${param.rto}" />
    <c:set var="status" value="${param.status}" />
    <c:set var="validity" value="${param.validity}" />
    <c:set var="issueDate" value="${param.issueDate}" />
    <sql:update dataSource="${con}" var="upd" sql="update vehicle 
        set name='${name}', seatingType='${seatingType}', vehicleNumber=${vehicleNumber}, 
        chassisNo=${chassisNo}, engineNo=${engineNo}, vehicleClass='${vehicleClass}', color='${color}', 
        fuelType='${fuelType}', status=${status}, rto='${rto}' where aadhar=${aadhar}" />
    <c:redirect url="viewVehicleData.jsp" />
</c:if>

<!DOCTYPE html>
<html>
<%@include file="header.jsp" %>
    <br>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Edit Vehicle Data </h1>
    <div class="container"><br>
        <div class="col-lg-6 m-auto d-block">
            <form method="POST" onsubmit="validation(event)" class="bg-light">
                <c:forEach var="row" items="${res.rows}">
                    <div class="form-group">
                        <label for="name" class="font-weight-bold"> Name: </label>
                        <input type="text" name="name" class="form-control" id="name" value="${row.name}">
                        <span id="nameerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="chassisNo" class="font-weight-bold"> Chassis No: </label>
                        <input type="number" name="chassisNo" class="form-control" id="chassisNo" value="${row.chassisNo}">
                        <span id="chassisNoerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="engineNo" class="font-weight-bold"> Engine No: </label>
                        <input type="number" name="engineNo" class="form-control" id="engineNo" value="${row.engineNo}">
                        <span id="engineNoerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="vehicleClass" class="font-weight-bold"> Vehicle Class: </label>
                        <input type="text" name="vehicleClass" class="form-control" id="vehicleClass" value="${row.vehicleClass}">
                        <span id="vehicleClasserr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="color" class="font-weight-bold"> Color: </label>
                        <input type="text" name="color" class="form-control" id="color" value="${row.color}">
                        <span id="colorerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="fuelType" class="font-weight-bold"> Fuel Type: </label>
                        <input type="text" name="fuelType" class="form-control" id="fuelType" value="${row.fuelType}">
                        <span id="fuelTypeerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="seatingType" class="font-weight-bold"> seatingType: </label>
                        <input type="text" name="seatingType" class="form-control" id="seatingType" value="${row.seatingType}">
                        <span id="seatingTypeerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="rto" class="font-weight-bold"> Mobile Number: </label>
                        <input type="text" name="rto" class="form-control" id="rto" value="${row.rto}">
                        <span id="rtoerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="status" class="font-weight-bold"> status(0-Pending 1-Accepted): </label>
                        <input type="number" name="status" class="form-control" id="status" value="${row.status}">
                        <span id="statuserr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="vehicleNumber" class="font-weight-bold"> Vehicle Number </label>
                        <input type="number" name="vehicleNumber" class="form-control" id="vehicleNumber" value="${row.vehicleNumber}">
                        <span id="vehicleNumbererr" class="text-danger font-weight-bold"> </span>
                    </div>
                </c:forEach>
                <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
            </form>
            <br>
        </div>
    </div>
    <script type="text/javascript">
        function validation(e) {
            var name = document.getElementById('name').value;
            if (name == "") {
                document.getElementById('nameerr').innerHTML =" ** Please fill the name field";
                e.preventDefault();
            }
            else if (!(/^[a-zA-z]+$/.test(name)))
            {
                document.getElementById('nameerr').innerHTML =" ** Name cannot contain anything other than characters";
                e.preventDefault();
            }
            var chassisNo = document.getElementById('chassisNo').value;
            if (chassisNo == "") {
                document.getElementById('chassisNoerr').innerHTML =" ** Please fill the chassisNo field";
                e.preventDefault();
            }
            else if(chassisNo.toString().length != 6) {
                document.getElementById('chassisNoerr').innerHTML =" ** Chassis No should be of 10 digits";
                e.preventDefault();
            }
            var engineNo = document.getElementById('engineNo').value;
            if (engineNo == "") {
                document.getElementById('engineNoerr').innerHTML =" ** Please fill the engineNo field";
                e.preventDefault();
            }
            else if(engineNo.toString().length != 10) {
                document.getElementById('engineNoerr').innerHTML =" ** Engine No should be of 10 digits";
                e.preventDefault();
            }
            var vehicleClass = document.getElementById('vehicleClass').value;
            if (vehicleClass == "") {
                document.getElementById('vehicleClasserr').innerHTML =" ** Please fill the vehicleClass field";
                e.preventDefault();
            }
            var color = document.getElementById('color').value;
            if (color == "") {
                document.getElementById('colorerr').innerHTML =" ** Please fill the color field";
                e.preventDefault();
            }
            var fuelType = document.getElementById('fuelType').value;
            if (fuelType == "") {
                document.getElementById('fuelTypeerr').innerHTML =" ** Please fill the fuelType field";
                e.preventDefault();
            }
            var seatingType = document.getElementById('seatingType').value;
            if (seatingType == "") {
                document.getElementById('seatingTypeerr').innerHTML =" ** Please fill the seatingType field";
                e.preventDefault();
            }
            var rto = document.getElementById('rto').value;
            if (rto == "") {
                document.getElementById('rtoerr').innerHTML =" ** Please fill the rto field";
                e.preventDefault();
            }
            var status = document.getElementById('status').value;
            if (status == "") {
                document.getElementById('statuserr').innerHTML =" ** Please fill the status field";
                e.preventDefault();
            }
            else if (!(/^[01]$/.test(status.toString())))
            {
                document.getElementById('statuserr').innerHTML =" ** Status should be either 0 or 1";
                e.preventDefault();
            }
            var vehicleNumber = document.getElementById('vehicleNumber').value;
            if (vehicleNumber == "") {
                document.getElementById('vehicleNumbererr').innerHTML =" ** Please fill the vehicleNumber field";
                e.preventDefault();
            }
            else if(vehicleNumber.toString().length != 10) {
                document.getElementById('vehicleNumbererr').innerHTML =" ** Vehicle No should be of 10 digits";
                e.preventDefault();
            }
        }
    </script>
    <%@include file="footer.jsp" %>
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