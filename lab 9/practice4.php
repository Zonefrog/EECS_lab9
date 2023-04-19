<html>
<head></head>
<body>
<table border = "2">
<tbody>
<?php
    $size = $_POST ['size'];
    $size++;
    for ($i = 0; $i < $size; $i++){
        echo "<tr>";
        for ($j = 0; $j < $size; $j++){
            echo "<td>";
            if ($j == 0 && $i == 0){
                echo " ";
            }
            else if ($j == 0){
                echo $i;
            }
            else if ($i == 0){
                echo $j;
            }
            else {
                echo ($i) * ($j);
            }
            echo "</td>";
        }
        echo "</tr>";
    }
?>
</tbody>
</table>
</body>
</html>
