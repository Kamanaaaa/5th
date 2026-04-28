<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

$conn = new mysqli("localhost","root","","labassignment1");
if ($conn->connect_error) die("Connection failed");

$sql = "DELETE FROM student WHERE LOWER(address)='lalitpur'";
$conn->query($sql);

$deleted = $conn->affected_rows;

if ($deleted > 0)
  echo "$deleted record(s) deleted successfully!";
else
  echo "No records found with address Lalitpur!";

$conn->close();
?>