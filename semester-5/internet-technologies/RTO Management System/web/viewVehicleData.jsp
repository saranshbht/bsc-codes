<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:if test="${!sessionScope.loggedin}">
    <% session.invalidate(); %>
    <c:redirect url="adminLogin.jsp" /> 
</c:if>
<c:if test="${param.adminPanel != null}">
    <c:redirect url="adminPanel.jsp" /> 
</c:if>
<sql:query dataSource="${con}" var="res" sql="select * from vehicle" />
<c:if test="${param.action != null && param.id != null}">
    <c:set var="aadhar" value="${param.id}" scope="session" />
    <c:redirect url="editVehicleData.jsp" />
</c:if>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>View Vehicle Data</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %>
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> View Vehicle Data </h1>
        <form method="post">
            <table class="table">
                <thead>
                    <tr>
                        <th scope="col">Aadhar Number</th>
                        <th scope="col">Temp No</th>
                        <th scope="col">Name</th>
                        <th scope="col">Edit</th>
                    </tr>
                </thead>
                <tbody>
                    <c:forEach var="row" items="${res.rows}">
                        <tr>
                            <td>${row.aadhar}</td>
                            <td>${row.tempNo}</td>
                            <td>${row.name}</td>
                            <td>
                                <form method="post">
                                    <input type="submit" name="action" value="Edit"/>
                                    <input type="hidden" name="id" value="${row.aadhar}"/>
                                </form>
                            </td>
                        </tr>
                    </c:forEach>
                </tbody>
            </table>
        </form>
        <br><br>
        <form method="post">
            <center><input type="submit" value="Admin Panel" name="adminPanel" class="btn btn-danger"></center>
        </form>
        <br>
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
