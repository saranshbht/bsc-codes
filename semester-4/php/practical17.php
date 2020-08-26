<?php
  $hello = array("English" => "Hello", "Spanish" => "Hola", "French" => "Bonjour", "Russian" => "Привет", "Norwegian" => "Hallo");
echo<<<end
  Enter a number:<br>
  <form method = "post">
    <select name="language">
      <option value="English">English</option>
      <option value="Spanish">Spanish</option>
      <option value="French">French</option>
      <option value="Russian">Russian</option>
      <option value="Norwegian">Norwegian</option>
    </select><br>
    <input type = "submit" value = "Submit"><br>
  </form>
end;

  if(isset($_POST["language"])){
    $lang = $_POST["language"];
    print("<h1>");
    switch($lang){
      case "English" : print($hello[$lang]);
                        break;
      case "Spanish" : print($hello[$lang]);
                        break;
      case "French" : print($hello[$lang]);
                        break;
      case "Russian" : print($hello[$lang]);
                        break;
      case "Norwegian" : print($hello[$lang]);
                        break;
      default : print("Hello");
    }
    print("</h1>");
  }
?>
