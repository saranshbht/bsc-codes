<?php
echo<<<end
  <form method = "post">
    Enter a string : <input name = "a" type = "text"><br>
    Enter the string to be searched : <input name = "b" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
if(isset($_POST["a"]) && isset($_POST["b"])){
  $str = $_POST["a"];
  $substr = $_POST["b"];
  if($str && $substr){
    if(strpos($str, $substr) === false)
      print("'$substr' is not a substring of '$str'");
      else
      print("'$substr' is a substring of '$str'");
  }
  else
    print("Enter both strings");
}
?>
