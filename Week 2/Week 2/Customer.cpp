#include "Customer.h"
#include <string>

Customer::Customer()
{
}
Customer::~Customer()
{
}

void Customer::Set_Name(std::string custName)
{
	Customer::name = custName;
}

void Customer::Set_CustomerID(int id)
{
	Customer::customerID = id;
}

std::string Customer::Get_Name()
{
	return Customer::name;
}
int Customer::Get_CustomerID()
{
	return Customer::customerID;
}