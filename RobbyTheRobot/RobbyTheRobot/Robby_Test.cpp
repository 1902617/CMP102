// Going to try and get the basic methods/layout for my robby the robot program in CMP104 practical
#include <iostream>
#include "GraphicsManager.h"

using namespace std;

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

bool RobbyCheck()
{
	robby->left();
	//replace 1 with whatever colour 
	if (robby->ahead_is_colour(room, 1) == true)
		return true;
	else
	{
		robby->right();
		return false;
	}
}

int main()
{
	room = new Room(6);
	robby = new Robot();	
	picture = new GraphicsManager(room, robby);

	picture->draw();

	// Replace 3 with whatever colour corresponds to the green tile
	while (robby->ahead_is_colour(room, 3) != true)
	{
		while (RobbyCheck() == false)
		{

		}

	}
	system("Pause");
	return 0;
}