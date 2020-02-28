


using namespace std;
#include <iostream>
#include "book.h"
#include <cstdlib>
#include <time.h>
#include <string>

int main()
{
    //create the book array
    Book bookLibrary[5];
    std::string bookTitle;
    //instantiating local variables
    std::string userTitle;
    int userID;
    bool checkedOut = false;
    //for a random integer for the default constructor
    srand(time(NULL));
    //std::cout << "Hello World!\n";

    //for loop that goes through each book, allowing user to input 5 titles
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter a book title for Book #" << i + 1 << std::endl;
        getline(std::cin, bookTitle); //grab user input
        userID = rand() % 1000 + 1; //assign a random bookID for each book
        bookLibrary[i] = Book(bookTitle, userID, false);//put each bookLibrary element/object to a new constructor
    }
    //testing overloaded operators
    bookLibrary[1] = bookLibrary[2] + bookLibrary[3];
    bookLibrary[4] = bookLibrary[1] - bookLibrary[2];
    bookLibrary[3] = bookLibrary[0];

    //for loop that displays to the console bookId and Title
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Title: " << bookLibrary[i].getTitle() << std::endl;
        std::cout << " BookID: " << bookLibrary[i].getBookID() << std::endl;
        std::cout << std::endl;
    }


    return 0;
}



   



