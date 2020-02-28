#ifndef BOOKCLASS_H
#define BOOKCLASS_H
#include <iostream>


//steps:
//define the class
//create member variables
//getters and setters
//constructors



class Book
{
private:
	//defining private variables to be used in BookClass.cpp
	bool checkedOut = false;
	std::string title;
	int bookID;



public:

	//getter prototypes
	int getBookID();
	bool isCheckedOut(); ///boolean function

	void borrowBook();

	void returnBook();

	//setter prototypes
	void setBookID(int bookID);
	std::string getTitle() const;
	std::string isBookAvailable();
	void setTitle(std::string title);



	//constructors (include a default constructor)
	//default constructor 
	Book();
	//constructor with parameters
	Book(std::string title, int bookID, bool te);
	//copy constructor
	Book(const Book& bookObj);

	//operator overload prototypes
	Book operator+(const Book &right);
	//we dont use const for the - operator because 
	Book operator-(Book &right);
	Book operator=(const Book& right);
};

#endif