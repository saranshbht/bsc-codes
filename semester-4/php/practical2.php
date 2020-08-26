<?php
echo<<<end
  Enter a number:<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
  function factorialNum($a){
    if($a == 0)
      return 1;
    return $a * factorialNum($a - 1);
  }
  if(isset($_POST["a"])){
    $a = $_POST["a"];
    if(is_numeric($a) && $a >= 0 && strpos($a, ".") === false)
        print("$a! = ".factorialNum($a));
    else
      print("Enter only a non-negative integer");
  }
  else
    print("Enter the value");
?>
