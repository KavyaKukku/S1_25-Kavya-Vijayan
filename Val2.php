<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Form</title>
</head>
<body>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Check if fields are empty
    if (empty($_POST['username']) || empty($_POST['password'])) {
        echo '<script>alert("Please fill in all fields.");</script>';
    } else {
        // Process the form data or store it in a database
        $username = $_POST['username'];
        $password = $_POST['password'];

        // Additional processing or database operations can be added here

        echo '<script>alert("Registration successful!");</script>';
    }
}
?>

<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
    <label for="username">Username:</label>
    <input type="text" name="username" id="username">

    <br>

    <label for="password">Password:</label>
    <input type="password" name="password" id="password">

    <br>

    <input type="submit" value="Register">
</form>

</body>
</html>
