#!/usr/bin/perl -w
use CGI;
use File::Spec;
use MIME::Base64;

# Get the upload directory from the environment variable, default to "html/upload"
$upload_dir = $ENV{'UPLOAD_DIR'} // "html/upload";

# Create a new CGI object
$query = new CGI;

# Check if the upload directory exists and is a directory
unless (-d $upload_dir) {
    print_error_and_exit("Upload directory not found or is not a directory: $upload_dir");
}

$filename = $query->param("photo");
$email_address = $query->param("email_address");

# Sanitize the filename
$filename =~ s/.*[\/\\](.*)/$1/;
$upload_filehandle = $query->upload("photo");

# Open the file for writing
$upload_path = File::Spec->catfile($upload_dir, $filename);
open UPLOADFILE, ">$upload_path" or die print_error_and_exit("Cannot open $upload_path: $!");

# Write the file to the specified directory
while (<$upload_filehandle>) {
    print UPLOADFILE;
}

close UPLOADFILE;

# Read the uploaded file and encode it in Base64
open UPLOADFILE, "<$upload_path" or die print_error_and_exit("Cannot open $upload_path: $!");
binmode UPLOADFILE;
my $file_content = do { local $/; <UPLOADFILE> };
close UPLOADFILE;

# Get the MIME type of the file (assuming it's an image)
my $mime_type = `file --mime-type -b $upload_path`;
chomp $mime_type;

my $base64_image = encode_base64($file_content);

# Print the HTML response
print $query->header();
print <<END_HTML;
<HTML>
<HEAD>
<TITLE>Thanks!</TITLE>
</HEAD>
<BODY>
<P>Thanks for uploading your photo!</P>
<P>Your email address: $email_address</P>
<P>Your photo:</P>
<img src="data:$mime_type;base64,$base64_image" border="0">
</BODY>
</HTML>
END_HTML

# Function to print an error message and exit
sub print_error_and_exit {
    my ($error_message) = @_;
    print $query->header();
    print <<END_HTML;
<HTML>
<HEAD>
<TITLE>Error</TITLE>
</HEAD>
<BODY>
<P><strong>Error:</strong> $error_message</P>
</BODY>
</HTML>
END_HTML
    exit;
}
