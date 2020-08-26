<?php
    session_start();
    $loggedin = $_SESSION['loggedin'];
    if ($loggedin == 0)
    {
        header("Location: adminLogin.php");
        session_destroy();
        die();
    }
    if (isset($_POST['adminPanel']))
    {
        header("Location: adminPanel.php");
        die();
    }
    require_once('Connection.php');
    $obj = new Connection();
    $db = $obj->getNewConnection();
    $sql = "select * from vehicle";
    $res = $db->query($sql);
    if (isset($_POST['action']) && isset($_POST['id'])) {
        if ($_POST['action'] == 'Edit') {
            $_SESSION['aadhar'] = $_POST['id'];
            header('Location: editVehicleData.php');
            die();
        }
    }
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>View Vehicle Data</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php require_once('header.php'); ?>
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
            <?php while ($row = $res->fetch_assoc()) : ?>
            <tr>
                <td><?php echo $row['aadhar'] ?></td>
                <td><?php echo $row['tempNo'] ?></td>
                <td><?php echo $row['name'] ?></td>
                <td>
                <form method="post">
                    <input type="submit" name="action" value="Edit"/>
                    <input type="hidden" name="id" value="<?php echo $row['aadhar']; ?>"/>
                </form>
                </td>
            </tr>
            <?php endwhile; ?>
        </table>
    </form>
    <br><br>
    <form method="post">
        <center><input type="submit" value="Admin Panel" name="adminPanel" class="btn btn-danger"></center>
    </form>
    <br>
    <?php require_once('footer.php'); ?>
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
