#pragma once

class Account
{
public:
	Account();
	Account(float);
	~Account();

private:
	// Attributes
	float balance;
	int regCustomerID;
	float interest;

public:
	// Funtion Prototypes
	void Withdraw(float);
	void Deposit(float);
	float Display_Balance();
	void Set_Interest(float);
	void Set_Balance(float);
	void Set_RegCustomerID(int);
	int Get_RegCustomerID();
	float Get_Interest();
};