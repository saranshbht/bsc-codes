<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:if test="${param.submit != null}">
    <c:set var="name" value="${param.name}" />
    <c:set var="tempNo" value="${param.tempNo}" />
    <c:set var="aadhar" value="${param.aadhar}" />
    <c:set var="chassisNo" value="${param.chassisNo}" />
    <c:set var="engineNo" value="${param.engineNo}" />
    <c:set var="vehicleClass" value="${param.vehicleClass}" />
    <c:set var="color" value="${param.color}" />
    <c:set var="fuelType" value="${param.fuelType}" />
    <c:set var="seatingType" value="${param.seatingType}" />
    <c:set var="rto" value="${param.rto}" />
    <sql:query dataSource="${con}" var="res" sql="select * from vehicle where tempNo='${tempNo}'" />
    <c:choose>
        <c:when test="${res.getRowCount() > 0}">
            <c:set var="tempNoerr" value="**Vehicle already registered" />
        </c:when>
        <c:otherwise>
            <sql:update dataSource="${con}" var="res" sql="insert into vehicle(tempNo, name, aadhar, chassisNo, engineNo, vehicleClass, color, fuelType, seatingType, rto) 
            values('${tempNo}', '${name}', '${aadhar}', '${chassisNo}', '${engineNo}', '${vehicleClass}', '${color}', '${fuelType}', '${seatingType}', '${rto}')" />
            <c:if test="${res > 0}">
                <c:set var="tempNo" value="${tempNo}" scope="session" />
                <c:set var="status" value="0" scope="session" />
                <c:redirect url="vehicleRegResult.jsp" />
            </c:if>
        </c:otherwise>
    </c:choose>
</c:if>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>New Vehicle Registration</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %> 
        <br>
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> New Vehicle Registration </h1>
        <div class="container"><br>
            <div class="col-lg-6 m-auto d-block">
                <form method="POST" onsubmit="validation(event)" class="bg-light">
                    <div class="form-group">
                        <label for="tempNo" class="font-weight-bold"> Temporary Number: </label>
                        <input type="number" name="tempNo" class="form-control" id="tempNo" value="${tempNo}"> 
                        <span id="tempNoerr" name="tempNoerr" class="text-danger font-weight-bold"> ${tempNoerr} </span>
                    </div>

                    <div class="form-group">
                        <label for="name" class="font-weight-bold"> Name: </label>
                        <input type="text" name="name" class="form-control" id="name" value="${name}">
                        <span id="nameerr" class="text-danger font-weight-bold"> </span>
                    </div>

                    <div class="form-group">
                        <label for="aadhar" class="font-weight-bold"> Aadhar Number: </label>
                        <input type="number" name="aadhar" class="form-control" id="aadhar" value="${aadhar}">
                        <span id="aadharerr" class="text-danger font-weight-bold"> </span>
                    </div>

                    <div class="form-group">
                        <label for="chassisNo" class="font-weight-bold"> Chassis Number: </label>
                        <input type="number" name="chassisNo" class="form-control" id="chassisNo" value="${chassisNo}">
                        <span id="chassisNoerr" class="text-danger font-weight-bold"> </span>
                    </div>

                    <div class="form-group">
                        <label for="engineNo" class="font-weight-bold"> Engine Number: </label>
                        <input type="number" name="engineNo" class="form-control" id="engineNo" value="${engineNo}">
                        <span id="engineNoerr" class="text-danger font-weight-bold"> </span>
                    </div>

                    <div class="form-group">
                        <label for="vehicleClass" class="font-weight-bold"> Vehicle Class: </label>
                        <input type="text" name="vehicleClass" class="form-control" id="vehicleClass" value="${vehicleClass}">
                        <span id="vehicleClasserr" class="text-danger font-weight-bold"> </span>
                    </div>

                    <div class="form-group">
                        <label for="color" class="font-weight-bold"> Color: </label>
                        <input type="text" name="color" class="form-control" id="color" value="${color}">
                        <span id="colorerr" class="text-danger font-weight-bold"> </span>
                    </div>

                    <div class="form-group">
                            <label for="fuelType" class="font-weight-bold"> Fuel Type: </label>
                            <input type="text" name="fuelType" class="form-control" id="fuelType" value="${fuelType}">
                            <span id="fuelTypeerr" class="text-danger font-weight-bold"> </span>
                    </div>

                    <div class="form-group">
                        <label for="seatingType" class="font-weight-bold"> Seating Type: </label>
                        <input type="text" name="seatingType" class="form-control" id="seatingType" value="${seatingType}">
                        <span id="seatingTypeerr" class="text-danger font-weight-bold"> </span>
                    </div>

                    <div class="form-group">
                        <label for="rto" class="font-weight-bold"> RTO: </label>
                        <input type="text" name="rto" class="form-control" id="rto" value="${rto}">
                        <span id="rtoerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
                </form>
                <br>
            </div>
        </div>

        <script type="text/javascript">
            function validation(e) {
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
                    e.preventDefault();
                }
                else if(tempNo.toString().length != 10) {
                    document.getElementById('tempNoerr').innerHTML =" ** Temp No should be of 10 digits";
                    e.preventDefault();
                }
                if (name == "") {
                    document.getElementById('nameerr').innerHTML =" ** Please fill the name field";
                    e.preventDefault();
                }
                else if (!(/^[a-zA-z]+$/.test(name)))
                {
                    document.getElementById('nameerr').innerHTML =" ** Name cannot contain anything other than characters";
                    e.preventDefault();
                }
                if (aadhar == "") {
                    document.getElementById('aadharerr').innerHTML =" ** Please fill the aadhar field";
                }
                else if(aadhar.toString().length != 10) {
                    document.getElementById('aadharerr').innerHTML =" ** Aadhar No should be of 10 digits";
                    e.preventDefault();
                }
                if (chassisNo == "") {
                    document.getElementById('chassisNoerr').innerHTML =" ** Please fill the chassisNo field";
                    e.preventDefault();
                }
                else if(chassisNo.toString().length != 6) {
                    document.getElementById('chassisNoerr').innerHTML =" ** Chassis No should be of 6 digits";
                    e.preventDefault();
                }
                if (engineNo == "") {
                    document.getElementById('engineNoerr').innerHTML =" ** Please fill the engineNo field";
                    e.preventDefault();
                }
                else if(engineNo.toString().length != 10) {
                    document.getElementById('engineNoerr').innerHTML =" ** Engine No should be of 10 digits";
                    e.preventDefault();
                }
                if (vehicleClass == "") {
                    document.getElementById('vehicleClasserr').innerHTML =" ** Please fill the vehicleClass field";
                    e.preventDefault();
                }
                if (color == "") {
                    document.getElementById('colorerr').innerHTML =" ** Please fill the color field";
                    e.preventDefault();
                }
                if (fuelType == "") {
                    document.getElementById('fuelTypeerr').innerHTML =" ** Please fill the fuelType field";
                    e.preventDefault();
                }
                if (seatingType == "") {
                    document.getElementById('seatingTypeerr').innerHTML =" ** Please fill the seatingType field";
                    e.preventDefault();
                }
                if (rto == "") {
                    document.getElementById('rtoerr').innerHTML =" ** Please fill the rto field";
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
    </body>
</html>