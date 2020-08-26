<?php
echo<<<end
  Enter a string:<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
  function reverseStr($a){
    $n = strlen($a);
    $m = $n / 2;
    for($i = 0; $i < $m; $i++){
      $temp = $a[$i];
      $a[$i] = $a[$n - $i - 1];
      $a[$n - $i - 1] = $temp;
    }
    return $a;
  }
  if(isset($_POST["a"])){
    $a = $_POST["a"];
    if($a)
      print("Reverse of $a : ".reverseStr($a));
    else
      print("Enter something");
  }
?>
