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


	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 17; j++) {
			robby->move();
			picture->draw();
		}

		robby->right();
		picture->draw();
	}

	//we need the system pause command so that we can see where Robby ends up
	system("Pause");
}