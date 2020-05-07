#pragma once
#include <time.h>
#include <stdlib.h>

class ThrowCheck
{
private:


public:
	ThrowCheck();
	~ThrowCheck();

	int throwBull(int p);
	int throwTreble(int d, int p);
	int throwDouble(int d);
	int throwSingle(int d);
};

