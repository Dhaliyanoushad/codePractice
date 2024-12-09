<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Calculator</title>
  <link rel="stylesheet" href="styles.css">
</head>
<body>
  <div class="calculator">
    <h1>Calculator</h1>
    <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="POST">
      <input type="number" name="num1" placeholder="Enter first number" required>
      <select name="operation">
        <option value="+">+</option>
        <option value="-">−</option>
        <option value="*">×</option>
        <option value="/">÷</option>
      </select>
      <input type="number" name="num2" placeholder="Enter second number" required>
      <button type="submit">Calculate</button>
    </form>
    <div class="result">
      <?php
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $num1 = $_POST['num1'];
            $num2 = $_POST['num2'];
            $operation = $_POST['operation'];
            $result = "";

            switch ($operation) {
                case '+':
                    $result = $num1 + $num2;
                    break;
                case '-':
                    $result = $num1 - $num2;
                    break;
                case '*':
                    $result = $num1 * $num2;
                    break;
                case '/':
                    if ($num2 != 0) {
                        $result = $num1 / $num2;
                    } else {
                        $result = "Error: Division by zero";
                    }
                    break;
                default:
                    $result = "Invalid operation";
                    break;
            }
            $result=htmlspecialchars($result);
            echo "<h2>Result<br> $num1 $operation $num2 = $result</h2> ";        
          }
      ?>
    </div>
  </div>
</body>
</html>
