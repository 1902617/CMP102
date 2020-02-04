#include "Account.h"
#include <iostream>

Account::Account()
{

}

Account::Account(float bal)
{
	balance = bal;
}

Account::~Account()
{
}

void Account::Withdraw(float witAmount)
{
	if (witAmount > Account::balance)
	{
		std::cout << "You have insufficient funds in you're account." << std::endl;
	}
	else
	{
		Account::balance -= witAmount;
	}	
}

void Account::Deposit(float depAmount)
{
	Account::balance += depAmount;
}


// ----- Setters ---------------------------
void Account::Set_RegCustomerID(int id)
{
	Account::regCustomerID = id;
}


void Account::Set_Interest(float i)
{
	Account::interest = i;
}

void Account::Set_Balance(float b)
{
	Account::balance = b;
}

// ----- Getters ---------------------------
float Account::Display_Balance()
{
	return Account::balance;
}

int Account::Get_RegCustomerID()
{
	return Account::regCustomerID;
}

float Account::Get_Interest()
{
	return Account::interest;
}