#include "GraphicsManager.h"
#include <iostream>

//Pointer reference to classes
Room* room;
Robot* robby;
GraphicsManager* picture;

int main()
{//create the objects
	room = new Room(0);
	robby = new Robot();
	picture = new GraphicsManager(room, robby);

	//Robby will move forward till he encounters an obstacle
	while (!robby->obstacle_ahead(room))
	{
		robby->move();
		picture->draw();
	}

	//we need the system pause command so that we can see where Robby ends up
	system("Pause");
}