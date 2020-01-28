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
	
	int task_Counter = 0;

	picture->draw();
	robby->right();
	picture->draw();

	for (int i = 0; i < 4; i++)
	{
		while (!robby->obstacle_ahead(room))
		{
			robby->move();
			picture->draw();
		}

		if (task_Counter == 0)
		{
			std::cout << "Robby Reached the south-east corner!" << std::endl;
		}
		else if (task_Counter == 1)
		{
			std::cout << "Robby Reached the north-east corner!" << std::endl;
		}
		else if (task_Counter == 2)
		{
			std::cout << "Robby Reached the north-west corner!" << std::endl;
		}
		else 
		{
			std::cout << "Robby reached the start!" << std::endl;
		}

		task_Counter++;
		robby->left();
	}
	robby->left();
	picture->draw();

	//we need the system pause command so that we can see where Robby ends up
	system("Pause");
}