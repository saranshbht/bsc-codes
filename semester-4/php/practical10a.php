<?php
echo<<<end
  <form method = "post">
    Username : <input name = "a" type = "text"><br>
    Password : <input name = "b" type = "password"><br>
    <input type = "submit" value = "Login"><br>
  </form>
end;
$conn = mysqli_connect("localhost", "root", "");
mysqli_select_db($conn, "saransh");
$getQuery = "select * from practical10";
$result = mysqli_query($conn, $getQuery);
$flag = true;
if(isset($_POST["a"]) && isset($_POST["b"])){
  $uname = $_POST["a"];
  $pwd = $_POST["b"];
  while(($row = mysqli_fetch_assoc($result)) && $flag){
      if((strcmp($row["Username"], $uname) == 0) && (strcmp($row["Password"], $pwd) == 0)){
        print("Welcome $uname");
        $flag = false;
      }
  }
  if($flag)
    print("Invalid Login credentials");

}
else
  print("Enter your info");

?>
