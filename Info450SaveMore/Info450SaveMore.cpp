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
		cout << "D for Display Information for All Accounts" << endl;
		cout << "O for Order Checks for a Checking Account" << endl;
		cout << "W for Withdraw Money from an Account" << endl;
		cin >> doAnswer;
		cin.clear();
		cin.ignore();

		if
	}

    return 0;
}

