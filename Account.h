#pragma once
#include <string>
#include <iostream>
#ifndef Account_h
#define Account_h




class Account
{

protected:
	std::string OwnerName;
	int AcctNum;
	double Balance;

public:

	
	Account();//define the default constructor 
	Account(std::string name, double num, double bal);// constructor

	//getter and setter prototypes and declaration at the same time
	std::string getOwnerName() {
		return OwnerName;
	}
	double getAcctNum() {
		return AcctNum;
	}
	double getBalance()
	{
		return Balance;
	}
	void setOwnerName(std::string name);
	
	void  setAcctNum(double num);
	void setBalance(double bal);



};


//derived class Checking Account
class CheckingAcct:public Account //class that inherits the Account class
{

private:

	
	double withdraw;

	double deposit;

public:

	CheckingAcct(std::string ownerName, double num, double bal);
	/*
	double getWithdraw()
	{
		return withdraw;
	}

	double getDeposit()
	{
		return deposit;
	}
	*/
	void setDeposit(double amount);
	

	void setWithdraw(double amount);
	


};


class LoanAcct :public Account
{
private:

	double interestRate;

public:
	//getters and setters
	LoanAcct(std::string name, double num, double interest, double bal);
	void getCalculateInterest();
	
	double getInterestRate();
	void getPayBalance(double amount);
	void setInterestRate(double amount);
	
};




#endif