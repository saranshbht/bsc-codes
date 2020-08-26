<?PHP
  echo<<<end
    Enter three numbers:<br>
    <form method = "post">
      <input name = "a" type = "text"><br>
      <input name = "b" type = "text"><br>
      <input name = "c" type = "text"><br>
      <input type = "submit" value = "Submit"><br>
    </form>
end;
  function printLargest($a, $b, $c){
    if($a > $b)
      $max = $a;
    else
      $max = $b;
    if($max < $c)
      $max = $c;
    return $max;
  }
  if(isset($_POST["a"]) && isset($_POST["b"]) && isset($_POST["c"])){
    if(is_numeric($_POST["a"]) && is_numeric($_POST["b"]) && is_numeric($_POST["c"]))
      print("Maximum Number : ".printLargest($_POST["a"], $_POST["b"], $_POST["c"]));
    else
      print("Enter only numeric values");
  }
  else
    print("Enter all the values");
?>
