<?php
  $color = array('white', 'green', 'red');
  foreach($color as $a)
    print("$a,");
  print("<br>");
  sort($color);
  print("<ul>");
  foreach($color as $a)
    print("<li>$a</li>");
  print("</ul>");
?>
