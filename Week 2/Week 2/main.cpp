#include <iostream>
#include <string>
#include "Account.h"
#include "Customer.h"

// ----- Prototypes ---------------------
float Calculate_Interest(float, float);
bool Loan_Availability(float, float);

int main()
{
	Customer jeff;
	Account accountOne;
	
	// Customer
	jeff.Set_CustomerID = 4545;
	jeff.Set_Name = "jeff";

	// Account
	accountOne.Set_Balance = 500.0;
	accountOne.Set_Interest = 2.5;
	accountOne.Set_RegCustomerID = jeff.Get_CustomerID;


}

float Calculate_Interest(float interest, float balance)
{
	float calculatedInterest;
	calculatedInterest = interest * balance;
	return calculatedInterest;
}

bool Loan_Availability(float accBalance, float reqAmount)
{
	if (reqAmount > (accBalance * 2))
	{
		return false;
	}

	else
	{
		return true;
	}
}