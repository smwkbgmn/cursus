#!/usr/bin/env python

import cgi

def generate_error_page(status_code, explanation):
    print("Content-Type: text/html\n")  # Required HTTP header

    # HTML body for the error page
    error_page = """
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Error {} - {}</title>
        <style>
            body {{
                font-family: Arial, sans-serif;
                background-color: #f4f4f4;
                margin: 0;
                padding: 20px;
            }}
            .container {{
                max-width: 800px;
                margin: 50px auto;
                background-color: #fff;
                padding: 20px;
                border-radius: 5px;
                box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
            }}
            h1 {{
                color: #dc3545;
            }}
        </style>
    </head>
    <body>
        <div class="container">
            <h1>Error {} - {}</h1>
            <p>{}</p>
        </div>
    </body>
    </html>
    """.format(status_code, explanation, status_code, explanation, cgi.escape(explanation))

    print(error_page)

def main():
    form = cgi.FieldStorage()

    # Get status code and explanation from CGI parameters
    status_code = form.getvalue('status_code')
    explanation = form.getvalue('explanation')

    if status_code is None or explanation is None:
        # If status code or explanation is missing, show a generic error
        generate_error_page(500, "Internal Server Error: Missing parameters")
    else:
        # Generate error page with provided status code and explanation
        generate_error_page(status_code, explanation)

if __name__ == "__main__":
    main()
