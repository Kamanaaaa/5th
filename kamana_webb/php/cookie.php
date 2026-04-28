<?php
setcookie("user", "Suresh", time() + 3600); // 1 hour
?>
<html>
<body>
  <h3>Cookie Example</h3>
  <?php
    if (isset($_COOKIE["user"])) {
      echo "Cookie value: " . $_COOKIE["user"];
    } else {
      echo "Cookie is set. Refresh the page to see it.";
    }
  ?>
</body>
</html>