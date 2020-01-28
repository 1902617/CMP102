#include "MyRobot.h"
#include "Robot.h"
#include "GraphicsManager.h"

void MyRobot::move(int n)
{
	for (int i = 0; i <= n; i++)
	{
		Robot::move();
	}
}

void MyRobot::back()
{
	if (Robot::get_dir() == (0 || 1))
	{	
		invBackDir = get_dir();
		backDir = get_dir() + 2;
	}

	else if(Robot::get_dir() == (2 || 3))
	{
		invBackDir = get_dir();
		backDir = get_dir() - 2;
	}

	else
	{
		"Error in back()";
	}

	Robot::setDirection(backDir);
	Robot::move();
	Robot::setDirection(invBackDir);
}

void MyRobot::goTo(int x, int y, GraphicsManager* pic)
{
	currX = Robot::get_xpos();
	currY = Robot::get_ypos();

	// Solving for X
	if (currX > x)
	{
		Robot::setDirection(3);
		for (int i = currX; i > x; i--)
		{
			Robot::move();
			pic->draw();
		}
	}
	else if (currX < x)
	{
		Robot::setDirection(1);
		for (int i = currX; i < x; i++)
		{
			Robot::move();
			pic->draw();
		}
	}

	// Solving for Y
	if (currY > y)
	{
		Robot::setDirection(0);
		for (int i = currY; i > y; i--)
		{
			Robot::move();
			pic->draw();
		}
	}

	else if (currY < y)
	{
		Robot::setDirection(2);
		for (int i = currY; i < y; i++)
		{
			Robot::move();
			pic->draw();
		}
	}
}

void MyRobot::teleport(int x, int y, GraphicsManager* pic)
{
	std::cout << "Robby Channeling Teleport..." << std::endl;;
	for (int i = 0; i < 8; i++)
	{
		Robot::left();
		pic->draw();
	}
	Robot::setX(x);
	Robot::setY(y);
	pic->draw();
	std::cout << "ROBBY HAS ARRIVED!" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl;
	}
}

void MyRobot::anotherLogOnTheFire()
{
	std::cout << "PUT ANOTHER LOG ON THE FIRE!" << std::endl;
	std::cout << "BAKE ME UP SOME BACON AND SOME BEANS!" << std::endl;
}