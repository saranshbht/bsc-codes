<?php
echo<<<end
  Enter a number:<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
  function isPrime($a){
    if($a < 2)
      return false;
    for($i = 2; $i * $i <= $a; $i++)
      if($a % $i == 0)
        return false;
    return true;
  }
  if(isset($_POST["a"])){
    $a = $_POST["a"];
    if(is_numeric($a) && $a >= 0 && strpos($a, ".") === false){
      if(isPrime($a))
        print("$a is prime");
      else
        print("$a is not a prime");
    }
    else
      print("Enter only a non-negative integer");
  }
  else
    print("Enter the value");
?>
