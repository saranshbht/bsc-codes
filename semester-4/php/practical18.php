<?php
echo<<<end
  Enter a number:<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
$set = [];
function print_Fib($a){
  global $set;
  if($a < 1)
    return 0;
  if($a == 1){
    if(in_array(1, $set) == false){
      $set[] = 1;
      print($a." ");
    }
    return 1;
  }
  $num = print_Fib($a - 1) + print_Fib($a - 2);
  if(in_array($num, $set) == false){
    $set[] = $num;
    print($num." ");
  }
  return $num;
}

if(isset($_POST["a"])){
  $a = $_POST["a"];
  if(is_numeric($a) && $a > 0 && strpos($a, ".") === false){
    print("1 ");
    if($a > 1)
      print_Fib($a);
  }
  else
    print("Enter only a positive integer");
}
else
  print("Enter the value");
?>
