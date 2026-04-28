<!-- save as chess.php -->
<!DOCTYPE html>
<html>
<head>
  <title>Chess Board 1 to 64</title>
</head>
<body>
<?php
echo "<table border='1' cellspacing='0' cellpadding='12' style='border-collapse:collapse;text-align:center;'>";

$num = 1;
for ($row = 1; $row <= 8; $row++) {
  echo "<tr>";
  for ($col = 1; $col <= 8; $col++) {
    $color = (($row + $col) % 2 == 0) ? "#ffffff" : "#000000";
    $textColor = ($color == "#000000") ? "#ffffff" : "#000000";
    echo "<td style='width:40px;height:40px;background:$color;color:$textColor;'>";
    echo $num;
    echo "</td>";
    $num++;
  }
  echo "</tr>";
}
echo "</table>";
?>
</body>
</html>