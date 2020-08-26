<?php
echo<<<end
  Enter a string:<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
  function removeWhitespaces(&$a){
    $n = strlen($a);
    $str = $a[0];
    for($i = 1; $i < $n; $i++)
      if($a[$i] != " ")
        $str .= $a[$i];
    $a = $str;
  }
  if(isset($_POST["a"])){
    $a = $_POST["a"];
    if($a){
      removeWhitespaces($a);
      print("String after removing whitespaces : $a");
    }
    else
      print("Enter something");
  }
?>
