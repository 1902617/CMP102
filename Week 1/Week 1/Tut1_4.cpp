// Darts Program Task 3 - Jamie L 14/1/20

// ----- Includes ------------------------------------
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <ctime>

// ----- Prototypes ----------------------------------
class Player;

// ----- Global Variables ----------------------------

// ----- Classes -------------------------------------

class Player
{
	public:
	int hitChance = 0, noOfHits= 0;
	bool victory = 0;
	std::string playerName = " ";

	bool Bullseye()
	{
		return (rand() % (100 + 1) <= hitChance);
	}

	void Simulation()
	{
		if (Bullseye())
		{
			noOfHits++;
		}
	}

	void WinCheck()
	{
		if (noOfHits >= 10)
		{
			victory = true;
		}
	}

	float CalculateHitChance(float simulations)
	{
		float percentageHitChance = ((noOfHits / simulations) * 100);
		return percentageHitChance;
	}

	void printStats(float &simulations)
	{
		std::cout << std::endl;
		std::cout << playerName <<": " << std::endl;
		std::cout << "Number of hits: " << noOfHits << std::endl;
		std::cout << "Hit Chance: " << CalculateHitChance(simulations) << std::endl;
	}
};


int main()
{
	srand((unsigned)time(NULL));
	float noOfThrows = 0, noOfSimulations = 200000;

	// ----- Object Creation --------------------------
	Player joe, sid;
	joe.playerName = "Joe";
	sid.playerName = "Sid";
	joe.noOfHits = 0;
	sid.noOfHits = 0;
	joe.hitChance = 71;
	sid.hitChance = 73;
	joe.victory = false;
	sid.victory = false;


	//while (!joe.victory && !sid.victory)
	for (int i = 0; i < noOfSimulations; i++)
	{
		joe.Simulation();
		//WinCheck(joe);

		sid.Simulation();
		//WinCheck(sid);

		noOfThrows++;
		//std::cout << "Joe: " << joe.noOfHits << " Sid: " << sid.noOfHits << std::endl;
	}
	/*
	if (joe.noOfHits >= sid.noOfHits)
	{
		std::cout << "Joe managed to reach 10 hits first!" << std::endl;
		std::cout << "It took " << noOfThrows << " turns." << std::endl;
	}
	
	else
	{
		std::cout << "Sid managed to reach 10 hits first!" << std::endl;
		std::cout << "It took " << noOfThrows << " turns." << std::endl;
	}
	*/

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << "Number of Simulations: " << noOfSimulations << std::endl;
	joe.printStats(noOfSimulations);
	sid.printStats(noOfSimulations);
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	system("pause");
}