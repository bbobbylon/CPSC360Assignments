// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// THIS IS MAIN!!! I did not want to save it as another name because that was messing 
//the files up for some reason



using namespace std;
#include <iostream>
#include "book.h"
#include <cstdlib>
#include <time.h>
#include <string>

int main()
{
    //instantiating local variables
    std::string userTitle = " ";
    int userID = 0;
    bool checkedOut = false;
    //for a random integer for the default constructor
    srand(time(NULL));
    std::cout << "Hello World!\n";

    //creating book objects b1, b2, and b3
    //b2 is created with hardcoded parameters
    //b3 is a copy of b1
    Book b1; //default constructor
    Book b2("Strange Case of Dr Jekyll and Mr Hyde", 23, true);
    Book b3(b2);

   //per assignment instructions: get user input for first book
    //using default constructor
    std::cout << "Please enter a title for this book: " << std::endl;
    getline(std::cin, userTitle);
    //setting the title per user input
    b1.setTitle(userTitle);
    std::cout << "Please enter the book ID number: " << std::endl;
    std::cin >> (userID);
    //setting book ID per user input
    b1.setBookID(userID);


    //display the parameters to the console
    std::cout << "1stBook: " << std::endl;
    std::cout << "Title: " << b1.getTitle() << std::endl;
    std::cout << "bookID: " <<  b1.getBookID() << std::endl;
    std::cout << "checkedOut: " << b1.isBookAvailable() << std::endl;
    std::cout <<std::endl;
    b1.borrowBook();//call the borrow book function


    //reprint the stats
    std::cout << "1stBook: " << std::endl;
    std::cout << "Title: " << b1.getTitle() << std::endl;
    std::cout << "bookID: " << b1.getBookID() << std::endl;
    std::cout << "checkedOut: " << b1.isBookAvailable() << std::endl;
    std::cout << std::endl;


    //printing out b2 with the hardcoded parameters declared above
    std::cout << "2nd Book: " << std::endl;

    std::cout << "Title: " << b2.getTitle() << std::endl;
    std::cout << "bookID: " << b2.getBookID() << std::endl;
    std::cout << "checkedOut: " << b2.isBookAvailable() << std::endl;
    std::cout << std::endl;
    b2.returnBook();//return book function call

    //reprint the stats
    std::cout << "2nd Book: " << std::endl;
    std::cout << "Title: ";
    std::cout << b2.getTitle() << std::endl;
    std::cout << "bookID: " << b2.getBookID() << std::endl;
    std::cout << "checkedOut: " << b2.isBookAvailable() << std::endl;
    std::cout << std::endl;




    //printing out the copy constructor using b1
    std::cout << "3rd Book: " << std::endl;
    std::cout <<"Title: " <<b3.getTitle() << std::endl;
    std::cout << "bookID: ";
    std::cout << b3.getBookID() << std::endl;
    std::cout << "checkedOut:";
    std::cout << b3.isBookAvailable() << std::endl;


}

//TO-DO

//create a header file for the homework called book.h
// we need a book class as well that contains data on the title and if it has been rented out or not



//we need some default constuctor that sets the title to no title, the ID to random, 
//and the checkedOut to false

//we need a constructor that allows the user to initialize title and 
//book ID, and optional value for checkedOut. If no value is selected, 
//set it to false 

//we need a copy constructor


//getTitle, setTitle, getBookID, setBookID
//isCheckedOut() returns a boolean indicating whether or not the book is checked out










