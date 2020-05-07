#include "Game.h"

//This will run the game, and find the victor.
Game::Game()
{
	initialSetup();
}

Game::~Game()
{

}

void Game::initialSetup()
{
	sid = new Player("Sid", 71);
	joe = new Player("Joe", 73);

	gameOver = false;
	roundOver = false;
	noOfSims = 0;
	for (int i = 0; i < 14; i++)
	{
		winPercentages[i] = 0;
		gameScores[i] = 0;
	}

	//This will be used to check who goes first, false = Sid, true = Joe.
	goesFirst = false;
}

//Function that will run all the simulations.
void Game::play(int noOfSims)
{
	this->noOfSims = noOfSims;

	for (int i = 0; i < noOfSims; i++)
	{
		while (joe->getSetWins() < 7 && sid->getSetWins() < 7)
		{
			while (joe->getRoundWins() < 3 && sid->getRoundWins() < 3)
			{
				playOrder(goesFirst);

				if (roundOver)
				{
					joe->resetScore();
					sid->resetScore();
					roundOver = false;
					goesFirst = !goesFirst;
				}
			}

			if (joe->getRoundWins() > sid->getRoundWins())
			{
				joe->setWin();
			}
			else sid->setWin();

			joe->resetRoundWins();
			sid->resetRoundWins();
		}

		if (joe->getSetWins() > sid->getSetWins())
		{
			joe->gameWin();
		}
		else sid->gameWin();

		scoreKeeper(joe->getSetWins(), sid->getSetWins());
		joe->resetSetWins();
		sid->resetSetWins();
	}
	
	calculateWinPercentages();
	gameOver = true;
}

//Function for a players turn.
void Game::takeTurn(Player* p)
{
	int startingScore = p->getScore();

	while (p->getNoOfDarts() > 0 && !roundOver)
	{
		p->useDart();

		// 61 is cutoff point where a treble 20 would lose the game.
		if (p->getScore() > 61)
		{
			p->subtractScore(dart.throwTreble(20, p->getHitChance()));
		}

		else
		{	// Make sure the players score is even.
			if (p->getScore() % 2 == 0 && p->getScore() != 0) 
			{
				//Try get to 50 for bull throw.
				if (p->getScore() > 50)
				{
					p->subtractScore(dart.throwSingle(p->getScore() - 50));
				}
				else if (p->getScore() == 50)
				{
					p->subtractScore(dart.throwBull(p->getHitChance()));
				}
				else
				{
					// Try to line up for a double for the win
					if (p->getScore() > 40)
					{
						p->subtractScore(dart.throwSingle(p->getScore() - 40));

					}
					else
					{
						p->subtractScore(dart.throwDouble(p->getScore() / 2));
					}
				}
			}
			else
			{
				p->subtractScore(dart.throwSingle(1));
			}
		}

		if (p->getScore() == 1 || p->getScore() < 0)
		{
			p->setScore(startingScore);
		}

		else if (p->getScore() == 0)
		{
			p->roundWin();
			roundOver = true;
		}
	}
	p->resetDarts();
}

void Game::playOrder(bool b)
{
	if (!b)
	{
		takeTurn(sid);
		takeTurn(joe);
	}
	else
	{
		takeTurn(joe);
		takeTurn(sid);
	}
}

void Game::scoreKeeper(int p1, int p2)
{
	if (p2 == 7)
	{
		switch (p1)
		{
		case(6): // 6:7
			gameScores[0]++;
			break;
		case(5): // 5:7
			gameScores[1]++;
			break;
		case(4): // 4:7
			gameScores[2]++;
			break;
		case(3): // 3:7
			gameScores[3]++;
			break;
		case(2): // 2:7
			gameScores[4]++;
			break;
		case(1): // 1:7
			gameScores[5]++;
			break;
		case(0): // 0:7
			gameScores[6]++;
			break;
		}
	}

	else
	{
		switch (p2)
		{
		case(0): // 7:0
			gameScores[7]++;
			break;
		case(1): // 7:1
			gameScores[8]++;
			break;
		case(2): // 7:2
			gameScores[9]++;
			break;
		case(3): // 7:3
			gameScores[10]++;
			break;
		case(4): // 7:4
			gameScores[11]++;
			break;
		case(5): // 7:5
			gameScores[12]++;
			break;
		case(6): // 7:6
			gameScores[13]++;
			break;
		}
	}
}

void Game::calculateWinPercentages()
{
	for (int i = 0; i < 14; i++)
	{
		winPercentages[i] = (gameScores[i] / noOfSims) * 100.f;
	}
}

void Game::setGameOver(bool b)
{
	this->gameOver = b;
}

bool Game::getGameOver()
{
	return this->gameOver;
}

std::string Game::getWinnerName()
{
	if (joe->getGameWins() > sid->getGameWins())
	{
		return joe->getName();
	}
	else return sid->getName();
}

Player* Game::getJoe()
{
	return joe;
}

Player* Game::getSid()
{
	return sid;
}

float* Game::getWinFequency()
{
	return winPercentages;
}