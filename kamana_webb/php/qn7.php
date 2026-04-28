<?php
$conn = new mysqli("localhost", "root", "", "labassignment1");
if ($conn->connect_error) die("Connection failed");

$res = $conn->query("SELECT * FROM student");

echo "<table border='1' cellpadding='8' cellspacing='0'>
        <tr><th>Roll</th><th>Name</th><th>Address</th><th>Contact</th></tr>";

while ($row = $res->fetch_assoc()) {
  echo "<tr>
          <td>{$row['roll']}</td>
          <td>{$row['name']}</td>
          <td>{$row['address']}</td>
          <td>{$row['contact']}</td>
        </tr>";
}
echo "</table>";

$conn->close();
?>