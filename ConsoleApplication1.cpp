
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int ROWS = 15;
const int SEATS_PER_ROW = 30;
const int FRONT_ROW_COST = 50;
const int BACK_ROW_COST = 40;
const int DIVIDER = 7; //first 7 rows are "front"
char available[ROWS][SEATS_PER_ROW];
double totalCost[ROWS];

//User choice in seat
int seat()
{
	
	cout << "Pick a seat from 1-30" << endl;
	int Seat;
	cin >> Seat;
	while (Seat < 1 || Seat>30)
	{
		cout << "Invalid" << endl;
		cin >> Seat;
	}
	Seat--;
	return Seat;
}
//user choice for row
int row()
{
	int Row;

	cout << "Please pick a row (1-15)" << endl;
	cin >> Row;
	while (Row < 1 || Row > 15)
	{
		cout << "Invalid" << endl;
		cin >> Row;
	}
	Row--;
	return Row;
}
//function that prints out the seats
void printSeats(char seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW)
{
	cout << "Available: #. Sold: *" << endl;
	cout << "SEAT \t123456789012345678901234567890" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		cout << endl;
		cout << "ROW:" << i + 1 << "\t";
		for (int j = 0; j < SEATS_PER_ROW; j++)
		{
			cout << seat[1][j];
		}
	}
	cout << endl;
}
//function that prints out the seats (all empty)
void openingSeats(char seat[ROWS][SEATS_PER_ROW], int ROWS, int SEATS_PER_ROW)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < SEATS_PER_ROW; j++)
		{
			seat[i][j] = '#';
		}
	}

}

//cost of a seat
void cost(double seat[][SEATS_PER_ROW], int ROWS)
{
	cout << seat[ROWS][0];
}



int main()
{
	int availableRow;
	int availableSeat;

		//declare and initialize seating array
	char concertSeats[ROWS][SEATS_PER_ROW];
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < SEATS_PER_ROW; j++)
			concertSeats[i][j] = '#';


	bool seatOpen = false;
	int totalSales = 0;  //tracks total sales
	int openSeats = 0;
	int soldSeats = 0;
	int ticketCost = 0;
	char userChoice;
	int rowChoice = 0;
	int total = 0;

	do {
		openingSeats(available, ROWS, SEATS_PER_ROW);
		//display choices
		cout << "[D]isplay Seating Chart" << endl;
		cout << "[B]uy Tickets" << endl;
		cout << "Show [T]otal Sales" << endl;
		cout << "[S]how seating information" << endl;
		cout << "[Q]uit" << endl;
		cout << "Enter option \n";
		cin >> userChoice;
		//validate option - check if it's a a valid choice
		//convert to uppercase using toupper
		userChoice = toupper(userChoice);

		//here, you can use a switch statement to write the code for what needs to be done depending on the user choice
		switch (userChoice) {
		case 'D':
			//TO DO: code for displaying seating chart
			printSeats(available, ROWS, SEATS_PER_ROW);
			break;
		case 'B':
			/*TO DO: code for letting user buy tickets
				-also updates total sales and seating chart
				-up to you to implement, but the following steps may help:
				Steps:
				1. Ask how many tickets user wants to buy
				2. For each ticket they want to purchase
					-Ask user to enter row number followed by seat number
					-Validate that the rows selected are valid (not taken)
					-If seat selection is valid, update order cost and seating chart
					-Repeat until user has purchased the number of tickets they entered
			*/
			//I could not get this section of the code to run correctly
			availableRow = row();
			availableSeat = seat();
			if (available[ROWS][SEATS_PER_ROW] == '*')
			{
				cout << "This seat is taken. Pick another one. " << endl;
			}
			else
			{
				ticketCost = totalCost[ROWS];
					total += ticketCost;
					cout << "This seat costs $" << ticketCost << endl;
					totalSales++;
			}

			break;
		case 'T':
			//TO DO: code for displaying total sales
			cout << totalSales << "$ is today's profit" << endl;
			
			break;
		case 'S':
			availableRow = row();
			if (rowChoice == 1 || 2 || 3 || 4 || 5 || 6 || 7)
			{


				cout << "These seats costs $50 " << endl;
			}
			else if (rowChoice == 8||9||10||11||12||13||14||15)
			{
				cout << "These seats cost $40" << endl;
			}
			cout << soldSeats << " Have been sold" << endl;
			
			for (int a = 0; a < SEATS_PER_ROW; a++)
			{
				if (available[availableRow][a] == '#')
				{
					openSeats++;
				}
			}

			cout << "Row " << availableRow + 1 << " Has " << openSeats << " open seats" << endl;

			openSeats = 0;
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < SEATS_PER_ROW; j++)
				{
					if (available[i][j] == '#')
						openSeats++;
				}
			}
			cout << "There are " << openSeats << " Available" << endl;
			/*TO DO: code for displaying seat info, e.g.
				-how many seats have sold
				-how many seats available for each row
				-how many seats available for the entire auditorium
			*/
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
