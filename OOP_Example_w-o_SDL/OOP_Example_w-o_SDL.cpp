// OOP_example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Game.h"

void ScoreDisplay(Game &G)//that function has acces to private members of Game class
{
	if (G.win)
	{
		std::cout << "\n\n\t you won! ";
	}
	else
	{
		std::cout << "\n\n\t you lose! ";
	}
	std::cout << "with score of " << G.score;
	std::cout << "\n\n\ ";
};

int main()
{
	//   Cleric* C = new Cleric();
	srand(time(NULL));
	Game* G = new Game();
	while (G->keepGoing)
	{
		G->PlayATurn();
	}
	ScoreDisplay(*G);
	G->~Game(); //needed to call deconstructor cuz of dynamic object
}