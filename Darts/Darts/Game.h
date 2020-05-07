#pragma once
#include "ThrowCheck.h"
#include "Player.h"

class Game
{
private:
	Player* sid, * joe;
	ThrowCheck dart;

	bool gameOver, roundOver, goesFirst;


public:
	Game();
	~Game();

	void play(int noOfSims);
	void takeTurn(Player* p);
	void playOrder(bool b);

	void setGameOver(bool b);

	bool getGameOver();
	Player* getWinner();
};