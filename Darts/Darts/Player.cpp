#include "Player.h"

Player::Player(std::string name, int chance)
{
	this->name = name;
	this->hitChance = chance;
	score = 501;
	noOfDarts = 3;
	roundWins = 0;
	setWins = 0;
	gameWins = 0;
}

Player::~Player()
{

}

void Player::resetRoundWins()
{
	roundWins = 0;
}

void Player::resetSetWins()
{
	setWins = 0;
}

void Player::resetGameWins()
{
	gameWins = 0;
}

void Player::resetScore()
{
	score = 501;
}

void Player::roundWin()
{
	roundWins++;
}

void Player::setWin()
{
	setWins++;
}

void Player::gameWin()
{
	gameWins++;
}

void Player::subtractScore(int x)
{
	score -= x;
}

void Player::useDart()
{
	noOfDarts--;
}

void Player::resetDarts()
{
	noOfDarts = 3;
}

//Setters
void Player::setHitChance(int chance)
{
	this->hitChance = chance;
}

void Player::setScore(int score)
{
	this->score = score;
}


//Getters
int Player::getHitChance()
{
	return this->hitChance;
}

int Player::getRoundWins()
{
	return this->roundWins;
}

int Player::getSetWins()
{
	return this->setWins;
}

int Player::getGameWins()
{
	return this->gameWins;
}

int Player::getScore()
{
	return this->score;
}

std::string Player::getName()
{
	return this->name;
}

int Player::getNoOfDarts()
{
	return this->noOfDarts;
}