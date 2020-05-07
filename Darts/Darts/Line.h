#pragma once
#include <string>

class Line
{
private:
	bool active;
	std::string text;

public:

	Line(std::string text);
	~Line();

	void setText(std::string text);
	void setActive(bool b);

	std::string getText();
	bool getActive();
};

