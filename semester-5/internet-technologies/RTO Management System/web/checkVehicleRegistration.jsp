<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:if test="${param.submit != null}">
    <c:set var="tempNo" value="${param.tempNo}" />
    <sql:query dataSource="${con}" var="res" sql="select status from vehicle where tempNo='${tempNo}'" />
    <c:choose>
        <c:when test="${res.getRowCount() == 0}">
            <c:set var="tempNoerr" value="Invalid Temp Number" />
        </c:when>
        <c:otherwise>
            <c:forEach var="row" items="${res.rows}" >
                <c:set var="tempNo" value="${tempNo}" scope="session" />
                <c:set var="status" value="${row.status}" scope="session" />
                <c:redirect url="vehicleRegResult.jsp" />
            </c:forEach>
        </c:otherwise>
    </c:choose>
</c:if>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Check Vehicle Registration Status</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %> 
        <br>
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Check Vehicle Registration Status </h1>
        <div class="container"><br>
            <div class="col-lg-6 m-auto d-block">
                <form method="POST" onsubmit="validation(event)" class="bg-light">
                    <div class="form-group">
                                            <label for="tempNo" class="font-weight-bold"> Enter Temp Number: </label>
                                            <input type="number" name="tempNo" class="form-control" id="tempNo" value="${tempNo}">
                                            <span id="tempNoerr" class="text-danger font-weight-bold"> ${tempNoerr} </span>
                                    </div>
                    <center><input type="submit" name="submit" value="SUBMIT" class="btn btn-success"><center>
                </form>
                <br>
            </div>
        </div>
        <script type="text/javascript">
            function validation(e) {
                var tempNo = document.getElementById('tempNo').value;
                if (tempNo == "") {
                    document.getElementById('tempNoerr').innerHTML =" ** Please fill the tempNo field";
                    e.preventDefault();
                }
                else if(tempNo.toString().length != 10) {
                    document.getElementById('tempNoerr').innerHTML =" ** Temp No should be of 10 digits";
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