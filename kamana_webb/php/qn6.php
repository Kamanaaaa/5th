<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

$conn = new mysqli("localhost","root","","labassignment1");
if ($conn->connect_error) die("Connection failed: " . $conn->connect_error);

$students = [
  [2,"Ram","Kathmandu","9811111111"],
  [3,"Shyam","Lalitpur","9822222222"],
  [4,"Hari","Bhaktapur","9833333333"],
  [5,"Gita","Lalitpur","9844444444"],
  [6,"Sita","Pokhara","9855555555"],
  [7,"Nabin","Butwal","9866666666"],
  [8,"Rita","Biratnagar","9877777777"],
  [9,"Kiran","Dharan","9888888888"],
  [10,"Nisha","Chitwan","9899999999"],
  [11,"Asha","Dallu","9801234567"]
];

foreach ($students as $s) {
  $conn->query("INSERT INTO student(roll,name,address,contact)
                VALUES($s[0],'$s[1]','$s[2]','$s[3]')");
}

echo "10 records inserted!";
$conn->close();
?>