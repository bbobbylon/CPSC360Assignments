#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int ROWS = 15;//constant variable for number of rows in the theatre
const int SEATS_PER_ROW = 30;//constant variable for the number of seats per row in the theatre
const int FRONT_ROW_COST = 50; //cost of rows 1-7
const int BACK_ROW_COST = 40; // cost of rows 8-15
const int DIVIDER = 7; //first 7 rows are "front"
//2D array to represent the price of each seat (as an integer, either 50 or 40)
int price[ROWS][SEATS_PER_ROW];
//2D array for what seat is available (as a char, either # or *)
char available[ROWS][SEATS_PER_ROW];

//function prototypes 
void rowPrice(int seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW);
//function with default aruguments 
bool sold(int a, int b);
int seat();
int row();
void printSeats(char seats[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW);
//function with default arguments
void openingSeats(char seats[ROWS][SEATS_PER_ROW], int a, int b);
void cost(int seat[ROWS][SEATS_PER_ROW], int ROWS);
void allSeatsOpen(char seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW, int openSeats);
//another function with default arguments per assignment directions
void profit(int a, int b);



int main()
{
	//declaration of variables that will be used in main
	int numTix = 0; //number of tickets the user wants to buy
	int availableRow = 0;
	int availableSeat = 0;
	bool seatOpen = false;
	int totalSales = 0;  //tracks total sales
	int openSeats = 0; //tracks number of open seats available
	int soldSeats = 0; //tracks sold seats
	char userChoice;

	rowPrice(price, ROWS, SEATS_PER_ROW); // initialize the  cost of each row
	openingSeats(available, ROWS, SEATS_PER_ROW); // make all seats empty initially 
	void specificRowOpenSeats(char seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW, int openSeats, int availableRow);


	do {
		//display choices
		cout << "[D]isplay Seating Chart" << endl;
		cout << "[B]uy Tickets" << endl;
		cout << "Show [T]otal Sales in dollars and the number of seats sold" << endl;
		cout << "[S]how seating information (Seats available) " << endl;
		cout << "[Q]uit" << endl;
		cout << "Pick an option: ";
		cin >> userChoice;
		//validate option - check if it's a a valid choice
		//convert to uppercase using toupper
		userChoice = toupper(userChoice);

		//here, you can use a switch statement to write the code for what needs to be done depending on the user choice
		switch (userChoice) {
		case 'D':
			//TO DO: code for displaying seating chart
			printSeats(available, ROWS, SEATS_PER_ROW);
			cout << endl;
			break;
		case 'B':
			cout << "Enter the number of tickets you would like to buy : " << endl;
			cin >> numTix;
			/*for loop that takes the users input of the number of seats they want,
			with a nested if loop that has the user pick another seat if the seat 
			 is already taken. I was not too sure on how I could make this entire 
			 section into a function, as multiple functions are called in case B
			 UPDATE: I was able to put all of the for loop in a function, but the sold seats
			 per row and the entire theatre would not update/ would be inaccurate....
			 */
			for (int i = 0; i < numTix; i++)
			{
				//call the row and seat functions for user input 
				availableRow = row();
				availableSeat = seat();
				bool alreadySold;
				alreadySold = sold(availableRow, availableSeat);
				if (alreadySold)
				{
					cout << "This seat is sold, pick another please: " << endl;
					availableRow = row();
					availableSeat = seat();
					alreadySold = sold(availableRow, availableSeat);
				}

				cout << "This seat costs $";
				//call the cost function at the user chosen row for the price
				cost(price, availableRow);
				//the next three lines of code is updating seating chart, total sales, and the total number of seats sold
				available[availableRow][availableSeat] = '*';
				totalSales += price[availableRow][availableSeat];
				soldSeats++;
				cout << " and you purchase is complete." << endl;
				cout << endl;
			}
			break;
		case 'T':
			//TO DO: code for displaying total sales and number of seats sold
			profit(totalSales, soldSeats);
			break;
		case 'S':
			//resetting openSeats to 0 every time this case is called
			openSeats = 0;
			availableRow = row();
			//call the function that tells how many seats are open in a specific row
			specificRowOpenSeats(available, ROWS,  SEATS_PER_ROW,  openSeats,  availableRow);
			//call the function that says how many seats are open in the whole theatre
			allSeatsOpen(available, ROWS, SEATS_PER_ROW, openSeats);
			cout << endl;
			break;
		case 'Q':
			//code to quit program
			std::cout << "Thank you for using Seat Charter";
			break;
		default:
			std::cout << "Invalid choice" << std::endl; //this should never happen
		}

	} while (userChoice != 'Q');
	return 0;
}


//function to set the price for each row
void rowPrice(int seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW)
{
	//for loop that goes through for each row(15 total)
	for (int i = 0; i < ROWS;i++)
	{
		//nested if loop that continues while i < 7
		if (i < DIVIDER)
		{
			FRONT_ROW_COST;
			//nested for loop that continues for each seat in the row
			//setting the cost of the seat to $50
			for (int j = 0; j < SEATS_PER_ROW; j++)
			{
				seat[i][j] = FRONT_ROW_COST;
			}
		}
		//else if statement with a nested for loop that goes through each row above row 7
		else if (i >= DIVIDER)
		{
			BACK_ROW_COST;
			//for each row above row 7, each seat is being set to a price of $40
			for (int j = 0; j < SEATS_PER_ROW; j++)
			{
				seat[i][j] = BACK_ROW_COST;
			}
		}
	}

}
//function for case"T"
void profit(int sales, int seatsSold)
{
	cout << endl;
	cout << "$" << sales << " is today's profit" << endl;
	cout << seatsSold << " seats have been sold" << endl;
	cout << endl;
}
//for loop with a nested for loop that checks the
//available seats for the whole theatre
void allSeatsOpen(char seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW, int openSeats)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < SEATS_PER_ROW; j++)
		{
			if (available[i][j] == '#')
				openSeats++;
		}
	}
	cout << "There are " << openSeats << " seats available in the entire theatre" << endl;
}
//for loop with a nested if statement to check the number
//of available seats that are open for the row the user chose
void specificRowOpenSeats(char seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW, int openSeats, int availableRow)
{

	for (int a = 0; a < SEATS_PER_ROW; a++)
	{
		if (seat[availableRow][a] == '#')
		{
			openSeats++;
		}
	}

	cout << "Row " << availableRow + 1 << " has " << openSeats << " open seats" << endl;
	openSeats = 0;

}
//function that says the seat is already sold
bool sold(int ROWS, int SEATS_PER_ROW)
{
	//initialize sold to 0 aka false
	bool sold = 0;
	//if the seat is sold, change it from # to *
	if (available[ROWS][SEATS_PER_ROW] == '*')
	{
		//make sold = 1 aka true
		sold = 1;
	}
	return sold;
}
//User choice in seat
int seat()
{
	cout << "Pick a seat from 1-30" << endl;
	int Seat;
	cin >> Seat;
	//if loop that has the user pick another seat if it is not between 1 and 30
	while (Seat < 1 || Seat>30)
	{
		cout << "Invalid. Pick a seat between 1 and 30:" << endl;
		cin >> Seat;
	}
	//clear the Seat variable
	Seat--;
	return Seat;
}
//user choice for row
int row()
{
	int Row;
	cout << "Please pick a row (1-15)" << endl;
	cin >> Row;
	//if loop that has the user pick another number if they are out of the range of 1 and 15
	while (Row < 1 || Row > 15)
	{
		cout << "Invalid. Pick another row between 1 and 15:" << endl;
		cin >> Row;
	}
	//clear the Row variable
	Row--;
	return Row;
}
//function that prints out the seats
void printSeats(char seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW)
{
	cout << endl;
	cout << "Icons: Available = # ,  Sold = *" << endl;
	cout << "SEAT \t123456789012345678901234567890" << endl;//tabbed so that it lines up with the rows
	//for loop that prints each row
	for (int i = 0; i < ROWS; i++)
	{
		cout << endl;
		cout << "ROW:" << i + 1 << "\t"; //tabbed so that it matches up with the seats
		//nested for loop for printing each seat to the screen
		for (int j = 0; j < SEATS_PER_ROW; j++)
		{
			cout << seat[i][j];
		}
	}
	cout << endl;
}
//function that prints out the seats (all empty)
void openingSeats(char seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW)
{
	//the same as declaring and initialiing the array
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < SEATS_PER_ROW; j++)
		{
			seat[i][j] = '#';
		}
	}

}
//cost of a seat
void cost(int seat[ROWS][SEATS_PER_ROW], int ROWS)
{
	//to show the cost per row of each seat
	cout << seat[ROWS][0];
}
