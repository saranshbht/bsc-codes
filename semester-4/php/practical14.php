<?php
echo<<<end
<form method = "post">
  Enter an email address : <input name = "a" type = "text"><br>
  <input type = "submit" value = "Submit"><br>
</form>
end;
  if(isset($_POST["a"])){
    $a = $_POST["a"];
    $pattern = '/[a-zA-Z0-9\.]+@[a-zA-Z0-9]+\.[a-z]+/';
    $result = preg_match($pattern, $a);
    if($result)
      print("The email address is valid");
    else
      print("The email address is invalid");
  }
?>
