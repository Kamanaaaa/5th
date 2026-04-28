<?php
session_start();

if (!isset($_SESSION["count"])) {
  $_SESSION["count"] = 1;
} else {
  $_SESSION["count"]++;
}
?>
<html>
<body>
  <h3>Session Example</h3>
  Visits in this session: <?php echo $_SESSION["count"]; ?>
</body>
</html>