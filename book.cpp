#include <iostream>
#include "book.h"
using namespace std;

#include <time.h>
#include <string>

//default constructor with a body

//first one is name of the class, 
//second one is the name of the function
Book::Book()
{
	srand(time(NULL));
	std::cout << "Here is the default constructor" << std::endl;
	checkedOut = false;
	title = "No Title";
	bookID = rand() % 1000 + 1;
}



//constructor that allows the user to initialize title and BookID
//optional value for checkedOut
Book::Book(string bookTitle, int ID, bool t)
{
	title = bookTitle;
	bookID = ID;
	checkedOut = t;

}


//copy constructor

Book::Book(const BookClass& bookObj)
{
	title = bookObj.title;
	bookID = bookObj.bookID;
	checkedOut = bookObj.checkedOut;
}





//getters being initialized/created with their parameters

std::string Book::getTitle() const
{
	return title;
}

int Book::getBookID() 
{
	return bookID;
}

//setters being created
void Book::setTitle(string t)
{
	title = t;
}
void Book::setBookID(int b)
{
	bookID = b;
}

//boolean that returns false by default
bool Book::isCheckedOut()
{
	return checkedOut;
	
}

//void method that checks to see if a book is already being rented
//if it is, then we give a print statement to let them know
void Book::borrowBook()
{
	if (isCheckedOut() == true)
	{
		std::cout << "This book is already being rented out,sorry." << std::endl;
	}
	else
	{
		isCheckedOut() == true;
	}

}

//check to see if the book is available to rent
//uses same style as borrowBook.
std::string Book::isBookAvailable()
{
	if (isCheckedOut() == true)
	{
		return "This book is already being rented out,sorry.";
	}
	else 
	{
		return "This book is available";
	}
}

//return book function that, when called, will
//change the isCheckedOut function to false, 
//making the book available
void Book::returnBook()
{
	checkedOut == false;

}
