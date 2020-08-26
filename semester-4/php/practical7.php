<?php
echo<<<end
  Enter a comma separated list of numbers(or strings):<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
  function arraySort(&$arr){
    $n = count($arr);
    for($i = 1; $i < $n; $i++){
      $j = $i - 1;
      $key = $arr[$i];
      while($j >= 0 && $arr[$j] > $key){
        $arr[$j + 1] = $arr[$j];
        $j--;
      }
      $arr[$j + 1] = $key;
    }
  }
  if(isset($_POST["a"])){
    $arr = $_POST["a"];
    if($arr){
      $arr = explode(", ", $arr);
      arraySort($arr);
      print("Sorted array<br>");
      foreach($arr as $a)
        print("$a ");
    }
    else
      print("Enter something");
  }
?>
