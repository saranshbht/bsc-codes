<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta name="description" content="">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <!-- The above 4 meta tags *must* come first in the head; any other head content must come *after* these tags -->

        <!-- Title -->
        <title>RTO Management System</title>

        <!-- Core Stylesheet -->
        <link rel="stylesheet" href="style.css">
    </head>

    <body>
        <!-- ##### Preloader ##### -->
        <div id="preloader">
            <i class="circle-preloader"></i>
        </div>

        <!-- ##### Header Area Start ##### -->
        <header class="header-area">

            <!-- Top Header Area -->
            <div class="top-header">
                <div class="container h-100">
                    <div class="row h-100">
                        <div class="col-12 h-100">
                            <div class="top-header-content h-100 d-flex align-items-center justify-content-between">
                                <!-- Top Headline -->
                                <div class="top-headline">
                                    <p>Welcome to <span>RTO Management System</span></p>
                                </div>
                                <div class="login-faq-earn-money">
                                    <c:choose>
                                        <c:when test="${loggedin}">
                                            <form method='post'>
                                                <input type='submit' name='logout' value='LOGOUT'>
                                            </form>
                                            <c:if test="${param.logout != null}">
                                                <%session.invalidate();%>
                                                <c:redirect url="adminPanel.jsp" />
                                            </c:if>
                                        </c:when>
                                        <c:otherwise> 
                                            <a href='adminLogin.jsp'>Admin Login</a>
                                        </c:otherwise>
                                    </c:choose>   

                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>

            <!-- Navbar Area -->
            <div class="cryptos-main-menu">
                <div class="classy-nav-container breakpoint-off">
                    <div class="container">
                        <!-- Menu -->
                        <nav class="classy-navbar justify-content-between" id="cryptosNav">

                            <!-- Logo -->
                            <a class="nav-brand" href="index.jsp"><img src="img/core-img/logo.png" alt=""></a>

                            <!-- Navbar Toggler -->
                            <div class="classy-navbar-toggler">
                                <span class="navbarToggler"><span></span><span></span><span></span></span>
                            </div>

                            <!-- Menu -->
                            <div class="classy-menu">

                                <!-- close btn -->
                                <div class="classycloseIcon">
                                    <div class="cross-wrap"><span class="top"></span><span class="bottom"></span></div>
                                </div>

                                <!-- Nav Start -->
                                <div class="classynav">
                                    <ul>
                                        <li><a href="index.jsp">Home</a></li>
                                        <li><a href="#">Vehicle Services</a>
                                            <ul class="dropdown">
                                                <li><a href="newVehicleRegistration.jsp">Register Vehicle</a></li>
                                                <li><a href="checkVehicleRegistration.jsp">Check RC Status</a></li>
                                                <li><a href="duplicateRC.jsp">Duplicate RC</a></li>
                                            </ul>
                                        </li>
                                        <li><a href="#">License Services</a>
                                            <ul class="dropdown">
                                                <li><a href="newLL.jsp">Apply For New LL</a></li>
                                                <li><a href="checkLLStatus.jsp">Check LL Status</a></li>
                                                <li><a href="newdl.jsp">Apply For New DL</a></li>
                                                <li><a href="checkDLStatus.jsp">Check DL Status</a></li>
                                            </ul>
                                        </li>
                                    </ul>

                                </div>
                                <!-- Nav End -->
                            </div>
                        </nav>
                    </div>
                </div>
            </div>
        </header>
        <!-- ##### Header Area End ##### -->
    </body>
</html>