   <html>   
    <head>
      <title> Sum of Consecutive Integers </title>
    </head>
    <body>
     <?php
     //saying hi
      echo "Welcome to my Web site! Hi!";
	  define('Name' , "Bob");
	  //define('PI', 3.1415);
	  echo Name;
	  $numbers = range(1,10); //getting a range from 1 to 10
	  $sumOfNums = array_sum($numbers); //call the array sum method and input the number variable
	  
	  echo "The consecutive sum from 1 to 10 is: " .$sumOfNums;
     ?>
   </body>
  </html>
