#include <iostream>
#include "GraphicsManager.h"	

//Ignore this!!
Room* room;
Robot* robby;
GraphicsManager* picture;
//

int main()
{
	//declare the room, robby and picture objects here
	room = new Room(0);
	robby = new Robot();
	picture = new GraphicsManager(room, robby);


	robby->move();
	picture->draw();


	//we need system pause so that we can see where robby ends up
	system("Pause");
}