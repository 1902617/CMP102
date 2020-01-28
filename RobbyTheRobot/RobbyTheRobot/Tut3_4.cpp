#include "GraphicsManager.h"

//Pointer reference to classes
Room* room;
Robot* robby;
GraphicsManager* picture;

int main()
{//create the objects
	room = new Room(3);
	robby = new Robot();
	picture = new GraphicsManager(room, robby);
	picture->draw();

	//Robby will move forward till he encounters an obstacle
	do
	{
		robby->move();
		picture->draw();
	} while (!robby->obstacle_ahead(room));

	//we need the system pause command so that we can see where Robby ends up
	system("Pause");
}