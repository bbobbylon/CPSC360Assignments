#include <string>
#include "Account.h"
#include <iostream>

int main()
{
	std::string AccountName;
	int AccountNumber;
	double AccountBalance;
	std::cout << "Enter the name of the account: " << std::endl;
	std::cin >> AccountName;

	std::cout << "Enter Account number: " << std::endl;
	std::cin >> AccountNumber;

	std::cout << "Enter the current balance of this account: " << std::endl;
	std::cin >> AccountBalance;

	Account holder(AccountName, AccountNumber, AccountBalance);


	std::cout << "Info about this account: " << std::endl;
	std::cout << "Owner Name: " << holder.getOwnerName() << std::endl;
	std::cout << "Account Number: " << holder.getAcctNum() << std::endl;
	std::cout << "Current Balance: " << holder.getBalance() << std::endl;

		 

}
 