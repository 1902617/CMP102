#include <iostream>
#include "GraphicsManager.h"

Room* room;
Robot* robby;
GraphicsManager* picture;

int i = 0;

// Function to simply move robby forward then draw the picture.
void RobbyMove()
{
	robby->move();
	picture->draw();
}

// Function to turn robby and draw depending left or right if I send through a 1 or two respectively
void RobbyDir(int dir)
{
	if (dir == 1)
	{
		robby->left();
		picture->draw();
	}
	else if (dir == 2)
	{
		robby->right();
		picture->draw();
	}
}

//Functuon to turn robby left and check the colour of the tile.
bool LeftCheck()
{
	robby->left();
	if (robby->ahead_is_colour(room, "black") || robby->ahead_is_colour(room, "blue"))
	{
		robby->right();
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
	room = new Room(8);
	robby = new Robot();
	picture = new GraphicsManager(room, robby);

	picture->draw();

	//Endless while loop.
	while (i < 1)
	{
		//If there is an obstacle in front of robby.
		if (robby->obstacle_ahead(room))
		{
			RobbyDir(2);
			std::cout << "Condition 1" << std::endl;
		}
		//While there is a black or blue wall to the left of robby and no obstacles in front of him.
		while (LeftCheck() && !robby->obstacle_ahead(room))
		{
			RobbyMove();
		}

		//When there is no wall to robby's left or obstacles in front of him.
		if (!robby->obstacle_ahead(room) && !LeftCheck())
		{
			RobbyDir(1);
			RobbyMove();
		}
	}
}