<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Show DL</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %>
        <br>
        <div class="row">
            <div class="col-lg-6 m-auto d-block">
                <ul class="list-group">
                    <li class="list-group-item text-muted" contenteditable="false">DL:</li>
                    <%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql" %>
                    <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

                    <c:set var="aadhar" value="${sessionScope.aadhar}" />
                    <c:set var="dlno" value="${sessionScope.dlno}" />
                    <sql:query dataSource="${con}" var="res" sql="select * from dl where aadhar='${aadhar}' AND dlno='${dlno}'" />
                    <c:forEach var="row" items="${res.rows}" >
                        <c:set var="name" value="${row.name}" />
                        <c:set var="fatherName" value="${row.fatherName}" />
                        <c:set var="dob" value="${row.dob}" />
                        <c:set var="bloodGroup" value="${row.bloodGroup}" />
                        <c:set var="address" value="${row.address}" />
                        <c:set var="aadhar" value="${row.aadhar}" />
                        <c:set var="validity" value="${row.validity}" />
                        <c:set var="issueDate" value="${row.issueDate}" />
                    </c:forEach>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>DL NO:</strong></span>${dlno}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Name:</strong></span>${name}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Father's Name:</strong></span>${fatherName}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>DOB:</strong></span>${dob}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Blood Group:</strong></span>${bloodGroup}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Address:</strong></span>${address}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Aadhar Number:</strong></span>${aadhar}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Issue Date:</strong></span>${issueDate}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Validity:</strong></span>${validity}</li>
                    <%session.invalidate();%>
                </ul>
            </div>
        </div><br>
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


