#include "Game.h"

#include <iostream>
//This will run the game, and find the victor.
Game::Game()
{
	sid = new Player("Sid", 71);
	joe = new Player("Joe", 73);

	gameOver = false;
	roundOver = false;

	//This will be used to check who goes first, false = Sid, true = Joe.
	goesFirst = false;
}

Game::~Game()
{

}

void Game::play(int noOfSims)
{
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

		joe->resetSetWins();
		sid->resetSetWins();
	}

	std::cout << "Joe Wins: " + std::to_string(joe->getGameWins()) + "\n";
	std::cout << "Sid Wins: " + std::to_string(sid->getGameWins()) + "\n";
	gameOver = true;
	system("pause");
}

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
		{
			if (p->getScore() % 2 == 0 && p->getScore() != 0) // Make sure the players score is even.
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

void Game::setGameOver(bool b)
{
	this->gameOver = b;
}

bool Game::getGameOver()
{
	return this->gameOver;
}
