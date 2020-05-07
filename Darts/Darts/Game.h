#pragma once
#include "ThrowCheck.h"
#include "Player.h"

class Game
{
private:
	Player* sid, * joe;
	ThrowCheck dart;

	bool gameOver, roundOver, goesFirst;
	float gameScores[14], noOfSims;
	float winPercentages[14];

public:
	Game();
	~Game();

	void initialSetup();
	void play(int noOfSims);
	void takeTurn(Player* p);
	void playOrder(bool b);
	void scoreKeeper(int p1, int p2);
	void calculateWinPercentages();

	void setGameOver(bool b);

	bool getGameOver();
	std::string getWinnerName();
	Player* getJoe();
	Player* getSid();
	float* getWinFequency();
};