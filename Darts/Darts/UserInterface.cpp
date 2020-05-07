#include "UserInterface.h"

UserInterface::UserInterface()
{
	system("CLS");
	display.push_back(new Line("#######################"));
	display.push_back(new Line("   --- Darts 501 ---"));
	display.push_back(new Line(" "));
	display.push_back(new Line("      - Options - "));
	display.push_back(new Line(" 1 - Run Game "));
	display.push_back(new Line(" 2 - Reset UI"));
	display.push_back(new Line(" 3 - Quit Game "));
	display.push_back(new Line(" "));

	initialDisplaySize = 8;

	// Mode determines what state the ui will be in, true == main menu, false == game menu.
	mode = true;
}

UserInterface::~UserInterface()
{

}

//When called, clear console and display all active lines.
void UserInterface::draw()
{
	system("CLS");
	for (int i = 0; i < display.size(); i++)
	{
		if (display[i]->getActive())
		{
			std::cout << display[i]->getText();
		}
	}
}

//Adds strings to the display string array.
void UserInterface::addLine(std::string str)
{
	display.push_back(new Line(str));
}

//Switch between Main Menu and Game Menu layout.
void UserInterface::switchMode(bool b)
{
	this->mode = b;
	if (!mode)
	{
		reset();
		for (int i = 2; i < display.size(); i++)
		{
			display[i]->setActive(false);
		}
	}
	else
	{
		reset();
		for (int i = 0; i < display.size(); i++)
		{
			display[i]->setActive(true);
		}
	}
}

//Resets the display main menu array to its default.
void UserInterface::reset()
{
	for (int i = display.size(); i > initialDisplaySize; i--)
	{
		display.pop_back();
	}
}