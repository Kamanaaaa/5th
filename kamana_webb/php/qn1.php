<html>
<body>
<?php
echo "<table border='1' cellspacing='0' cellpadding='15'><tr>";

for ($i = 1; $i <= 10; $i++) {
    $color = ($i % 2 == 0) ? "lightblue" : "lightgreen";
    echo "<td style='background-color:$color'>Column $i</td>";
}

echo "</tr></table>";
?>
</body>
</html>