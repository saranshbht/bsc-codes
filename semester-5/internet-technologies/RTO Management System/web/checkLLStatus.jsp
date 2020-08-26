<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:if test="${param.submit != null}">
    <c:set var="aadhar" value="${param.aadhar}" />
    <c:set var="uniqueid" value="${param.uniqueid}" />
    ${aadhar}${uniqueid}
    <sql:query dataSource="${con}" var="res" sql="select aadhar, id, rto from ll where aadhar='${aadhar}' AND id='${uniqueid}'" />
    <c:choose>
        <c:when test="${res.getRowCount() == 0}">
            <c:set var="aadharerr" value="Invalid Aadhar Number or Unique Id" />
            <c:set var="uniqueiderr" value="Invalid Aadhar Number or Unique Id" />
        </c:when>
        <c:otherwise>
            <c:forEach var="row" items="${res.rows}" >
                <c:set var="aadhar" value="${aadhar}" scope="session" />
                <c:set var="rto" value="${row.rto}" scope="session" />
                <c:redirect url="llstatus.jsp" />
            </c:forEach>
        </c:otherwise>
    </c:choose>
</c:if>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Check LL Status</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %>
        <br>
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Check LL Status </h1>
        <div class="container"><br>
            <div class="col-lg-6 m-auto d-block">
                <form method="POST" onsubmit="validation(event)" class="bg-light">
                    <div class="form-group">
                        <label for="aadhar" class="font-weight-bold"> Enter Aadhar Number: </label>
                        <input type="number" name="aadhar" class="form-control" id="aadhar" value="${aadhar}">
                        <span id="aadharerr" class="text-danger font-weight-bold">${aadharerr}</span>
                    </div>
                    <div class="form-group">
                        <label for="id" class="font-weight-bold"> Enter Unique id: </label>
                        <input type="number" name="uniqueid" class="form-control" id="id" value="${uniqueid}">
                        <span id="iderr" class="text-danger font-weight-bold">${uniqueiderr}</span>
                    </div>
                    <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
                </form>
                <br>
            </div>
        </div>
        <script type="text/javascript">
            function validation(e) {
                var aadhar = document.getElementById('aadhar').value;
                if (aadhar == "") {
                    document.getElementById('aadharerr').innerHTML =" ** Please fill the aadhar field";
                    e.preventDefault();
                }
                else if(aadhar.toString().length != 10) {
                    document.getElementById('aadharerr').innerHTML =" ** Aadhar No should be of 10 digits";
                    e.preventDefault();
                }
                var id = document.getElementById('id').value;
                if (id == "") {
                    document.getElementById('iderr').innerHTML =" ** Please fill the id field";
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