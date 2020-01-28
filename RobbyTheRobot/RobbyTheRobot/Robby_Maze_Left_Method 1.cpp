// Going to try and get the basic methods/layout for my robby the robot program in CMP104 practical
#include <iostream>
#include "GraphicsManager.h"

Room* room;
Robot* robby;
GraphicsManager* picture;


void RobbyMove()
{
	robby->move();
	picture->draw();
}

void RobbyDir(int dir)
{
	if (dir == 2)
	{
		robby->right();
		picture->draw();
	}
	else if (dir == 1)
	{
		robby->left();
		picture->draw();
	}
	else;
}

bool RobbyCheckLeft()
{
	robby->left();

	if (robby->ahead_is_colour(room, 3) == true)
	{
		return true;
	}
	else 
	{ 
		robby->right(); 
		return false;
	}
}

int main()
{
	room = new Room(5);
	robby = new Robot();
	picture = new GraphicsManager(room, robby);

	picture->draw();

	while (!robby->ahead_is_colour(room, "green"))
	{
		// create functions for most of this stuff
		if (robby->ahead_is_colour(room, 4))
		{
			std::cout << "GREEN" << std::endl;
		}

		
		while (!robby->ahead_is_colour(room, 0) && !robby->obstacle_ahead(room) && !robby->ahead_is_colour(room, "green"))
		{
			RobbyCheckLeft();
			RobbyMove();
		}

		
		if (robby->ahead_is_colour(room, 4) == true)
		{
			break;
		}
		

	    if (RobbyCheckLeft() == true)
		{
			RobbyMove();
		}
		else
		{
			robby->right();
			if (robby->ahead_is_colour(room, 3) == true)
			{
				RobbyMove();
			}
			else
			{
				robby->right();
				RobbyMove();
			}
		}
	}

	RobbyMove();
	std::cout << "Robby Did It!!!!" << std::endl;
	system("Pause");
	return 0;
}