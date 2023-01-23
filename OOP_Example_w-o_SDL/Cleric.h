#pragma once
#include "Fighter.h"
class Cleric : public Character
{
	int maxMana;
	int mana;
	void ResetStats();
	void Heal(Fighter&);
public:
	Cleric();
	~Cleric();
	Cleric(std::string, unsigned);
	bool FindToHeal(std::vector<Fighter>&);
	bool Attack(Character&);
	bool Pray(Character&);//Clerics out of mana and prays that gods intervene, return if targeted enemy has died
	bool Attack(Character&, Character&);
	void LevelUP();
};
