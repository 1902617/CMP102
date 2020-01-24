#pragma once
#include <string>
class Customer
{
public:
	Customer();
	~Customer();

private:
	//Attributes
	std::string name;
	int customerID;

public:
	// Function Prototypes
	void Set_Name(std::string);
	void Set_CustomerID(int);
	std::string Get_Name();
	int Get_CustomerID();
};