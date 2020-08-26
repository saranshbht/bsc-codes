<%@page import="java.text.SimpleDateFormat"%>
<%@page import="java.util.Date"%>
<%@page import="java.util.Calendar"%>
<%!  
    String addDays(Date d, int days) throws Exception{
        Calendar c = Calendar.getInstance();
        c.setTime(d);
        c.add(Calendar.DATE, days);  // number of days to add
        return new SimpleDateFormat("yyyy-MM-dd").format(c.getTime());
    }
%>

<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:if test="${param.submit != null}">
    <c:set var="name" value="${param.name}" />
    <c:set var="fatherName" value="${param.fatherName}" />
    <c:set var="dob" value="${param.dob}" />
    <c:set var="bloodGroup" value="${param.bloodGroup}" />
    <c:set var="address" value="${param.address}" />
    <c:set var="aadhar" value="${param.aadhar}" />
    <c:set var="gender" value="${param.gender}" />
    <c:set var="mobileNumber" value="${param.mobileNumber}" />
    <c:set var="email" value="${param.email}" />
    <c:set var="rto" value="${param.rto}" />
    <c:set var="examDate" value="<%=addDays(new Date(), 15)%>" />
    <sql:query dataSource="${con}" var="res" sql="select * from ll where aadhar='${aadhar}'" />
    <c:choose>
        <c:when test="${res.getRowCount() > 0}">
            <c:set var="aadharerr" value="Aadhar Number already registered" />
        </c:when>
        <c:otherwise>
            <sql:update dataSource="${con}" var="res" sql="insert into ll(name, fatherName, dob, bloodGroup, address, aadhar, gender, mobileNumber, email, rto, status, examDate) values('${name}', '${fatherName}', '${dob}', '${bloodGroup}', '${address}', ${aadhar}, '${gender}', ${mobileNumber}, '${email}', '${rto}', 0, '${examDate}')" />
            <c:if test="${res > 0}">
               <c:set var="aadhar" value="${aadhar}" scope="session" />
                <c:set var="rto" value="${rto}" scope="session" />
                <c:redirect url="llstatus.jsp" /> 
            </c:if>
        </c:otherwise>
    </c:choose>
</c:if>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Apply for New Learner License</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %>
        <br>
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> New LL Registration </h1>
        <div class="container"><br>
            <div class="col-lg-6 m-auto d-block">
                <form method="POST" onsubmit="validation(event)" class="bg-light">
                    <div class="form-group">
                        <label for="name" class="font-weight-bold"> Enter Name: </label>
                        <input type="text" name="name" class="form-control" id="name" value="${name}">
                        <span id="nameerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="fatherName" class="font-weight-bold"> Enter Father's Name: </label>
                        <input type="text" name="fatherName" class="form-control" id="fatherName" value="${fatherName}">
                        <span id="fatherNameerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="dob" class="font-weight-bold"> Enter DOB: </label>
                        <input type="date" name="dob" class="form-control" id="dob" value="${dob}">
                        <span id="doberr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="bloodGroup" class="font-weight-bold"> Enter Blood Group: </label>
                        <input type="text" name="bloodGroup" class="form-control" id="bloodGroup" value="${bloodGroup}">
                        <span id="bloodGrouperr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="address" class="font-weight-bold"> Enter Address: </label>
                        <input type="text" name="address" class="form-control" id="address" value="${email}">
                        <span id="addresserr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="aadhar" class="font-weight-bold"> Enter Aadhar Number: </label>
                        <input type="text" name="aadhar" class="form-control" id="aadhar" value="${aadhar}">
                        <span id="aadharerr" class="text-danger font-weight-bold"> ${aadharerr} </span>
                    </div>
                    <div class="form-group">
                        <label for="gender" class="font-weight-bold"> Enter Gender: </label>
                        <input type="text" name="gender" class="form-control" id="gender" value="${gender}">
                        <span id="gendererr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="mobileNumber" class="font-weight-bold"> Enter Mobile Number: </label>
                        <input type="number" name="mobileNumber" class="form-control" id="mobileNumber" value="${mobileNumber}">
                        <span id="mobileNumbererr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="email" class="font-weight-bold"> Enter Email ID: </label>
                        <input type="email" name="email" class="form-control" id="email" value="${email}">
                        <span id="emailerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="rto" class="font-weight-bold"> Enter RTO Office: </label>
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
                var name = document.getElementById('name').value;
                var fatherName = document.getElementById('fatherName').value;
                var dob = document.getElementById('dob').value;
                var bloodGroup = document.getElementById('bloodGroup').value;
                var address = document.getElementById('address').value;
                var aadhar = document.getElementById('aadhar').value;
                var gender = document.getElementById('gender').value;
                var mobileNumber = document.getElementById('mobileNumber').value;
                var email = document.getElementById('email').value;
                var rto = document.getElementById('rto').value;
                if (name == "") {
                    document.getElementById('nameerr').innerHTML =" ** Please fill the name field";
                    e.preventDefault();
                }
                else if (!(/^[a-zA-z]+$/.test(name)))
                {
                    document.getElementById('nameerr').innerHTML =" ** Name cannot contain anything other than characters";
                    e.preventDefault();
                }
                if (fatherName == "") {
                    document.getElementById('fatherNameerr').innerHTML =" ** Please fill the fatherName field";
                    e.preventDefault();
                }
                else if (!(/^[a-zA-z]+$/.test(fatherName)))
                {
                    document.getElementById('nameerr').innerHTML =" ** Father Name cannot contain anything other than characters";
                    e.preventDefault();
                }
                if (dob == "") {
                    document.getElementById('doberr').innerHTML =" ** Please fill the dob field";
                    e.preventDefault();
                }
                if (bloodGroup == "") {
                    document.getElementById('bloodGrouperr').innerHTML =" ** Please fill the bloodGroup field";
                    e.preventDefault();
                }
                else if(bloodGroup.toString().length > 3) {
                    document.getElementById('bloodGrouperr').innerHTML =" ** Blood Group should be of maximum 3 characters";
                    e.preventDefault();	
                }
                if (address == "") {
                    document.getElementById('addresserr').innerHTML =" ** Please fill the address field";
                    e.preventDefault();
                }
                if (aadhar == "") {
                    document.getElementById('aadharerr').innerHTML =" ** Please fill the aadhar field";
                    e.preventDefault();
                }
                else if(aadhar.toString().length != 10) {
                    document.getElementById('aadharerr').innerHTML =" ** Aadhar No should be of 10 digits";
                    e.preventDefault();	
                }
                if (gender == "") {
                    document.getElementById('gendererr').innerHTML =" ** Please fill the gender field";
                    e.preventDefault();	
                }
                if (mobileNumber == "") {
                    document.getElementById('mobileNumbererr').innerHTML =" ** Please fill the mobileNumber field";
                    e.preventDefault();	
                }
                else if(mobileNumber.toString().length != 10) {
                    document.getElementById('mobileNumbererr').innerHTML =" ** Mobile No should be of 10 digits";
                    e.preventDefault();	
                }
                if (email == "") {
                    document.getElementById('emailerr').innerHTML =" ** Please fill the email field";
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