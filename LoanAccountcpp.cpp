#include "Account.h"
#include <string>

LoanAcct::LoanAcct(double pBalance, double lBalance, double iRate) : Account(lBalance)
{
	double balance2;
	interestRate = iRate;
	payBalance = balance2 - pBalance;
	double calcIRate;

	double annualRate;

	double calculate;
	calculate = calcIRate * balance2;
	annualRate = interestRate / 12;
	calcIRate = annualRate / 100;
	//CInt = calculate;


}