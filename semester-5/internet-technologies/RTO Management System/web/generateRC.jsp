<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta http-equiv="X-UA-Compatible" content="ie=edge">
        <title>Generate RC</title>
    </head>
    <body>
        <%@include file="header.jsp" %>
        <br>
        <div class="row">
            <div class="col-lg-6 m-auto d-block">
                <ul class="list-group">
                    <%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
                    <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
                    <c:set var="vehicleNumber" value="${sessionScope.vehicleNumber}" />
                    <sql:query dataSource="${con}" var="res" sql="select * from vehicle where vehicleNumber='${vehicleNumber}'" />
                    <c:forEach var="row" items="${res.rows}">    
                        <c:set var="name" value="${row.name}" />
                        <c:set var="aadhar" value="${row.aadhar}" />
                        <c:set var="chassisNo" value="${row.chassisNo}" />
                        <c:set var="engineNo" value="${row.engineNo}" />
                        <c:set var="vehicleClass" value="${row.vehicleClass}" />
                        <c:set var="color" value="${row.color}" />
                        <c:set var="fuelType" value="${row.fuelType}" />
                        <c:set var="seatingType" value="${row.seatingType}" />
                        <c:set var="rto" value="${row.rto}" />
                        <c:set var="status" value="${row.status}" />
                    </c:forEach>
                    <c:choose>
                        <c:when test="${status == 1}">
                            <li class='list-group-item text-muted' contenteditable='false'>Duplicate RC</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Vehicle Number:</strong></span>${vehicleNumber}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Name:</strong></span>${name}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Aadhar Number:</strong></span>${aadhar}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Chassis Number:</strong></span>${chassisNo}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Engine Number:</strong></span>${engineNo}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Vehicle Class:</strong></span>${vehicleClass}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Color:</strong></span>${color}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Fuel Type:</strong></span>${fuelType}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Seating Type:</strong></span>${seatingType}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>RTO:</strong></span>${rto}</li>
                        </c:when>
                        <c:otherwise>
                            <h1>Vehicle Registration Status</h1><br>
                            <h2>Status : Pending <br></h2>
                        </c:otherwise>
                    </c:choose>
                    <% session.invalidate(); %>
                </ul>
            </div>
        </div>
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