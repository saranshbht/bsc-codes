<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>DL Status</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %>
        <div class='col-lg-6 m-auto d-block'>
            <%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
            <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
            <c:set var="aadhar" value="${sessionScope.aadhar}" />
            <c:set var="rto" value="${sessionScope.rto}" />
            <sql:query dataSource="${con}" var="res" sql="select * from dl where aadhar='${aadhar}'" />
            <c:forEach var="row" items="${res.rows}" >
                <c:set var="status" value="${row.status}" />
                <c:set var="examDate" value="${row.examDate}" />
                <c:set var="id" value="${row.id}" />
            </c:forEach>
            <c:choose>
                <c:when test="${status == 1}">
                    <div class='alert alert-success' role='alert'>
                        <strong>DL approved!</strong> Generate your DL <a href='showdlHelp.jsp' class='alert-link'>here</a>.
                    </div>
                    <%session.invalidate();%>
                </c:when>
                <c:otherwise>
                    <div class='row'>
                        <div class='col-lg-6 m-auto d-block'>
                            <ul class='list-group'>
                                <li class='list-group-item text-muted' contenteditable='false'>DL Status</li>
                                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Status:</strong></span>Pending</li>
                                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Test Date:</strong></span>${examDate}</li>
                                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>RTO Office:</strong></span>${rto}</li>
                                <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Unique ID:</strong></span>${id}</li>
                            </ul>
                        </div>
                    </div>
                </c:otherwise>
            </c:choose>
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
