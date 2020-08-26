<?php
echo<<<end
  Enter a string:<br>
  <form method = "post">
    <input name = "a" type = "text"><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;
  function isPalindrome($a){
    $j = strlen($a) - 1;
    $i = 0;
    while($i < $j){
      while($a[$i] == " ")
        $i++;
      while($a[$j] == " ")
        $j--;
      if($a[$i] != $a[$j])
        return false;
      $i++;
      $j--;
    }
    return true;
  }
  if(isset($_POST["a"])){
    $a = $_POST["a"];
    if($a){
      if(isPalindrome($a))
        print("'$a' is a palindrome\n");
      else
        print("'$a' is not a palindrome\n");
    }
    else
      print("Enter something");
  }
?>
