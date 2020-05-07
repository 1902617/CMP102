#pragma once
#include <string>

class Player
{
private:
	int hitChance, score, noOfDarts, roundWins, setWins, gameWins;
	std::string name;

public:
	Player(std::string name, int chance);
	~Player();

	void resetRoundWins();
	void resetSetWins();
	void resetGameWins();
	void resetScore();
	void roundWin();
	void setWin();
	void gameWin();
	void subtractScore(int chance);
	void useDart();
	void resetDarts();

	void setHitChance(int x);
	void setScore(int score);

	int getHitChance();
	int getRoundWins();
	int getSetWins();
	int getGameWins();
	int getScore();
	std::string getName();
	int getNoOfDarts();

};

