#include "Character.h"

Character::Character(std::string name, int level)
{
	//	this->level = level;
	this->level = 1;
	this->name = name;
	maxhealth = 20;
	health = 20;
	maxDMG = 5;
	DMG = 5;

	maxmeleeDEF = 2;
	maxmagicDEF = 2;

	meleeDEF = 2;
	magicDEF = 2;
	wounded = false;

	while (this->level < level)//simulate leveling 1lvl at once
	{
		LevelUP();
	}
};

Character::Character()
{
	level = 1;
	maxhealth = 20;
	health = 20;
	maxDMG = 5;
	DMG = 5;

	maxmeleeDEF = 2;
	maxmagicDEF = 2;

	meleeDEF = 2;
	magicDEF = 2;

};

Character::~Character()
{
}

bool Character::Attack(Character& Target)
{

	int tmpDMG = DMG;// needed to recalculate dmg and add option to crittically succes/fail
	switch (rand() % 19)
	{
	case 19:// D20 crit  hit 20
	{
		tmpDMG = ceil(DMG * 1.5);
		break;
	}
	case 0: // D20 crit miss 0
	{
		tmpDMG = floor(DMG / 2);
		break;
	}
	}
	int healthTMP = Target.getHealth(); //take target's health

	Target.GetHit(tmpDMG, physic);//apply dmg to target
	//TODO delete below after adding sprits and sdl window

	if (healthTMP != Target.getHealth())
	{
		std::cout << "\t" << name << " lowered " << Target.name << "'s health from " << healthTMP << " to " << Target.getHealth() << std::endl;
	}
	else
	{
		std::cout << "\t" << name << " waged attack against " << Target.name << " but armor was too strong" << std::endl;
	}

	if (Target.health > 0)//checking if target died
	{
		return true;
	}
	std::cout << "  " << Target.name << " has died \n";
	return false;
	//	Target.GetHit(tmpDMG,physic);
};

void Character::GetHit(int dmg, dmgtype type)
{
	//take flat dmg, apply armor and other defence, set wounded flag if needed 

	if (type == physic)
	{
		if (dmg - meleeDEF > 0)
		{
			health -= dmg - meleeDEF;
			wounded = true;
		}
	}
	else if (type == magic)
	{
		if (dmg - magicDEF > 0)
		{
			health -= dmg - magicDEF;
			wounded = true;
		}
	}
	// chceck if health didnt went on negative value

	if (health < 0)
	{
		health = 0;
	}

};

void Character::LevelUP()
{
	maxhealth += rand() % (level + 5) + 5 + level;
	maxmagicDEF += rand() % level + 5;
	maxmeleeDEF += rand() % level + 2;
	maxDMG += rand() % (level + 5) + 5;
	level++;
	ResetStats();// setting actual stats to max limits
};

void Character::ResetStats()
{
	health = maxhealth;
	ResetBuffs();
};

void Character::ResetBuffs()
{
	meleeDEF = maxmeleeDEF;
	DMG = maxDMG;
	magicDEF = magicDEF;
};

void Character::DecreaseDMG(int howMuch)
{
	DMG -= howMuch;
	if (DMG < 3) DMG = 3;// to characters didn't end useless
};
void Character::DecreaseDEF(int howMuch)
{
	magicDEF -= howMuch;
	if (magicDEF < 1) magicDEF = 1;// to characters didn't end too vulnurable
	DMG -= howMuch;
	if (DMG < 1) DMG = 1;// to characters didn't end useless
};