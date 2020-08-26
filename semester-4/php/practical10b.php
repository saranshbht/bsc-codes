<?php
$conn = mysqli_connect("localhost", "root", "");
mysqli_select_db($conn, "saransh");
$createQuery = "create table practical10(Username varchar(20), Password varchar(20))";
$insertQuery1 = "insert into practical10 values('Saransh', 'abc123')";
$insertQuery2 = "insert into practical10 values('Rishabh', 'abcdef')";
$insertQuery3 = "insert into practical10 values('Vipin', '123456')";
mysqli_query($conn, $createQuery);
mysqli_query($conn, $insertQuery1);
mysqli_query($conn, $insertQuery2);
mysqli_query($conn, $insertQuery3);
mysqli_close($conn);
?>
