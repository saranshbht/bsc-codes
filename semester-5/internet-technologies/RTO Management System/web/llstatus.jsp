<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>LL Status</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %>
        <br>
        <div class="row">
            <div class="col-lg-6 m-auto d-block">
                <ul class="list-group">
                    <li class="list-group-item text-muted" contenteditable="false">LL Status</li>
                    <%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
                    <%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
                    <c:set var="aadhar" value="${sessionScope.aadhar}" />
                    <c:set var="rto" value="${sessionScope.rto}" />
                    <sql:query dataSource="${con}" var="res" sql="select * from ll where aadhar='${aadhar}'" />
                    <c:forEach var="row" items="${res.rows}" >
                        <c:set var="status" value="${row.status}" />
                        <c:set var="examDate" value="${row.examDate}" />
                        <c:set var="id" value="${row.id}" />
                    </c:forEach>
                    <c:choose>
                        <c:when test="${status == 1}">
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Status:</strong></span>Approved</li>
                            <%session.invalidate();%>
                        </c:when>
                        <c:otherwise>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Status:</strong></span>Pending</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Test Date:</strong></span>${examDate}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>RTO Office:</strong></span>${rto}</li>
                            <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Unique ID:</strong></span>${id}</li>
                        </c:otherwise>
                    </c:choose>
                </ul>
                <br><center><a href='showllHelp.jsp'><button type='button' class='btn btn-warning'>Show LL</button>  </a> </center>        
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


