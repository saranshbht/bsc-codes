<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<c:if test="${!loggedin || param.submit != null}">
    <% session.invalidate(); %>
    <c:redirect url="adminLogin.jsp" />
</c:if>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Admin Panel</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    
    <body>
        <%@include file="header.jsp" %>
        <div class="col-lg-6 m-auto d-block">
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Admin Panel </h1>
        <ul class="list-group">
            <li class="list-group-item"><a href="viewdlData.jsp">View DL Data</a></li>
            <li class="list-group-item"><a href="viewllData.jsp">View LL Data</a></li>
            <li class="list-group-item"><a href="viewVehicleData.jsp">View Vehicle Data</a></li>
        </ul>
        <br>
        <form method="post" class="bg-light">
            <center><input type="submit" value="Logout" name="submit" class="btn btn-danger"></center>
        </form>
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