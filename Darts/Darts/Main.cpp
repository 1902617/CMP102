// Darts 501 - Jamie Laurenson 2020
#include <iostream>

#include "UserInterface.h"
#include "Game.h"

int main()
{
	// Objects
	UserInterface ui;
	Game game;
	

	// Variables
	bool quit = false, play = false;
	int choice = 0;

	while (!quit)
	{
		// Run User Interface
		ui.switchMode(1);
		ui.draw();

		// User Input
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			ui.switchMode(false);
			ui.addLine(" ");
			play = true;
			choice = 0;
			break;

		case 2:
			quit = true;
			choice = 0;
			break;

		default:
			break;
		}

		if (play)
		{
			std::cout << "How Many Simulations?\n";
			while (choice == 0)
			{
				std::cin >> choice;
			}

			while (!game.getGameOver())
			{
				ui.draw();
				game.play(choice);
			}

			float frequency[14];
			for (int i = 0; i < 14; i++)
			{
				frequency[i] = game.getWinFequency()[i];
			}

			std::cout << "Results from " << choice << " Simulations:\n\n";	
			std::cout << " Sid:Joe    Frequency    \n";
			std::cout << "   6:7        " << frequency[0] << "%\n";
			std::cout << "   5:7        " << frequency[1] << "%\n";
			std::cout << "   4:7        " << frequency[2] << "%\n";
			std::cout << "   3:7        " << frequency[3] << "%\n";
			std::cout << "   2:7        " << frequency[4] << "%\n";
			std::cout << "   1:7        " << frequency[5] << "%\n";
			std::cout << "   0:7        " << frequency[6] << "%\n";
			std::cout << "   7:0        " << frequency[7] << "%\n";
			std::cout << "   7:1        " << frequency[8] << "%\n";
			std::cout << "   7:2        " << frequency[9] << "%\n";
			std::cout << "   7:3        " << frequency[10] << "%\n";
			std::cout << "   7:4        " << frequency[11] << "%\n";
			std::cout << "   7:5        " << frequency[12] << "%\n";
			std::cout << "   7:6        " << frequency[13] << "%\n\n";

			quit = true;
			system("pause");
		}
	}
}