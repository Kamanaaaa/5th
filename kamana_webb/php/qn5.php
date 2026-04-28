<?php
$host = "localhost";
$user = "root";
$pass = "";
$db   = "labassignment1";

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) die("Connection failed");

$conn->query("CREATE TABLE IF NOT EXISTS student(
  roll INT PRIMARY KEY,
  name VARCHAR(50),
  address VARCHAR(50),
  contact VARCHAR(15)
)");

$sql = "INSERT INTO student (roll, name, address, contact)
        VALUES (1, 'Suresh', 'dallu', '9800000000')";

if ($conn->query($sql) === TRUE) echo "Table created and 1 record inserted";
else echo "Error: " . $conn->error;

$conn->close();
?>