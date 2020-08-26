<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta http-equiv="X-UA-Compatible" content="ie=edge">
        <title>Vehicle Registration Result</title>
    </head>
    <body>
        <%@include file="header.jsp" %>
        <%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
        <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
        <c:set var="tempNo" value="${sessionScope.tempNo}" />
        <c:set var="status" value="${sessionScope.status}" />
        <c:choose>
            <c:when test="${status == 1}">
                <c:set var="displayStatus" value="Accepted" />
            </c:when>
            <c:otherwise>
                <c:set var="displayStatus" value="Pending" />
            </c:otherwise>
        </c:choose>
        <h1>Vehicle Registration Status</h1> <br>
        <h2>Status : ${displayStatus} <br></h2>
        <c:if test="${status == 1}">
            <sql:query dataSource="${con}" var="res" sql="select vehicleNumber from vehicle where tempNo='${tempNo}'" />
            <c:forEach var="row" items="${res.rows}">
                <h2>Permanent Vehicle Number: ${row.vehicleNumber}</h2></br>
            </c:forEach>
        </c:if>
        <% session.invalidate(); %>
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