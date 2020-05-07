#pragma once
#include <iostream>
#include <vector>

#include "Line.h"

class UserInterface
{
private:
	std::vector<Line*> display;
	int currentDisplaySize;
	bool mode;

public:
	UserInterface();
	~UserInterface();

	void initialSetup();
	void draw();
	void addLine(std::string str);
	void switchMode(bool b);
	void reset();
};

