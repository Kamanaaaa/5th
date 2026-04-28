<?php
$msg = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $name  = trim($_POST["name"]);
  $email = trim($_POST["email"]);
  $age   = trim($_POST["age"]);

  if ($name == "") {
    $msg = "Name is required!";
  } elseif ($email == "" || strpos($email, "@") <= 0 || strpos($email, ".") == false) {
    $msg = "Enter valid email!";
  } elseif ($age == "" || !is_numeric($age)) {
    $msg = "Age must be a number!";
  } else {
    $msg = "Form submitted successfully!";
  }
}
?>

<!DOCTYPE html>
<html>
<body>
  <h3>Form Validation</h3>

  <form method="post" action="">
    Name: <input type="text" name="name"><br><br>
    Email: <input type="text" name="email"><br><br>
    Age: <input type="text" name="age"><br><br>
    <button type="submit">Submit</button>
  </form>

  <p><?php echo $msg; ?></p>
</body>
</html>