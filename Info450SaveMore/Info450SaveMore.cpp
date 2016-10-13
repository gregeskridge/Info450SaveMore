// Info450SaveMore.cpp : Assignment 3 demonstrates Inheritance and Polymorphism in a Banking Application
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

class BankAccount
{
protected:
	int accountNumber;
	double interestRate;
	double accountBalance;

public:
	BankAccount()
	{
		accountNumber = 0;
		interestRate = 0;
		accountBalance = 0;
	}

	virtual void getAccountInfo() = 0;
	virtual void displayAccountInfo() = 0;
	virtual void calculateMonthlyInterest() = 0;
	virtual void orderChecks() = 0;
	virtual void makeWithdrawal() = 0;
};

class Savings : public BankAccount
{

	void getAccountInfo()
	{
		cout << "Please enter your account number: ";
		cin >> accountNumber;
		cin.clear();
		cin.ignore();
		cout << "Please enter your account Balance: ";
		cin >> accountBalance;
		cin.clear();
		cin.ignore();

		if (accountBalance < 10000)
		{
			interestRate = 0.01;
		}
		else
		{
			interestRate = 0.02;
		}
	}

	void displayAccountInfo()
	{
		printf("Account Number: %d\nAccountBalance: $%6.2f\nInterest Rate: %.2f\n",
			accountNumber, accountBalance, interestRate);
	}

	void calculateMonthlyInterest()
	{
		double monthlyBalance = accountBalance;
		double monthtlyInterest = 0.00;
		int amortizeYears = 0;

		cout << "How many years of amoritization would you like to see? ";
		cin >> amortizeYears;
		cin.clear();
		cin.ignore();

		if (accountBalance < 10000)
		{
			interestRate = 0.01;
			double dependInterestRate = interestRate;

			printf("\n\tMonthly Interest for Savings Account\n");
			printf("Month\tAPR\tMonthly Interest\tNew Balance\n");
			printf("-----\t---\t----------------\t------------\n");
			printf("0\t%.2f\t\t0.00\t%.2f\n", interestRate, accountBalance);

			for (int i = 1; i < ((amortizeYears*12)+1); i++)
			{
				monthtlyInterest = monthlyBalance*(dependInterestRate/12);
				monthlyBalance += monthtlyInterest;
				printf("%d\t%.2f\t\t$%.2f\t$%.2f\n", i, dependInterestRate, monthtlyInterest, monthlyBalance);

				if (monthlyBalance >= 10000)
				{
					dependInterestRate = 0.02;
				}
				else
				{
					dependInterestRate = 0.01;
				}
			}
		}

		else
		{
			interestRate = 0.02;

			printf("\n\tMonthly Interest for Savings Account\n");
			printf("Month\tAPR\tMonthly Interest\tNew Balance\n");
			printf("-----\t---\t----------------\t------------\n");
			printf("0\t%.2f\t\t0.00\t%.2f\n", interestRate, accountBalance);

			for (int i = 1; i < ((amortizeYears * 12)+1); i++)
			{
				monthtlyInterest = monthlyBalance*(interestRate / 12);
				monthlyBalance += monthtlyInterest;
				printf("%d\t%.2f\t\t$%.2f\t$%.2f\n", i, interestRate, monthtlyInterest, monthlyBalance);
			}
		}
	}

	void orderChecks()
	{
		cout << "We're sorry, but checks cannot be ordered for a Savings account." << endl;
	}

	void makeWithdrawal()
	{
		double withdrawalAmount = 0.00;
		cout << "How much money would you like to withdraw from your Savings account? " << endl;
		cout << "Reminder: There is a $2.00 fee for Savings withdrawals." << endl;
		cin >> withdrawalAmount;
		cin.clear();
		cin.ignore();

		if (withdrawalAmount <= (accountBalance - 2.00))
		{
			cout << "Your previous account balance was: $" << accountBalance << endl;

			accountBalance = accountBalance - withdrawalAmount - 2.00;

			cout << "$" << withdrawalAmount << " has been withdrawn from your account." << endl;
			cout << "Your new account balance is: $" << accountBalance << endl;

			if (accountBalance < 10000)
			{
				interestRate = 0.01;
			}
			else
			{
				interestRate = 0.02;
			}

			cout << "Your interest rate is: " << interestRate << endl;
			cout << "Thank you for being our favorite (and only) customer!" << endl;
		}
		
		else
		{
			cout << "I'm sorry.  You don't have enough money in your account to complete the withdrawal." << endl;
			cout << "But you knew that, didn't you?" << endl;
			cout << "Have fun going back to the previous menu." << endl;
		}
	}
};

class Checking : public BankAccount
{
	double lowBalanceFee = 0.00;
	void getAccountInfo()
	{
		cout << "Please enter your account number: ";
		cin >> accountNumber;
		cin.clear();
		cin.ignore();
		cout << "Please enter your account Balance: ";
		cin >> accountBalance;
		cin.clear();
		cin.ignore();

		if (accountBalance < 500)
		{
			lowBalanceFee = 5.00;
			accountBalance -= lowBalanceFee;
		}
		else
		{
			lowBalanceFee = 0.00;
		}
	}

	void displayAccountInfo()
	{
		printf("Account Number: %d\nAccountBalance: $%6.2f\nLow Balance Fee Assessed: %.2f\n",
			accountNumber, accountBalance, lowBalanceFee);
	}

	void calculateMonthlyInterest()
	{
		cout << "We're sorry, but Checking Accounts do not earn interest." << endl;
	}

	void orderChecks()
	{
		cout << "Checks have been ordered." << endl;
		cout << "There was a $15.00 check-order fee deducted from your account." << endl;
		cout << "Your previous account balance was $" << accountBalance << endl;

		accountBalance -= 15.00;

		cout << "Your new account balance is $" << accountBalance << endl;
	}

	void makeWithdrawal()
	{
		double withdrawalAmount = 0.00;
		cout << "How much money would you like to withdraw from your Checking account? ";
		cin >> withdrawalAmount;
		cin.clear();
		cin.ignore();

		if (withdrawalAmount <= accountBalance)
		{
			cout << "Your previous account balance was: $" << accountBalance << endl;

			accountBalance -= withdrawalAmount;

			cout << "$" << withdrawalAmount << "has been withdrawn from your account." << endl;
			cout << "Your post-withdrawal account balance is: $" << accountBalance << endl;

			if (accountBalance < 500)
			{
				accountBalance -= 5.00;
				cout << "Since your account has fallen below $500, a $5.00 was charged to your account." << endl;
				cout << "Your new account balance is: $" << accountBalance << endl;

			}
			else
			{

			}

			cout << "Your interest rate is: " << interestRate << endl;
			cout << "Thank you for being our favorite (and only) customer!" << endl;
		}

		else
		{
			cout << "I'm sorry.  You don't have enough money in your account to complete the withdrawal." << endl;
			cout << "But you knew that, didn't you?" << endl;
			cout << "Have fun going back to the previous menu." << endl;
		}
	}
};

class CertificateOfDeposit : public BankAccount
{
	int accountTerm = 0;

	void getAccountInfo()
	{
		cout << "Please enter your account number: ";
		cin >> accountNumber;
		cin.clear();
		cin.ignore();
		cout << "Please enter your account Balance: ";
		cin >> accountBalance;
		cin.clear();
		cin.ignore();
		cout << "Please enter the number of years for your account term: ";
		cin >> accountTerm;
		cin.clear();
		cin.ignore();

		if (accountTerm < 5)
		{
			interestRate = 0.05;
		}
		else
		{
			interestRate = 0.10;
		}
	}

	void displayAccountInfo()
	{
		printf("Account Number: %d\nAccountBalance: $%6.2f\nAccount Term: %d\nInterest Rate: %.2f\n",
			accountNumber, accountBalance, accountTerm, interestRate);
	}

	void calculateMonthlyInterest()
	{
		double monthlyBalance = accountBalance;
		double monthtlyInterest = 0.00;

		if (accountTerm < 5)
		{
			interestRate = 0.05;

			printf("\n\tMonthly Interest for Certificate of Deposit Term\n");
			printf("Month\tAPR\tMonthly Interest\tNew Balance\n");
			printf("-----\t---\t----------------\t------------\n");
			printf("0\t%.2f\t\t$0.00\t$%.2f\n", interestRate, accountBalance);

			for (int i = 1; i < ((accountTerm * 12)+1); i++)
			{
				monthtlyInterest = monthlyBalance*(interestRate / 12);
				monthlyBalance += monthtlyInterest;
				printf("%d\t%.2f\t\t$%.2f\t$%.2f\n", i, interestRate, monthtlyInterest, monthlyBalance);
			}
		}

		else
		{
			interestRate = 0.10;

			printf("\n\tMonthly Interest for Savings Account Year 1\n");
			printf("Month\tAPR\tMonthly Interest\tNew Balance\n");
			printf("-----\t---\t----------------\t------------\n");
			printf("0\t%.2f\t\t$0.00\t$%.2f\n", interestRate, accountBalance);

			for (int i = 1; i < ((accountTerm * 12)+1); i++)
			{
				monthtlyInterest = monthlyBalance*(interestRate / 12);
				monthlyBalance += monthtlyInterest;
				printf("%d\t%.2f\t\t$%.2f\t$%.2f\n", i, interestRate, monthtlyInterest, monthlyBalance);
			}
		}
	}

	void orderChecks()
	{
		cout << "We're sorry, but checks cannot be ordered for a CD account." << endl;
	}

	void makeWithdrawal()
	{
		double withdrawalAmount = 0.00;
		cout << "How much money would you like to withdraw from your CD account? ";
		cin >> withdrawalAmount;
		cin.clear();
		cin.ignore();

		if (withdrawalAmount <= accountBalance)
		{
			double earlyWithdrawalFee = accountBalance * 0.10;

			cout << "Your previous account balance was: $" << accountBalance << endl;

			accountBalance -= withdrawalAmount;

			cout << "$" << withdrawalAmount << "has been withdrawn from your account." << endl;
			cout << "Your post-withdrawal account balance is: $" << accountBalance << endl;

			cout << "A 10 percent fee was charged to your original balance as an early-withdrawal penalty!" << endl;
			cout << "SHAME SHAME SHAME!  Learn to save your money!  You're supposed to be an adult!" << endl;

			accountBalance -= earlyWithdrawalFee;
			cout << "After a fee of $" << earlyWithdrawalFee << ", your new account balance is: " 
				<< accountBalance << endl;

			cout << "Your interest rate is: " << interestRate << endl;
			cout << "Thank you for being our favorite (and only) customer!" << endl;
		}

		else
		{
			cout << "I'm sorry.  You don't have enough money in your account to complete the withdrawal." << endl;
			cout << "But you knew that, didn't you?" << endl;
			cout << "Have fun going back to the previous menu." << endl;
		}
	}
};

int main()
{
	BankAccount **accountPtr;
	int numberOfAccounts = 0;
	char answer;
	char doAnswer = 'v';

	cout << "How many accounts will we be opening today? ";
	cin >> numberOfAccounts;
	cin.clear();
	cin.ignore();

	accountPtr = new BankAccount*[numberOfAccounts];

	for (int i = 0; i < numberOfAccounts; i++)
	{
		cout << "What type of account would you like to open? " << endl;
		cout << "Enter A for Savings" << endl;
		cout << "Enter B for Checking" << endl;
		cout << "Enter C for Certificate of Deposit (CD)" << endl;
		cin >> answer;
		cin.clear();
		cin.ignore();

		if ((answer == 'A') || (answer == 'a'))
		{
			accountPtr[i] = new Savings;
			accountPtr[i]->getAccountInfo();
		}
		else if ((answer == 'B') || (answer == 'b'))
		{
			accountPtr[i] = new Checking;
			accountPtr[i]->getAccountInfo();
		}
		else if ((answer == 'C') || (answer == 'c'))
		{
			accountPtr[i] = new CertificateOfDeposit;
			accountPtr[i]->getAccountInfo();
		}
		else
		{
			cout << "You enterred an invalid value.  Please try again." << endl;
			--i;
		}
	}

	for (int i = 0; i < numberOfAccounts; i++)
	{
		printf("\n\tAccount %d Information\n", i + 1);
		accountPtr[i]->displayAccountInfo();
	}

	
	while (doAnswer == 'v' || doAnswer == 'V' || doAnswer == 'd' || doAnswer == 'D' || doAnswer == 'o' ||
		doAnswer == 'O' || doAnswer == 'w' || doAnswer == 'W')
	{
		cout << "What would you like to do?" << endl;
		cout << "V for View Amortization Schedule for an Account" << endl;
		cout << "D for Display Information for an Account" << endl;
		cout << "O for Order Checks for a Checking Account" << endl;
		cout << "W for Withdraw Money from an Account" << endl;
		cin >> doAnswer;
		cin.clear();
		cin.ignore();

		int whichAccount = 0;

		if (doAnswer == 'v' || doAnswer == 'V')
		{
			cout << "For which account would you like to view an amortization schedule?" << endl;
			cout << "Enter one digit.  For example, enter 2 for Account Number 2." << endl;
			cin >> whichAccount;
			cin.clear();
			cin.ignore();

			if (whichAccount > numberOfAccounts)
			{
				cout << "That's an invalid account number.  You don't even have that many accounts." << endl;
				cout << "You think this is a Wells Fargo app or something?" << endl;
				cout << "Just for doing that, I'm making you go back to the previous menu." << endl;
			}

			else
			{
				whichAccount -= 1;
				accountPtr[whichAccount]->calculateMonthlyInterest();
			}
		}

		else if (doAnswer == 'd' || doAnswer == 'D')
		{
			cout << "For which account would you like to display information?" << endl;
			cout << "Enter one digit.  For example, enter 2 for Account Number 2." << endl;
			cout << "You may also select 0 to display all accounts." << endl;
			cin >> whichAccount;
			cin.clear();
			cin.ignore();

			if (whichAccount > numberOfAccounts)
			{
				cout << "That's an invalid account number.  You don't even have that many accounts." << endl;
				cout << "You think this is a Wells Fargo app or something?" << endl;
				cout << "Just for doing that, I'm making you go back to the previous menu." << endl;
			}
			
			else if (whichAccount > 0)
			{
				cout << " " << endl;
				cout << "Details for Account Number " << whichAccount << endl;
				whichAccount -= 1;
				accountPtr[whichAccount]->displayAccountInfo();
			}

			else
			{
				for (int i = 0; i < numberOfAccounts; i++)
				{
					printf("\n\tAccount %d Information\n", i + 1);
					accountPtr[i]->displayAccountInfo();
				}
			}
		}

		else if (doAnswer == 'o' || doAnswer == 'O')
		{
			cout << "For which account would you like to order checks?" << endl;
			cout << "Enter one digit.  For example, enter 2 for Account Number 2." << endl;
			cin >> whichAccount;
			cin.clear();
			cin.ignore();

			if (whichAccount > numberOfAccounts)
			{
				cout << "That's an invalid account number.  You don't even have that many accounts." << endl;
				cout << "You think this is a Wells Fargo app or something?" << endl;
				cout << "Just for doing that, I'm making you go back to the previous menu." << endl;
			}

			else
			{
				whichAccount -= 1;
				accountPtr[whichAccount]->orderChecks();
			}
		}

		else if (doAnswer == 'w' || doAnswer == 'W')
		{
			cout << "For which account would you like to withdraw money?" << endl;
			cout << "Enter one digit.  For example, enter 2 for Account Number 2." << endl;
			cin >> whichAccount;
			cin.clear();
			cin.ignore();

			if (whichAccount > numberOfAccounts)
			{
				cout << "That's an invalid account number.  You don't even have that many accounts." << endl;
				cout << "You think this is a Wells Fargo app or something?" << endl;
				cout << "Just for doing that, I'm making you go back to the previous menu." << endl;
			}

			else
			{
				whichAccount -= 1;
				accountPtr[whichAccount]->makeWithdrawal();
			}
		}

		else
		{

		}
	}

    return 0;
}

