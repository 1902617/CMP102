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
bool Bullseye(int);
void Simulation(Player player);
void WinCheck(Player player);


// ----- Global Variables ----------------------------

// ----- Classes -------------------------------------

class Player
{
	public:
	int hitChance = 0, noOfHits= 0;
	bool victory = 0;
	std::string playerName = " ";

	void hitTarget()
	{
		noOfHits+=1;
	}
};


int main()
{
	srand((unsigned)time(NULL));
	float noOfThrows = 0, noOfSimulations = 200;

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

	while (!joe.victory || !sid.victory)
	{
		Simulation(joe);
		WinCheck(joe);

		Simulation(sid);
		WinCheck(sid);

		noOfThrows++;
		std::cout << "Joe: " << joe.noOfHits << " Sid: " << sid.noOfHits << std::endl;
	}
	
	if (joe.noOfHits >= sid.noOfHits)
	{
		std::cout << "Joe managed to reach 10 hits first!" << std::endl;
	}
	
	else
	{
		std::cout << "Sid managed to reach 10 hits first!" << std::endl;
	}


	//std::cout << noOfSimulations << std::endl;
	//std::cout << noOfHits << std::endl;
	//std::cout << hitChance << std::endl;

	//std::cout << "Out of " << noOfSimulations << " throws, " << noOfHits << " hit the target." << std::endl;
	//hitChance = (noOfHits / noOfSimulations * 100);
	//std::cout << "Percentage hit chance: " << hitChance << std::endl;

	system("pause");
}

bool Bullseye(int chance)
{
	return (rand() % (100 + 1) < 70);
}

void Simulation(Player player)
{
	if (Bullseye(player.hitChance))
	{
		player.hitTarget();
		//std::cout << player.playerName << " Hit" << std::endl;
	}
	else
	{
		//std::cout << player.playerName << " Missed" << std::endl;
	}
}

void WinCheck(Player player)
{
	if (player.noOfHits >= 10)
	{
		player.victory = true;
	}
}