#!/usr/bin/php-cgi
<?php

// Print the Content-Type header
header("Content-Type: text/html");

// Get the list of files and folders in the current directory
$directory = '.';
$files = array_diff(scandir($directory), array('..', '.'));

// Print the HTML page
echo <<<HTML
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Autoindex</title>
<style>
    ul {
        list-style-type: none;
        padding: 0;
    }
    li {
        margin-bottom: 5px;
    }
</style>
</head>
<body>
<h1>Directory Listing</h1>
<ul>
HTML;

// Loop through the list and create links for each file or folder
foreach ($files as $file) {
    $path = $file;
    if (is_dir("$directory/$file")) {
        $path .= '/';
    }
    echo "<li><a href=\"$path\">$file</a></li>\n";
}

// Print the closing HTML tags
echo <<<HTML
</ul>
</body>
</html>
HTML;
?>