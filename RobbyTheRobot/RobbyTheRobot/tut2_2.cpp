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

	//make robby move forward five squares, and draw it
	for (int i = 0; i < 5; i++) {
		robby->move();
		picture->draw();
	}

	//make robby turn right and draw it
	robby->right();
	picture->draw();

	for (int j = 0; j < 5; j++) {
		robby->move();
		picture->draw();
	}

	//we need the system pause command so that we can see where Robby ends up
	system("Pause");
}