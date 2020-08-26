<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:set var="aadhar" value="${sessionScope.aadhar}" />
<sql:query dataSource="${con}" var="res" sql="select * from ll where aadhar='${aadhar}'" />
<c:if test="${param.submit != null}"> 
    <c:set var="name" value="${param.name}" />
    <c:set var="llno" value="${param.llno}" />
    <c:set var="fatherName" value="${param.fatherName}" />
    <c:set var="dob" value="${param.dob}" />
    <c:set var="bloodGroup" value="${param.bloodGroup}" />
    <c:set var="address" value="${param.address}" />
    <c:set var="gender" value="${param.gender}" />
    <c:set var="mobileNumber" value="${param.mobileNumber}" />
    <c:set var="email" value="${param.email}" />
    <c:set var="rto" value="${param.rto}" />
    <c:set var="status" value="${param.status}" />
    <c:set var="validity" value="${param.validity}" />
    <c:set var="issueDate" value="${param.issueDate}" />
    <sql:update dataSource="${con}" var="upd" sql="update ll 
        set name='${name}', llno=${llno}, fatherName='${fatherName}', 
        dob='${dob}', bloodGroup='${bloodGroup}', address='${address}', gender='${gender}', 
        mobileNumber=${mobileNumber}, email='${email}', rto='${rto}', status=${status}, validity='${validity}', issueDate='${issueDate}' where aadhar=${aadhar}" />
    <c:redirect url="viewllData.jsp" />
</c:if>

<!DOCTYPE html>
<html>
<%@include file="header.jsp" %>
    <br>
    <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Edit LL Data </h1>
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
                        <label for="llno" class="font-weight-bold"> LL No: </label>
                        <input type="number" name="llno" class="form-control" id="llno" value="${row.llno}">
                        <span id="llnoerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="fatherName" class="font-weight-bold"> Father's Name: </label>
                        <input type="text" name="fatherName" class="form-control" id="fatherName" value="${row.fatherName}">
                        <span id="fatherNameerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="dob" class="font-weight-bold"> DOB: </label>
                        <input type="text" name="dob" class="form-control" id="dob" value="${row.dob}">
                        <span id="doberr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="bloodGroup" class="font-weight-bold"> Blood Group: </label>
                        <input type="text" name="bloodGroup" class="form-control" id="bloodGroup" value="${row.bloodGroup}">
                        <span id="bloodGrouperr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="address" class="font-weight-bold"> Address: </label>
                        <input type="text" name="address" class="form-control" id="address" value="${row.address}">
                        <span id="addresserr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="gender" class="font-weight-bold"> Gender: </label>
                        <input type="text" name="gender" class="form-control" id="gender" value="${row.gender}">
                        <span id="gendererr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="mobileNumber" class="font-weight-bold"> Mobile Number: </label>
                        <input type="number" name="mobileNumber" class="form-control" id="mobileNumber" value="${row.mobileNumber}">
                        <span id="mobileNumbererr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="email" class="font-weight-bold"> Email: </label>
                        <input type="email" name="email" class="form-control" id="email" value="${row.email}">
                        <span id="emailerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="rto" class="font-weight-bold"> RTO: </label>
                        <input type="text" name="rto" class="form-control" id="rto" value="${row.rto}">
                        <span id="rtoerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="status" class="font-weight-bold"> Status (0-pending, 1- approved): </label>
                        <input type="number" name="status" class="form-control" id="status" value="${row.status}">
                        <span id="statuserr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="validity" class="font-weight-bold"> Validity </label>
                        <input type="date" name="validity" class="form-control" id="validity" value="${row.validity}">
                        <span id="validityerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="issueDate" class="font-weight-bold"> Issue Date </label>
                        <input type="date" name="issueDate" class="form-control" id="issueDate" value="${row.issueDate}">
                        <span id="issueDateerr" class="text-danger font-weight-bold"> </span>
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
            var llno = document.getElementById('llno').value;
            if (llno == "") {
                document.getElementById('llnoerr').innerHTML =" ** Please fill the llno field";
                e.preventDefault();
            }
            else if(llno.toString().length != 10) {
                document.getElementById('llnoerr').innerHTML =" ** LL No should be of 10 digits";
                e.preventDefault();	
            }
            var fatherName = document.getElementById('fatherName').value;
            if (fatherName == "") {
                document.getElementById('fatherNameerr').innerHTML =" ** Please fill the fatherName field";
                e.preventDefault();
            }
            else if (!(/^[a-zA-z]+$/.test(fatherName)))
            {
                document.getElementById('fatherNameerr').innerHTML =" ** Father Name cannot contain anything other than characters";
                e.preventDefault();
            }
            var dob = document.getElementById('dob').value;
            if (dob == "") {
                document.getElementById('doberr').innerHTML =" ** Please fill the dob field";
                e.preventDefault();
            }
            var bloodGroup = document.getElementById('bloodGroup').value;
            if (bloodGroup == "") {
                document.getElementById('bloodGrouperr').innerHTML =" ** Please fill the bloodGroup field";
                e.preventDefault();
            }
            var address = document.getElementById('address').value;
            if (address == "") {
                document.getElementById('addresserr').innerHTML =" ** Please fill the address field";
                e.preventDefault();
            }
            var gender = document.getElementById('gender').value;
            if (gender == "") {
                document.getElementById('gendererr').innerHTML =" ** Please fill the gender field";
                e.preventDefault();
            }
            var mobileNumber = document.getElementById('mobileNumber').value;
            if (mobileNumber == "") {
                document.getElementById('mobileNumbererr').innerHTML =" ** Please fill the mobileNumber field";
                e.preventDefault();
            }
            else if(mobileNumber.toString().length != 10) {
                document.getElementById('mobileNumbererr').innerHTML =" ** Mobile No should be of 10 digits";
                e.preventDefault();	
            }
            var email = document.getElementById('email').value;
            if (email == "") {
                document.getElementById('emailerr').innerHTML =" ** Please fill the email field";
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
            var validity = document.getElementById('validity').value;
            if (validity == "") {
                document.getElementById('validityerr').innerHTML =" ** Please fill the validity field";
                e.preventDefault();
            }
            var issueDate = document.getElementById('issueDate').value;
            if (issueDate == "") {
                document.getElementById('issueDateerr').innerHTML =" ** Please fill the issueDate field";
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

