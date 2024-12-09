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

           echo "<h2>Result<br> " .$num1." ". $operation." ". $num2," = ". htmlspecialchars($result)."</h2> ";
        }
      ?>