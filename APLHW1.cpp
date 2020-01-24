// APLHW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <string>
using std::cin;
using std::cout;
using std::endl;


int main()
{
    
    int roll = 0;
    int compRoll = 0;
    int total = 0;
    int turn = 0;
    int compScore = 0;
    int compTurn = 0;
    std::string choice;
    srand(time(0));
    int x = rand() % 2 + 1;
    //My toughest issue was trying to randomize what player goes first. I was able to randomize the player, but was not sure on how I could switch everything in order 
    //to reflect if you were player one or two
   
    /*
    int player;
    player = x;
    int player2;
    if (player == 1)
    {
        player2 = player;
        compScore = total;
    }
    else if (player == 2)
    {
        player = player2;
    }
    */

    cout << "You will be Player " << x << endl;
    cout << "Enter R to roll; enter any other characters to hold\n";

    do //do loop that continues until until someone reaches 100 points
    {

        cout << "Player 1 score: " << compScore << endl;
        cout << "Player 2 score: " << total << endl;
        cout << "It is Player 1's turn.\n";
       
        do //do loop that continues until the computer either gets 1 or above 20
        {
            compRoll = rand() % 6 + 1; //get a random number between 1 and 6 to simulate a dice rolling
            cout << "Roll: " << compRoll << endl; //display the roll the computer got
            compTurn = compRoll + compTurn; //add the current roll to the turn score

            if (compRoll == 1) // if loop that gives computer 0 points for the turn; it does not reset their entire score to 0
            {
                cout << "You got Pig! \n";
                compTurn = 0;
                break;
            }

        } while (compTurn < 18);

        //some display information after the turn ends
        compScore = compScore + compTurn;
        cout << "Turn total: " << compTurn << endl;
        cout << "New score: " << compTurn << endl;
        compTurn = 0; //reset comp turn score to 0 so that it does not add their previous turn score to their total score
        cout << "Player 1 score: " << compScore << endl;
        cout << "Player 2 score: " << total << endl;
        cout << "It is Player 2's turn.\n";

        do //do loop for the User that continues until the User selects H to hold
        { 
            cout << "Would you like to [R]oll or [H]old?\n";
            std::cin >> choice;
            if (choice == "R") //if loop that rolls until you hit a one, then it breaks out of the loop
            {

                roll = rand() % 6 + 1; //roll a random number between 1 and 6 to simulate a dice roll
                turn = roll + turn; // add the current roll to the turn total
                cout << "Roll: " << roll << endl;
                cout << "Turn total: " << turn << endl;

                if (roll == 1 )
                {
                    //if loop that gives the User 0 points if they roll a 1
                    turn = 0;
                    cout << "You got Pig! \n";
                    break;
                }
            }

        } while (choice != "H"); //Hold the turn points if H is selected
        
        cout << "Your turn total is : " << turn << endl;
        total = total + turn;
        cout << "New Score: " << turn << endl;
        turn = 0;     
    }
    while (total < 100 && compScore < 100); // the do while loop that continues while both players have less than 100 points

    if (total >= 100) //little victory message for the winner
    {
        cout << "You win!";
        cout << "Your score was:" << total;

    }
    else if (compScore >= 100)
    {
        cout << "The computer won -_-";
    }
    return 0;
        }