// Darts Program Task 1 - Jamie L 14/1/20

// ----- Includes ------------------------------------
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <ctime>

// ----- Prototypes ----------------------------------

// ----- Global Variables ----------------------------

void main()
{
	srand(time(NULL));
	int joeHitChance = 70, noOfHits = 0, noOfThrows = 0, dartThrow;

	while (noOfHits < 10)
	{
		dartThrow = rand() % 100 + 1;

		if (dartThrow <= joeHitChance)
		{
			noOfHits++;
			std::cout << dartThrow << " Hit!" << std::endl;
		}
		else
		{
			std::cout << dartThrow << std::endl;
		}
		noOfThrows++;
	}
	std::cout << "Average throws to get 10 bulls: " << ((noOfThrows + noOfHits) / 2) << std::endl;
	system("pause");
}