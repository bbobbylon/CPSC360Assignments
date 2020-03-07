#pragma once
#include <string>
#include <iostream>
//#define Account_h
//#ifndef Account_h




class Account
{

private:
	std::string OwnerName;
	int AcctNum;
	double Balance;

public:
	Account(std::string, int, double); //default constructor prototype
	Account(double);
	Account() //define the default constructor 
	{
		OwnerName = " ";
		AcctNum = 0;
		Balance = 0;
	}

	//getter and setter prototypes and declaration at the same time
	std::string getOwnerName()
	{
		return OwnerName;
	}

	int getAcctNum()
	{
		return AcctNum;
	}
	
	double getBalance()
	{
		return Balance;
	}

	void setOwnerName()
	{
		std::string OwnerName;
	}
	
	void  setAcctNum()
	{
		AcctNum;
	}
	void setBalance()
	{
		Balance;
	}



};


//derived class Checking Account
class CheckingAcct:public Account //class that inherits the Account class
{

private:

	double currentBalance;
	double withdraw;
	double secondBalance;
	double deposit;

public:

	CheckingAcct(double, double, double, double);
	double getCurrentBalance()
	{
		return currentBalance;
	}
	double getWithdraw()
	{
		return withdraw;
	}
	double getSecondBalance()
	{
		return secondBalance;
	}
	double getDeposit()
	{
		return deposit;
	}

	void setDeposit()
	{
		deposit;
	}
	void setSecondBalance()
	{
		secondBalance;
	}

	void setWithdraw()
	{
		withdraw;
	}
	void setCurrentBalance()
	{
		currentBalance;
	}



};


class LoanAcct :public Account
{
private:

	double calculateInterest;
	double loanBalance;
	double interestRate;
	double payBalance;

public:
	//getters and setters
	LoanAcct(double, double, double);
	double getCalculateInterest()
	{
		return calculateInterest;
	}
	double getLoanBalance()
	{
		return loanBalance;
	}
	double getInterestRate()
	{
		return interestRate;
	}
	double getPayBalance()
	{
		return payBalance;
	}
	void setCalculateInterest()
	{
		calculateInterest;
	}
	void setLoanBalance()
	{
		loanBalance;
	}
	void setInterestRate()
	{
		interestRate;
	}
	void setPayBalance()
	{
		payBalance;
	}
};




//#endif