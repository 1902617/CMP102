// Going to try and get the basic methods/layout for my robby the robot program in CMP104 practical
#include <iostream>
#include "GraphicsManager.h"

using namespace std;

Room* room;
Robot* robby;
GraphicsManager* picture;

void robby_move()
{
	robby->move();
	picture->draw();
}

void robby_dir(int dir)
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

int main()
{
	room = new Room(6);
	robby = new Robot();
	picture = new GraphicsManager(room, robby);

	int const noOfTasks = 11;
	int robbyMove[noOfTasks] = { 3,7,3,2,4,2,3,3,7,4,3 };
	int robbyDir[noOfTasks] = { 0,2,1,1,2,1,1,2,2,2,1 };

	for (int i = 0; i < noOfTasks; i++)
	{
		robby_dir(robbyDir[i]);

		for (int j = 0; j < robbyMove[i]; j++)
		{
			robby_move();
		}
	}

	system("Pause");
	return 0;
}