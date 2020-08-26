<?php
echo<<<end
  Enter a string:<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
if(isset($_POST["a"])){
  $a = $_POST["a"];
  if($a){
    $str1 = "That";
    $str2 = "the";
    $pos = stripos($a, "the");
    print(substr_replace($a, $str1, $pos, strlen($str2)));
  }
  else
    print("Enter something");
}
?>
