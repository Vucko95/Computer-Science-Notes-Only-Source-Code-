<?php
    require_once 'dbconfig.php';
 
    try {
        $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
 
    $sql = 'SELECT lastname, 
            firstname, 
            jobtitle
            FROM employees
            ORDER BY lastname';
 
    $q = $conn->query($sql);
    
    $q->setFetchMode(PDO::FETCH_ASSOC);
 
    } 
    catch (PDOException $pe) {
        die("Could not connect to the database $dbname :" . $pe->getMessage());
    }
?>

<!DOCTYPE html>

<html>
    <head>
        <title>PHP MySQL Query Data Demo</title>
    </head>

    <body>

        <div id="container">
            <h1>Employees</h1>

            <table class="table table-bordered table-condensed">
                 <thead>
                     <tr>
                         <th>First Name</th>
                        <th>Last Name</th>
                        <th>Job Title</th>
                    </tr>
                </thead>
                <tbody>
                    <?php while ($r = $q->fetch()): ?>
                    <tr>
                        <td><?php echo htmlspecialchars($r['lastname'])?></td>
                        <td><?php echo htmlspecialchars($r['firstname']); ?></td>
                        <td><?php echo htmlspecialchars($r['jobtitle']); ?></td>
                    </tr>
                    <?php endwhile; ?>
                </tbody>
            </table>
        </div>
    
    </body>
</html>