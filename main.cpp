#include <string>
#include "Account.h"
#include <iostream>

int main()
{
	//initializing vatriables
	char userChoice;
	std::string AccountName;
	int AccountNumber = 0;
	double AccountBalance = 0;
	double depositCheckingAccount;
	double withdrawCheckingAccount ;
	double balanceCheckingAccount ;
	double interestRateLoanAccount ;
	double balanceLoanAccount;
	double payLoanAccount;


	/*std::cout << "Enter the name of the account: " << std::endl;
	std::cin >> AccountName;

	std::cout << "Enter Account number: " << std::endl;
	std::cin >> AccountNumber;

	std::cout << "Enter the current balance of this account: " << std::endl;
	std::cin >> AccountBalance;
*/
	Account holder("Bob", 100000, 5000);


	std::cout << "Info about this account: " << std::endl;
	std::cout << "Owner Name: " << holder.getOwnerName() << std::endl;
	std::cout << "Account Number: " << holder.getAcctNum() << std::endl;
	std::cout << "Current Balance: " << holder.getBalance() << std::endl;



	CheckingAcct holder1("bob2" ,20000, 99999);

	std::cout << "Checking Account information: " << std::endl;
	std::cout << "Name of account: " << holder1.getOwnerName() << std::endl;
	std::cout << "Account number: " << holder1.getAcctNum() << std::endl;
	std::cout << "Withdraw some cash: " << std::endl;
	holder1.setWithdraw(10000);

	std::cout << "Deposit some cash: " << std::endl;;
	holder1.setDeposit(100000);
	std::cout << "Current Balance: " << holder1.getBalance() << std::endl;

	LoanAcct holder2("bob3", 12000, 4.5, 100000);


	std::cout << "Loan Account information: " << std::endl;
	std::cout << "Name of account: " << holder2.getOwnerName() << std::endl;
	std::cout << "Account number: " << holder2.getAcctNum() << std::endl;
	std::cout << "Enter your current interest rate: " << std::endl;
	std::cin >> interestRateLoanAccount;
	std::cout << "Enter a payment: " << std::endl;
	std::cin >> payLoanAccount;
	holder2.getPayBalance(payLoanAccount);

	//std::cout << "Your interest rate is : " << holder2.getInterestRate() << std::endl;
	std::cout << "Monthy accrued interest: " << std::endl;
	holder2.getCalculateInterest();
	std::cout << "Your current unpaid balance is :" << holder2.getBalance() << std::endl;







	
	std::cout << "Thank you for using this program.";
	return 0;

	
}

 
