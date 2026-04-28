<?php
$host = "localhost";
$user = "root";
$pass = "";

$conn = new mysqli($host, $user, $pass);
if ($conn->connect_error) die("Connection failed");

$sql = "CREATE DATABASE IF NOT EXISTS labassignment1";
if ($conn->query($sql) === TRUE) echo "Database created successfully";
else echo "Error: " . $conn->error;

$conn->close();
?>