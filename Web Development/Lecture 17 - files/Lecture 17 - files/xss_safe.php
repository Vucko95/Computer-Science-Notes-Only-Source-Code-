<html>
<body>

<?php
    // define variables and set to empty values
    $name = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = ($_POST["name"]);
    }

?>
        
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    Name: <input type="text" name="name">
    <input type="submit" value="Submit to this page"> 
</form>
    
    
<?php
    echo "<h2>Your Input:</h2>";
    echo "Name = " . htmlspecialchars($name);
?>
    
    
</body>
</html>