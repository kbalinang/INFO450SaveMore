// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "windows.h"
using namespace std;

class Account
{
public:
	int accountNum;
	double interest; 
	double balance;

public: Account()
	{
		accountNum = 0;
		interest = 0;
		balance = 0;
	}
public:
	void display();
	void add_new();
	int withdraw();
};

void Account::add_new()
{
	cout << "Enter account Number: ";
	cin >> accountNum;
	cout << "How much do you want to Deposit: ";
	cin >> balance;
	cin.clear();
	cin.ignore();
}

void Account::display()
{
	cout << "Account: " << accountNum << endl;
	cout << "Balance: " << balance << endl;
	cout << " " << endl;
}

int Account::withdraw()
{ 
	double withdraw;
	cout << "Enter amount you want to withdraw: " << endl;
	cin >> withdraw;
	balance = balance - withdraw;
	if (balance < 0)
	{
		cout << "<ALERT> Withdraw ammount is too high! Please try again." << endl;
		balance = balance + withdraw;
		return 0;
	}
	else
	{
		cout << "Withdraw is succesful! Thank you for using SaveMore!" << endl;
		cout << "Your balance is now: " << balance << endl;
		return 1;
	}
}


class Savings : public Account
{
	double varint;
	double calcSav()
	{
		if (balance < 10000)
		{
			interest = .02;
		}
		else
		{
			interest = .01;
		}
		varint = balance * interest;
		balance = balance + (balance* varint);
		balance = balance - 2;
		return balance;
	}
};

class Checking : public Account 
{
	void calcCheck()
	{
		if (balance < 500)
		{
			interest = 5;
		}
		else
		{
			interest = 0;
		}
		balance = balance - interest;
	}
};

class Cd : public Account
{
	int term;
	void getTerm()
	{
		cout << "How many terms would you like: " << endl;
		cin >> term;
	}
	void calcCd()
	{
		if (term >= 5)
		{
			interest = .10;
		}
		else
		{
			interest = .05;
		}
		balance = balance - (balance * interest);
	}
};



int main()
{
	int i = 1;
	bool answer = true;
	char response;
	do 
	{
		system("cls");
		cout << "Project By Kristoffer Balinang" << endl;
		cout << " " << endl;
		cout << "Welcome to Save-More banking service" << endl;
		cout << "------------------------------------" << endl;
		cout << "What do you want to do?" << endl;
		cout << "-----------------------" << endl;
		cout << "A. Create a new account" << endl;
		cout << "B. Display accounts" << endl;
		cout << "C. Withdraw" << endl;
		cout << "D. Quit" << endl;
		cin >> response;
		cout << " " << endl;

		if ((response == 'A') || (response == 'a'))
		{
			static int i; 
			char response; 
			system("cls");
			cout << "What type of account would you like to add?" << endl;
			cout << "-------------------------------------------" << endl;
			cout << "A. Savings" << endl;
			cout << "B. Checking" << endl;
			cout << "C. Certificate of deposit" << endl;
			cout << "D. Main menu" << endl;
			cin >> response;
			cout << " " << endl;

			if ((response == 'A') || (response == 'a'))
			{
				system("cls");
				cout << "New Savings Account" << endl;
				system ("pause");
				i++;
			}
			else if ((response == 'B') || (response == 'b'))
			{
				system("cls");
				cout << "New Checking Account" << endl;
				system("pause");
				i++;
			}
			else if ((response == 'c') || (response == 'C'))
			{
				system("cls");
				cout << "New Certificate of Deposit" << endl;
				system("pause");
				i++;
			}
			else if  ((response == 'D') || (response == 'd'))
			{
				system("cls");
				cout << "Data entry cancelled!" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "<ALERT> invalid entry. Please Try Again" << endl;
				system("pause");
			}

			answer = true;
		}
		else if ((response == 'B') || (response == 'b'))
		{
			system("cls");
			cout << " b" << endl;
			system("pause");
			answer = true;
		}
		else if ((response == 'C') || (response == 'c'))
		{
			system("cls");
			cout << " c" << endl;
			system("pause");
			answer = true;
		}
		else if ((response == 'D') || (response == 'd'))
		{
			system("cls");
			cout << "Thank you for using Save-More. Good Bye!" << endl;
			answer = false;
		}
		else
		{
			system("cls");
			cout << "<ALERT> invalid entry. Please Try Again" << endl;
			system("pause");
			answer = true;
		}
			
	} while (answer);
    return 0;
}


