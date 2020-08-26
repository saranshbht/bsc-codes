<?php
echo<<<end
  Enter a string:<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
  function isLower($a){
    $n = strlen($a);
    for($i = 0; $i < $n; $i++)
      if($a[$i] > 'z' || $a[$i] < 'a')
        return false;
    return true;
  }
  if(isset($_POST["a"])){
    $a = $_POST["a"];
    if($a){
      if(isLower($a))
        print("All characters in '$a' are in lowercase\n");
      else
        print("Some character(s) in '$a' are in uppercase\n");
    }
    else
      print("Enter something");
  }
?>
