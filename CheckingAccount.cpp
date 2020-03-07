#include "Account.h"
#include <iostream>
#include<string>

CheckingAcct::CheckingAcct(double withDraw, double deposit, double balanceNumber, double currentBalance) : Account(balanceNumber)
{
	secondBalance = getBalance();
	double withdraw1;
	double deposit1;
	withdraw1 = withDraw;
	deposit1 = deposit;
	double balance1;

	//setting the variables if withdraw is above 0
	if (withdraw1 > 0)
	{
		currentBalance = balance1;
		deposit = 0;
		balance1 = secondBalance + withdraw1;
		withdraw = withdraw1;
		//Cbal2 = balance1;
	}
	if (deposit1 > 0)
	{
		deposit = deposit;
		currentBalance = balance1;
		withdraw = 0;
		balance1 = secondBalance + deposit1;
		//Cbal2 = balance1;
		
	}


}
//default constructor
Account::Account(std::string ownerName, int accountNumber, double balanceNumber)
{
	OwnerName = ownerName;
	AcctNum = accountNumber;
	Balance = balanceNumber;
}

Account::Account(double balanceNumber)
{
	Balance = balanceNumber;
}
