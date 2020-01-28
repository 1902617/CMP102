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

	//make robby move forward two squares, and draw it
	robby->move();
	picture->draw(); // 1

	robby->move();
	picture->draw(); // 2

	robby->move();
	picture->draw(); // 3

	robby->move();
	picture->draw(); // 4

	robby->move();
	picture->draw(); // 5

	//make robby turn right and draw it
	robby->right();
	picture->draw();

	//Move robby 5 spaces
	robby->move();
	picture->draw(); // 1

	robby->move();
	picture->draw(); // 2

	robby->move();
	picture->draw(); // 3

	robby->move();
	picture->draw(); // 4

	robby->move();
	picture->draw(); // 5

	//we need the system pause command so that we can see where Robby ends up
	system("Pause");
}