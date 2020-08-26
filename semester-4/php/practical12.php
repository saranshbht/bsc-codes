<?php
echo<<<end
Enter date of your next birthday:<br>
<form method = "post">
  <input name = "a" type = "date"><br>
  <input type = "submit" value = "Submit"><br>
</form>
end;

if(isset($_POST["a"])){
  $date1 = date_create(date("Y-m-d"));
  $date2 = date_create($_POST["a"]);
  $diff = date_diff($date1, $date2);
  print($diff->format("%a days left for your birth day"));
}
?>
