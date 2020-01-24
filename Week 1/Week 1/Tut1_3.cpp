// Darts Program Task 3 - Jamie L 14/1/20

// ----- Includes ------------------------------------
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <ctime>

// ----- Prototypes ----------------------------------
bool Bullseye(int);


// ----- Global Variables ----------------------------

int main()
{
	srand((unsigned)time(NULL));
	float joeHitChance = 70, noOfHits = 0, noOfThrows = 0, noOfSimulations = 20000, hitChance = 0;

	for (int i = 0; i < noOfSimulations; i++)
	{

		if (Bullseye(joeHitChance))
		{
			noOfHits++;
			std::cout << "Hit" << std::endl;
		}
		else
		{
			std::cout << "Miss" << std::endl;
		}
		noOfThrows++;
	}
	std::cout << noOfSimulations << std::endl;
	std::cout << noOfHits << std::endl;
	std::cout << hitChance << std::endl;



	std::cout << "Out of " << noOfSimulations  << " throws, " << noOfHits << " hit the target." << std::endl;
	hitChance = (noOfHits / noOfSimulations * 100);
	std::cout << "Percentage hit chance: " << hitChance << std::endl;

	system("pause");
}

bool Bullseye(int chance)
{
	return (rand() % (100 + 1) < 70);
}