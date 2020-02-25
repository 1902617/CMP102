#include <iostream> 
#include "Hasher.h"
#include <string>

// - Prototypes -

// - Objects -
Hasher hasher;

// - Variables -
std::string username = "";
std::string password = "";
bool running = 1, usernameI = 0, passwordI = 0, usernameCheck = 0;;


int main()
{
	while (running)
	{
		std::cout << "Hello, please enter your username(LETTERS ONLY): ";

		while (!usernameI)		// While the user hasn't entered a username
		{
			std::cin >> username;
			if (username != "") // Checks for when a name has been entered
			{
				usernameI = 1;	// Toggles that there has been an input.
			}
		}

		if (hasher.checkUsername(username))	//Runs check for if the username is valid.
		{
			std::cout << "\nPlease enter your password(LETTERS ONLY): ";
			usernameCheck = 1;
		}
		else
		{
			std::cout << "\nSorry that is not a valid username.\n";
		}

		if (usernameCheck)	//If the name was valid
		{
			while (!passwordI) //While no password has been input
			{
				std::cin >> password;
				if (password != "")
				{
					passwordI = 1; // toggles that password has been entered
				}
			}

			;
			if (hasher.checkPassword(hasher.hashDecoder(password)))
			{
				std::cout << "Welcome, " << username << "\n";
				running = 0;
			}
			else
			{
				std::cout << "Sorry your password is incorrect.\n";
			}
		}
	}
	system("pause");
}