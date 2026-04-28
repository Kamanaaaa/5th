<!DOCTYPE html>
<html>
<body>
  <h3>GET Form</h3>
  <form method="get" action="">
    Name: <input type="text" name="name"><br><br>
    Roll: <input type="text" name="roll"><br><br>
    <button type="submit">Send (GET)</button>
  </form>

  <h3>POST Form</h3>
  <form method="post" action="">
    Name: <input type="text" name="name"><br><br>
    Roll: <input type="text" name="roll"><br><br>
    <button type="submit">Send (POST)</button>
  </form>

  <hr>

  <?php
  echo "Request Method: " . $_SERVER["REQUEST_METHOD"] . "<br>";

  if ($_SERVER["REQUEST_METHOD"] == "GET" && isset($_GET["name"])) {
    $name = htmlspecialchars($_GET["name"]);
    $roll = htmlspecialchars($_GET["roll"]);
    echo "GET Data => Name: $name , Roll: $roll";
  }

  if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["name"])) {
    $name = htmlspecialchars($_POST["name"]);
    $roll = htmlspecialchars($_POST["roll"]);
    echo "POST Data => Name: $name , Roll: $roll";
  }
  ?>
</body>
</html>