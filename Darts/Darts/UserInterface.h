#pragma once
#include <iostream>
#include <vector>

#include "Line.h"

class UserInterface
{
private:
	std::vector<Line*> display;
	int initialDisplaySize;
	bool mode;

public:
	UserInterface();
	~UserInterface();

	void draw();
	void addLine(std::string str);
	void switchMode(bool b);
	void reset();
};

