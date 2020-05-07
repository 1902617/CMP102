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
	bool quit = false;
	int choice = 0, choice2 = 0;

	while (!quit)
	{
		// Run User Interface
		ui.draw();

		// User Input
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			ui.switchMode(false);
			ui.addLine("Game:");
			ui.addLine(" ");
			break;

		case 2:
			ui.reset();
			break;

		case 3:
			std::cout << "QUIT\n";
			quit = true;
			break;

		case 4:
			ui.switchMode(false);
			break;

		case 5:
			ui.switchMode(true);
			break;

		default:
			break;
		}

		if (choice == 1)
		{
			std::cout << "How Many Simulations?\n";
			while (choice2 == 0)
			{
				std::cin >> choice2;
			}
			
			while (!game.getGameOver())
			{
				ui.draw();
				game.play(choice2);
			}
		}

		//Pick Where to shoot.
		
		// Check Throw

		// Reduce Player Score

		// Darts Left?

		// Game Over Check
	}
}