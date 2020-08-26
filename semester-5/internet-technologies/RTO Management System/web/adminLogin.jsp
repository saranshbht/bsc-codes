<%@ taglib uri = "http://java.sun.com/jsp/jstl/sql" prefix = "sql"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Admin Login</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    
    <body>

        <c:if test="${loggedin}">
            <c:redirect url="adminPanel.jsp" />
        </c:if>
        <c:if test="${param.submit != null}">
            <sql:query dataSource="${con}" var="res" sql="select * from admin where username='${param.username}' AND password='${param.password}'" />
            <c:choose>
                <c:when test="${res.getRowCount() > 0}">
                    <c:set var="loggedin" value="true" scope="session" />
                    <c:redirect url="adminPanel.jsp" />
                </c:when>
                <c:otherwise>
                    <script>alert("Invalid Credentials");</script>
                </c:otherwise>
            </c:choose>
        </c:if>

        <%@include file="header.jsp" %>
        <br>
        <h1 class="text-white text-center font-weight-bold bg-warning" style="font-size: 55px;"> Admin Login </h1>
        <div class="container"><br>
            <div class="col-lg-6 m-auto d-block">
                <form method="POST" onsubmit="validation(event)" class="bg-light">
                    <div class="form-group">
                        <label for="username" class="font-weight-bold"> Username:: </label>
                        <input type="text" name="username" class="form-control" id="username">
                        <span id="usernameerr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <div class="form-group">
                        <label for="password" class="font-weight-bold"> Password: </label>
                        <input type="password" name="password" class="form-control" id="password">
                        <span id="passworderr" class="text-danger font-weight-bold"> </span>
                    </div>
                    <center><input type="submit" name="submit" value="LOGIN" class="btn btn-success"><center>
                </form>
                <br>
            </div>
        </div>
        <script type="text/javascript">
            function validation(e) {
                var username = document.getElementById('username').value;
                var password = document.getElementById('password').value;
                if (username == "") {
                    document.getElementById('usernameerr').innerHTML =" ** Please fill the username field";
                    e.preventDefault();
                }
                if (password == "") {
                    document.getElementById('passworderr').innerHTML =" ** Please fill the password field";
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