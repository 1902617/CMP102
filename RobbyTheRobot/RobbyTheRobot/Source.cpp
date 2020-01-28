#include <iostream>
#include "GraphicsManager.h"	
#include "Robot.h"
#include "MyRobot.h"

//Creating Objects

Room* room;
MyRobot* BigRobby;
GraphicsManager* picture;

int main()
{
	// Initialising Objects
	room = new Room(0);
	BigRobby = new MyRobot();
	picture = new GraphicsManager(room, BigRobby);


	BigRobby->move(4);
	BigRobby->right();
	BigRobby->move(4);

	picture->draw();
	BigRobby->back();
	picture->draw();

	BigRobby->teleport(5, 5, picture);
	BigRobby->goTo(10, 15, picture);

	system("Pause");
}