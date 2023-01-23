#pragma once
#include "Cleric.h"

class Game
{
	unsigned int roomsLEFT;// game can't go forever
	unsigned int turn;// if game's during turn or other part of game
	unsigned int charactersLevel;//level of PC, on it depends enemies' level
	unsigned int sizeOfTeam;
	unsigned int sizeOfEnemyTeam;// how mamy enemies, depends of player team's size
	unsigned int TurnsUntilLevelUP;//  how many rooms till PC's level up
	
	std::vector<Character> EnemyTeam;
	std::vector<Fighter> PlayerTeam;
	Cleric* PlayersCleric;// only character controlled by player TODO

	void PlayerTeamAttack();
	void EnemyTeamAttack();
	void LevelUP();

	void DoPC_Turn();// now it only make cleric-type character paly their turn

public:
	bool keepGoing; // if game should keep going or end
	int score;
	bool win;//need to be paired with keepGoing variable

	Game();
	~Game();
	void PrepareRoom();//spawn enemy team
	void PlayATurn();//process with characters actions
	void EmptyTeams();//delete ALL teams

	friend void ScoreDisplay(Game&);//that function can be called outside of class and has accces to private members of object given on input
};
