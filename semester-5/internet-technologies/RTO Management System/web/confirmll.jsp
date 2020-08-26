<%@page import="java.text.SimpleDateFormat"%>
<%@page import="java.util.Date"%>
<%@page import="java.util.Calendar"%>
<%!  
    String addDays(Date d, int days) throws Exception{
        Calendar c = Calendar.getInstance();
        c.setTime(d);
        c.add(Calendar.DATE, days);  // number of days to add
        return new SimpleDateFormat("yyyy-MM-dd").format(c.getTime());
    }
%>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Confirm New DL</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body>
        <%@include file="header.jsp" %>
        <div class="row">
            <div class="col-lg-6 m-auto d-block">
                <ul class="list-group">
                    <%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql" %>
                    <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

                    <c:set var="aadhar" value="${sessionScope.aadhar}" />
                    <c:set var="llno" value="${sessionScope.llno}" />
                    <sql:query dataSource="${con}" var="res" sql="select * from ll where aadhar='${aadhar}' AND llno='${llno}'" />
                    <c:forEach var="row" items="${res.rows}" >
                        <c:set var="rto" value="${row.rto}" />
                        <c:set var="name" value="${row.name}" />
                        <c:set var="fatherName" value="${row.fatherName}" />
                        <c:set var="dob" value="${row.dob}" />
                        <c:set var="bloodGroup" value="${row.bloodGroup}" />
                        <c:set var="address" value="${row.address}" />
                        <c:set var="aadhar" value="${row.aadhar}" />
                        <c:set var="validity" value="${row.validity}" />
                        <c:set var="issueDate" value="${row.issueDate}" />
                        <c:set var="gender" value="${row.gender}" />
                        <c:set var="mobileno" value="${row.mobileNumber}" />
                        <c:set var="email" value="${row.email}" />
                        <c:set var="examDate" value="<%=addDays(new Date(), 15)%>" />
                    </c:forEach>
                    <li class='list-group-item text-muted' contenteditable='false'>LL</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>LL Number:</strong></span>${llno}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Name:</strong></span>${name}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Aadhar Number:</strong></span>${aadhar}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Father's Name:</strong></span>${fatherName}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>DOB:</strong></span>${dob}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Blood Group:</strong></span>${bloodGroup}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Address:</strong></span>${address}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Issue Date:</strong></span>${issueDate}</li>
                    <li class='list-group-item text-right'><span class='pull-left'><strong class=''>Validity:</strong></span>${validity}</li>
                    <c:if test="${param.confirm != null}">
                        <sql:update dataSource="${con}" var="res" sql="insert into dl(name, fatherName, dob, bloodGroup, address, aadhar, gender, mobileNumber, email, rto, validity, issueDate, examDate) values('${name}', '${fatherName}', '${dob}', '${bloodGroup}', '${address}', ${aadhar}, '${gender}', ${mobileno}, '${email}', '${rto}', '${validity}', '${issueDate}', '${examDate}')" />
                        <c:set var="aadhar" value="${aadhar}" scope="session" />
                        <c:set var="rto" value="${rto}" scope="session" />
                        <c:redirect url="dlstatus.jsp" />
                    </c:if>
                </ul>
            </div>
        </div>
        <form method="post">
            <br><center><input class ="btn btn-success" type="submit" value="ConfirmDetails" name="confirm"></center><br>
        </form>
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