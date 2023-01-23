#pragma once
#include "CharacterInterface.h"
//#include "Item.h"
class Character : public CharacterInterface
{
protected:

	int health;
	int level;
	int maxhealth;

	int maxDMG;
	int maxmeleeDEF;
	int maxmagicDEF;//after de/ -buffing

	bool wounded;//if that character has health < maxhealth

	int DMG;//after de/ -buffing
	int meleeDEF;//after de/ -buffing
	int magicDEF;//after de/ -buffing
	void ResetStats();
	void ResetBuffs();

public:

	Character();
	~Character();
	Character(std::string, int); //making character, take name and level
	int getHealth() { return this->health; }; // return unaccesable variable encapsulation example
	int getDMG() { return this->DMG; }
	bool Attack(Character&); // return true on succesfull attack( or other action)
	void GetHit(int, dmgtype);// calculate result of getting hit, take flat dmg and dmg type
	void LevelUP();// strenght stats and heal up
	void DecreaseDMG(int);// //
	void DecreaseDEF(int);


	std::string name;

	//	void UseItem(Item);
};