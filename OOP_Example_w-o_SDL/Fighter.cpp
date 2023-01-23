#include "Fighter.h"
Fighter::Fighter()
{
}
Fighter::Fighter(std::string name, unsigned level)
{
	this->level = 1;
	this->name = name;
	maxhealth = 30;
	health = 30;
	maxDMG = 8;
	DMG = 8;
	maxmeleeDEF = 8;
	maxmagicDEF = 1;
	meleeDEF = 8;
	magicDEF = 1;

	wounded = false;

	while (this->level < level)
	{
		LevelUP();
	}
}
Fighter::~Fighter()
{
}
void Fighter::LevelUP()
{
	maxhealth += rand() % (level + 5) + 2 * level;
	maxmagicDEF += rand() % level + 5;
	maxmeleeDEF += rand() % level + 2;
	maxDMG += rand() % (level + 5) + level;
	ResetStats();
	level++;
};
/*
void Fighter::LevelUP()
{
	std::cout << health<<"\n";
	health = +20;
};*/