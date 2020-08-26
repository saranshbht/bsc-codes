<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:if test="${param.submit != null}">
    <c:set var="dlno" value="${param.dlno}" />
    <c:set var="aadhar" value="${param.aadhar}" />
    <sql:query dataSource="${con}" var="res" sql="select * from dl where aadhar='${aadhar}' AND dlno='${dlno}'" />
    <c:choose>
        <c:when test="${res.getRowCount() > 0}">
            <c:set var="dlno" value="${dlno}" scope="session" />
            <c:set var="aadhar" value="${aadhar}" scope="session" />
            <c:redirect url="showdl.jsp" /> 
        </c:when>
        <c:otherwise>
            <script>alert("Invalid Aadhar or DL Number");</script>
        </c:otherwise>
    </c:choose>
</c:if>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Show DL Help</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
    <%@include file="header.jsp" %>
        <br>
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Show DL Help </h1>
        <div class="container"><br>
            <div class="col-lg-6 m-auto d-block">
                <form method="POST" onsubmit="validation(event)" class="bg-light">
                    <div class="form-group">
                        <label for="dlno" class="font-weight-bold"> Enter DL Number: </label>
                        <input type="number" name="dlno" class="form-control" id="dlno">
                        <span id="dlnoerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="aadhar" class="font-weight-bold"> Enter Aadhar Number: </label>
                        <input type="number" name="aadhar" class="form-control" id="aadhar">
                        <span id="aadharerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
                </form>
                <br>
            </div>
        </div>
        <script type="text/javascript">
            function validation(e) {
                var dlno = document.getElementById('dlno').value;
                if (dlno == "") {
                    document.getElementById('dlnoerr').innerHTML =" ** Please fill the dlno field";
                    e.preventDefault();
                }
                else if(dlno.toString().length != 10) {
                    document.getElementById('dlnoerr').innerHTML =" ** DL No should be of 10 digits";
                    e.preventDefault();	
                }
                var aadhar = document.getElementById('aadhar').value;
                if (aadhar == "") {
                    document.getElementById('aadharerr').innerHTML =" ** Please fill the aadhar field";
                    e.preventDefault();
                }
                else if(aadhar.toString().length != 10) {
                    document.getElementById('aadharerr').innerHTML =" ** Aadhar No should be of 10 digits";
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