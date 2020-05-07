#include "Line.h"

//Basic class for displaying information to the console easily.
Line::Line(std::string text)
{
	this->text = text;
	this->text.append("\n");
	active = true;
}

Line::~Line()
{

}

void Line::setText(std::string text)
{
	this->text = text;
	this->text.append("\n");
}

void Line::setActive(bool b)
{
	this->active = b;
}

std::string Line::getText()
{
	return this->text;
}

bool Line::getActive()
{
	return this->active;
}