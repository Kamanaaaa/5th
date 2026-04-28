<?php
$conn = new mysqli("localhost", "root", "", "labassignment1");
if ($conn->connect_error) die("Connection failed");

$sql = "UPDATE student SET address='Dallu' WHERE name='Suresh'";
if ($conn->query($sql) === TRUE) echo "Updated successfully";
else echo "Error: " . $conn->error;

$conn->close();
?>