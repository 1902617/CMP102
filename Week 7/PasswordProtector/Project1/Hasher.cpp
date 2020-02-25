#include "Hasher.h"
#include <cctype>
#include <iostream>

Hasher::Hasher()
{
	for (int i = 1; i < 27; i++)
	{
		hashValues[i - 1] = i;
	}
	userPos = 0;
}

Hasher::~Hasher()
{

}

bool Hasher::checkUsername(std::string user)
{
	bool found = false;

	for (int i = 0; i < 5; i++)
	{
		if (user == usernames[i])
		{
			found = true;
			userPos = i;
		}

		else if (found)
		{
			break;
		}

		else
		{
			found = false;
		}
	}
	return found;
}

bool Hasher::checkPassword(int n)
{
	if (n == userPos)
	{
		return true;
	}

	else
	{
		return false;
	}
}

int Hasher::hashDecoder(std::string pass)
{
	int totalValue = 0;

	for (std::string::size_type i = 0; i < pass.length(); i++)
	{
		pass[i] = tolower(pass[i]); // Converts any characters from upper to lower.
		
		for (int j = 0; j < 26; j++)
		{
			if (pass[i] == hashableCharacters[j]) //checks for the referance value
			{
				totalValue += hashValues[j];	// adds the corresponding value to the total
			}
			std::cout << totalValue << "\n";
		}
	}
	return totalValue;
}