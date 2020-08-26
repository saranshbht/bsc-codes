<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<c:if test="${param.submit != null}">
    <c:set var="vehicleNumber" value="${param.vehicleNumber}" />
    <c:set var="aadharNumber" value="${param.aadharNumber}" />
    <c:set var="chassisNumber" value="${param.chassisNumber}" />
    <c:set var="engineNumber" value="${param.engineNumber}" />
    <sql:query dataSource="${con}" var="res" sql="select vehicleNumber, chassisNo, engineNo, aadhar from vehicle where
            vehicleNumber='${vehicleNumber}' AND chassisNo='${chassisNumber}' AND 
            engineNo='${engineNumber}' AND aadhar='${aadharNumber}'" />
    <c:choose>
        <c:when test="${res.getRowCount() > 0}">
            <c:set var="vehicleNumber" value="${vehicleNumber}" scope="session" />
            <c:redirect url="generateRC.jsp" />
        </c:when>
        <c:otherwise>
            <script>alert("No such record")</script>
        </c:otherwise>
    </c:choose>
</c:if>
            
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Generate Duplicate RC</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %>
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Duplicate RC </h1>
        <div class="container"><br>
            <div class="col-lg-6 m-auto d-block">
                <form method="POST" onsubmit="validation(event)" class="bg-light">
                    <div class="form-group">
                        <label for="vehicleNumber" class="font-weight-bold"> Enter Vehicle Number: </label>
                        <input type="number" name="vehicleNumber" class="form-control" id="vehicleNumber" value="${vehicleNumber}">
                        <span id="vehicleNumbererr" class="text-danger font-weight-bold"> ${vehicleNumbererr} </span>
                    </div>
                    <div class="form-group">
                        <label for="chassisNumber" class="font-weight-bold"> Enter Chassis Number: </label>
                        <input type="number" name="chassisNumber" class="form-control" id="chassisNumber" value="${chassisNumber}">
                        <span id="chassisNumbererr" class="text-danger font-weight-bold"> ${chassisNumbererr}</span>
                    </div>
                    <div class="form-group">
                        <label for="engineNumber" class="font-weight-bold"> Enter Engine Number: </label>
                        <input type="number" name="engineNumber" class="form-control" id="engineNumber" value="${engineNumber}">
                        <span id="engineNumbererr" class="text-danger font-weight-bold"> ${engineNumbererr} </span>
                    </div>
                    <div class="form-group">
                        <label for="aadharNumber" class="font-weight-bold"> Enter Aadhar Number: </label>
                        <input type="number" name="aadharNumber" class="form-control" id="aadharNumber" value="${aadharNumber}">
                        <span id="aadharNumbererr" class="text-danger font-weight-bold"> ${aadharNumbererr}</span>
                    </div>
                    <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
                </form>
                <br>
            </div>
        </div>
        <script type="text/javascript">
            function validation(e) {
                var vehicleNumber = document.getElementById('vehicleNumber').value;
                if (vehicleNumber == "") {
                    document.getElementById('vehicleNumbererr').innerHTML =" ** Please fill the vehicleNumber field";
                    e.preventDefault();
                }
                else if(vehicleNumber.toString().length != 10) {
                    document.getElementById('vehicleNumbererr').innerHTML =" ** Vehicle No should be of 10 digits";
                    e.preventDefault();	
                }
                var chassisNumber = document.getElementById('chassisNumber').value;
                if (chassisNumber == "") {
                    document.getElementById('chassisNumbererr').innerHTML =" ** Please fill the chassisNumber field";
                    e.preventDefault();
                }
                else if(chassisNumber.toString().length != 6) {
                    document.getElementById('chassisNumbererr').innerHTML =" ** Chassis No should be of 10 digits";
                    e.preventDefault();	
                }
                var engineNumber = document.getElementById('engineNumber').value;
                if (engineNumber == "") {
                    document.getElementById('engineNumbererr').innerHTML =" ** Please fill the engineNumber field";
                    e.preventDefault();
                }
                else if(engineNumber.toString().length != 10) {
                    document.getElementById('engineNumbererr').innerHTML =" ** Engine No should be of 10 digits";
                    e.preventDefault();	
                }
                var aadharNumber = document.getElementById('aadharNumber').value;
                if (aadharNumber == "") {
                    document.getElementById('aadharNumbererr').innerHTML =" ** Please fill the aadharNumber field";
                    e.preventDefault();
                }
                else if(aadharNumber.toString().length != 10) {
                    document.getElementById('aadharNumbererr').innerHTML =" ** Aadhar No should be of 10 digits";
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