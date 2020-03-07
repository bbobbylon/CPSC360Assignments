#include "Account.h"
#include <string>
#include <fstream>

#include "Account.h"
#include <iostream>
#include<string>
//default constructor initialized
Account::Account(std::string name, double num, double bal)// constructor
{
	OwnerName = name;
	AcctNum = num;
	Balance = bal;
}


void Account::setOwnerName(std::string name) { OwnerName = name; }
void Account::setAcctNum(double num) { AcctNum = num; }
void Account::setBalance(double bal) { Balance = bal; }

CheckingAcct::CheckingAcct(std::string name, double accountNumber, double balanceNumber) : Account(name,accountNumber,balanceNumber)
{
	OwnerName = OwnerName;
	AcctNum = AcctNum;

	Balance = Balance;
}

void CheckingAcct::setWithdraw(double amount) { Balance = Balance - amount; }
void CheckingAcct::setDeposit(double amount) { Balance = Balance + amount; }
LoanAcct::LoanAcct(std::string name, double account, double balance, double interest) : Account(name, account, balance)
{
	OwnerName = name;
	Balance = balance;
	interestRate = interest;
	AcctNum = account;



}
double LoanAcct::getInterestRate() { return interestRate; }
void LoanAcct::getPayBalance(double amount) { Balance = Balance - amount; }
void LoanAcct::getCalculateInterest()
{
	float interest;
	interest = Balance * interestRate;
	Balance = Balance - interest;
}