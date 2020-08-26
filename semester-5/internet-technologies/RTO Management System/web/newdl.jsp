<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:if test="${param.submit != null}">
    <c:set var="aadhar" value="${param.aadhar}" />
    <c:set var="llno" value="${param.llno}" />
    <sql:query dataSource="${con}" var="res" sql="select * from ll where aadhar='${aadhar}' AND llno='${llno}'" />
    <c:choose>
        <c:when test="${res.getRowCount() > 0}">
            <c:forEach var="row" items="${res.rows}" >
                <c:set var="rto" value="${row.rto}" />
                <c:if test="${row.status == 0}">
                    <c:set var="aadharerr" value="Status Pending" />
                </c:if>
                <c:if test="${row.llno != llno}">
                    <c:set var="llnoerr" value="Invalid LL Number" />
                </c:if>
                <c:if test="${row.aadhar != aadhar}">
                    <c:set var="aadharerr" value="Invalid Aadhar Number" />
                </c:if>
                <c:if test="${row.status == 1 && row.llno == llno && row.aadhar == aadhar}">
                    <c:set var="llno" value="${llno}" scope="session" />
                    <c:set var="aadhar" value="${aadhar}" scope="session" />
                    <c:set var="rto" value="${rto}" scope="session" />
                    <c:redirect url="confirmll.jsp" />
                </c:if>
            </c:forEach>
        </c:when>
        <c:otherwise>
            <script>alert("No such record");</script>
        </c:otherwise>
    </c:choose>
</c:if>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Apply For New DL</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %>
        <br>
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Apply For New DL </h1>
        <div class="container"><br>
            <div class="col-lg-6 m-auto d-block">
                <form method="POST" onsubmit="validation(event)" class="bg-light">
                    <div class="form-group">
                        <label for="llno" class="font-weight-bold"> Enter LL No: </label>
                        <input type="number" name="llno" class="form-control" id="llno" value="${llno}">
                        <span id="llnoerr" class="text-danger font-weight-bold"> ${llnoerr} </span>
                    </div>
                    <div class="form-group">
                        <label for="aadhar" class="font-weight-bold"> Enter Aadhar No: </label>
                        <input type="number" name="aadhar" class="form-control" id="aadhar" value="${aadhar}">
                        <span id="aadharerr" class="text-danger font-weight-bold"> ${aadharerr} </span>
                    </div>
                    <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
                </form>
                <br>
            </div>
        </div>
        <script type="text/javascript">
            function validation(e) {
                var llno = document.getElementById('llno').value;
                var aadhar = document.getElementById('aadhar').value;
                if (llno == "") {
                    document.getElementById('llnoerr').innerHTML =" ** Please fill the llno field";
                    e.preventDefault();
                }
                else if(llno.toString().length != 10) {
                    document.getElementById('llnoerr').innerHTML =" ** LL No should be of 10 digits";
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