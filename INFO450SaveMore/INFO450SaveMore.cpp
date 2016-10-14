// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

//The role of inheritance is to be able to reduce redundancy when writing code. It alows classes to get general attritubutes without having to
//restate them in individual classes themselves. This saves time for the progammer and makes it easier to see the relationships of the clases 
//themselves. 

/*Project By Kristoffer Louie Balinang*/
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "windows.h"
using namespace std;

class Account // mother class 
{
public: //initialize variables 
	int accountNum;
	double interest; 
	double balance;
	char *Type;

public: Account()// set intial values for the variables
	{
		accountNum = 450;
		interest = 0;
		balance = 0;
	}
public: //functions that will be inherited
	virtual int deposit(double d);
	virtual void display();
	virtual int withdraw(double w);
};

int Account::deposit(double d) // function description
{
	if (d > 0)
	{
		balance = d + balance;
			return 0;
	}
	else
	{
		cout << "<ALERT> Cannot have a negative deposit!";
			return -1;
	}
}

void Account::display() // fumction description
{
	cout << " " << endl;
	cout << "<Display> " << endl;
	cout << "Account Number: " << accountNum << endl;
	cout << "Account Type: " << Type << endl;
	cout << "Balance: " << balance << endl;
	cout << "Interest: " << interest << endl;
}

int Account::withdraw(double w) // function description
{ 
	balance = balance - w;
	if (balance < 0)
	{
		cout << "<ALERT> Withdraw ammount is too high! Please try again." << endl;
		balance = balance + w;
		return 0;
	}
	else
	{
		cout << "Withdraw is succesful! Thank you for using SaveMore!" << endl;
		cout << "  " << endl;
		cout << "Your balance is now: " << balance << endl;
		return 1;
	}
}


class Savings : public Account //a class that inherites from the account class
{
public:
	Savings()
	{
		Type = "Savings"; 
	}
	double varint;
	double calcSav()
	{
		if (balance >= 10000)
		{
			interest = .02;
		}
		else
		{
			interest = .01;
		}
		return balance;
	}
};

class Checking : public Account // a class that inherits from the account class
{
public:
	Checking()
	{
		Type = "Checking";
	}
	void calcCheck()
	{
		if (balance < 500)
		{
			balance -= 5;
		}
	}
	double orderCheck(int order)
	{
		balance = balance - (order * 15.00);
			if (balance <0)
			{
				cout << "Cannot order that many checks" << endl;
				balance = balance + (order * 15.00);
				return balance;
			    
			}
			else
			{
				cout << "Order sucessful!" << endl;
				return balance;
			}
	}
};

class Cd : public Account // class that inherirates from the account class
{

public: 
	Cd()
{
	Type = " Certificate of deposit";
}
	
	void calcCd(int term)
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
	int d;
	int w;
	int term;
	int order;

	Savings SavingsAccount;
	Checking CheckingAccount;
	Cd CdAccount;

	cout << "Project By Kristoffer Balinang" << endl;
	cout << " " << endl;
	cout << "Welcome to Save-More banking service" << endl;
	cout << "------------------------------------" << endl;
	cout << "Creating bank accounts" << endl;
	system("pause");
	system("cls");
	cout << "Enter deposit for savings account:" << endl;
	cin >> d;
	SavingsAccount.deposit(d);
	system("pause");
	system("cls");
	cout << "Interest for Savings account Calculated: " << endl;
	SavingsAccount.calcSav();
	SavingsAccount.display();

	cout << "Enter ammount you want to withdraw from savings account" << endl;
	cin >> w;
	SavingsAccount.withdraw(w+2);// withdraw fee
	SavingsAccount.display();

	system("pause");
	system("cls");
	cout << "Enter deposit for checking account: " << endl;
	cin >> d;
	CheckingAccount.deposit(d);

	CheckingAccount.calcCheck();// checks for penalties 
	CheckingAccount.display();
	cout << "Enter ammount you want to withdraw from checking account" << endl;
	cin >> w;
	
	CheckingAccount.withdraw(w);
	CheckingAccount.display();
	cout << " " << endl;
	cout << "How many checks do you want to order" << endl;
	cin >> order;

	CheckingAccount.orderCheck(order);
	CheckingAccount.display();

	system("pause");

	system("cls");
	cout << "Enter deposit for Certicate of deposit: " << endl;
	cin >> d;
	CdAccount.deposit(d);


	system("cls");
	cout << "Enter years for Certficate of deposit: " << endl;
	cin >> term;
	system("pause");
	
	CdAccount.calcCd(term);
	CdAccount.display();
	system("pause");
	system("cls");
	cout << "Enter ammount you want to withdraw from Certificate of Deposit: " << endl;
	cin >> w;

	CdAccount.withdraw(w*1.1);


	SavingsAccount.display();
	CheckingAccount.display();
	CdAccount.display();

}


