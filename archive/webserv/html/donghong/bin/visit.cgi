#!/usr/bin/perl
use strict;
use warnings;
use CGI;
use CGI::Cookie;

my $query = CGI->new;

# Retrieve the cookie from the browser
my %cookies = CGI::Cookie->fetch;

# Get the visit count from the cookie, if it exists
my $visit_count = $cookies{'visit_count'} ? $cookies{'visit_count'}->value : 0;

# Increment the visit count
$visit_count++;

# Create a new cookie with the updated visit count
my $cookie = CGI::Cookie->new(
    -name    => 'visit_count',
    -value   => $visit_count,
    -expires => '+1y' # Set cookie to expire in 1 year
);

# Print the HTTP header with the cookie
print $query->header(-cookie => $cookie);

# Print the HTML response
print <<END_HTML;
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Visit Counter</title>
</head>
<body>
<h1>Welcome to Our Server!</h1>
<p>You have visited this site $visit_count times.</p>
</body>
</html>
END_HTML
