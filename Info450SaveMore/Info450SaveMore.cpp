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
		printf("Account Number: %d\nAccountBalance: $%6.2f\nInterest Rate: 2.2%f\n",
			accountNumber, accountBalance, interestRate);
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
		printf("Account Number: %d\nAccountBalance: $%6.2f\nLow Balance Fee Assessed: 2.2%f\n",
			accountNumber, accountBalance, lowBalanceFee);
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
		printf("Account Number: %d\nAccountBalance: $%6.2f\nAccount Term: %d\nInterest Rate: 2.2%f\n",
			accountNumber, accountBalance, accountTerm, interestRate);
	}
};

int main()
{
	BankAccount **accountPtr;
	int numberOfAccounts = 0;
	char answer;

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
		accountPtr[i]->displayAccountInfo();
	}

    return 0;
}

