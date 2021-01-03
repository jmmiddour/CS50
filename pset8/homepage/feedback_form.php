<!--Error chacking-->
ini_set('display_errors',1);
error_reporting(E_ALL);

<!--Create an email web form script using code from https://www.lcn.com/support/articles/how-to-create-an-email-form-with-php/-->
<?php
// Receive user input
$name = $_POST['your name'];
$email_address = $_POST['email_address'];
$message = $_POST['feedback'];

// Filter user input
function filter_email_header($form_field)
{
  return preg_replace('/[nr|!/<>^$%*&]+/', '', $form_field);
}

$email_address = filter_email_header($email_address);

// Send email
$headers = "From: $email_address";
$sent = mail('joanne-middour@outlook.com', 'Feedback Form Submission',
            $name, $headers, $message);

// Thank the user for their message
if ($sent)
{
  ?><html>
      <head>
        <title>Thank you</title>
      </head>
      <body>
        <h1>Thank you!</h1>
          <p>Thank you for your message. I will get back to you as soon as possible. Have a beautiful day!
          </p>
      </body>
    </html>
  <?php
}

// Notify the user if there was a problem sending their message
else
{
  ?><html>
      <head>
        <title>Something went wrong</title>
      </head>
      <body>
        <h1>Something went wrong!</h1>
        <p>We could not send your message. Please try again</p>
      </body>
    </html>
  <?php
}

?>