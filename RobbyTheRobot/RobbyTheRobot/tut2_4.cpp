#include "GraphicsManager.h"
#include <iostream>

//Pointer reference to classes
Room* room;
Robot* robby;
GraphicsManager* picture;

int main()
{//create the objects
	room = new Room(2);
	robby = new Robot();
	picture = new GraphicsManager(room, robby);

	//Forward 5
	for (int i = 0; i < 5; i++) {
		robby->move();
		picture->draw();
	}

	//Right 7
	robby->right();
	picture->draw();
	for (int j = 0; j < 7; j++) {
		robby->move();
		picture->draw();
	}

	//Left 6
	robby->left();
	picture->draw();
	for (int j = 0; j < 6; j++) {
		robby->move();
		picture->draw();
	}

	//right 3
	robby->right();
	picture->draw();
	for (int j = 0; j < 3; j++) {
		robby->move();
		picture->draw();
	}

	//right 1
	robby->right();
	picture->draw();
	for (int j = 0; j < 1; j++) {
		robby->move();
		picture->draw();
	}





	//we need the system pause command so that we can see where Robby ends up
	system("Pause");
}