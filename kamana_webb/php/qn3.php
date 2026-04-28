<!DOCTYPE html>
<html>
<body>
<?php
// 1) Numeric array
$num = [10, 20, 30];
$num[1] = 99;                 // change 20 to 99

// 2) Associative array
$assoc = ["name"=>"Ram", "age"=>20];
$assoc["age"] = 25;           // change age

// 3) Multidimensional array
$multi = [
  [1, 2, 3],
  [4, 5, 6]
];
$multi[0][2] = 100;           // change 3 to 100

echo "Numeric Array: ";
print_r($num);

echo "<br><br>Associative Array: ";
print_r($assoc);

echo "<br><br>Multidimensional Array: ";
print_r($multi);
?>
</body>
</html>