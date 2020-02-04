#include <iostream>
#include <string>
#include "Account.h"
#include "Customer.h"

// ----- Prototypes ---------------------
void Menu_Draw();
void Menu(int);
float Calculate_Interest(float, float);
bool Loan_Availability(float, float);
void New_User(Customer, std::string, int);
void New_Account(Account, int, float);
void Create_User();
void Create_Account(int);
void Make_Deposit();
void Make_Withdrawl();
void Account_View();

int accountsCreated = 0, customersCreated = 0;
Customer customer[10];
Account account[10];

int main()
{
	
	int menuChoice = 0;

	system("CLS");

	Menu_Draw();

	while (menuChoice != 6)
	{
		std::cin >> menuChoice;
		if (menuChoice > 0 && menuChoice < 5)
		{
			Menu(menuChoice);
		}
	}
}

void Menu_Draw()
{
	std::cout << "=======================" << std::endl;
	std::cout << " ----- Bank Menu -----" << std::endl;
	std::cout << "=======================" << std::endl;
	std::cout << " 1 - New User" << std::endl;
	std::cout << " 2 - Create Account" << std::endl;
	std::cout << " 3 - Make a Deposit" << std::endl;
	std::cout << " 4 - Make a Wihdrawl" << std::endl;
	std::cout << " 5 - View Account" << std::endl;
	std::cout << " 6 - Quit Application" << std::endl;
	std::cout << "=======================" << std::endl;
}

void Menu(int selection)
{
	switch(selection)
	{
		case 1:
		{
			Create_User();
			break;
		}

		case 2:
		{
			int id = 0;

			while(id==0)
			{
				std::cout << "Enter your user ID." << std::endl;
				std::cin >> id;
			}

			Create_Account(id);
			break;
		}

		case 3:
		{
			Make_Deposit();
			break;
		}

		case 4:
		{
			Make_Withdrawl();
			break;
		}

		case 5:
		{
			Account_View();
			break;
		}

		default:
		{
			std::cout << "Error in Menu switch." << std::endl;
			break;
		}
	}
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

void New_User(Customer cust, std::string name, int id)
{
	cust.Set_Name(name);
	cust.Set_CustomerID(id);
}

void New_Account(Account acc, int custID, float interest)
{
	acc.Set_RegCustomerID(custID);
	acc.Set_Interest(interest);
}

void Create_User()
{
	customer[customersCreated].Set_CustomerID(1000 + customersCreated);
	system("CLS");
	Menu_Draw();
	std::cout << std::endl;
	std::cout << "User account created with ID: " << 1000 + customersCreated << std::endl;
	customersCreated++;
}

void Create_Account(int id)
{
	account[accountsCreated].Set_RegCustomerID(id);
	system("CLS");
	Menu_Draw();
	std::cout << std::endl;
	std::cout << "User account created with ID: " << 1000 + customersCreated << std::endl;
	accountsCreated++;
}

void Make_Deposit()
{

}

void Make_Withdrawl()
{

}

void Account_View()
{

}