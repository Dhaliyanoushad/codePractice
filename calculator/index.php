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
    <form action="./calc.php" method="POST">
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
      
    </div>
  </div>
</body>
</html>
