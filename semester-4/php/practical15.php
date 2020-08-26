<?php
echo<<<end
  Enter a number:<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
if(isset($_POST["a"])){
  $a = $_POST["a"];
  if(is_numeric($a) && $a >= 0 && strpos($a, ".") === false)
    print("Sum of first $a even numbers ".($a * $a + $a));
  else
    print("Enter only a non-negative integer");
}
?>
