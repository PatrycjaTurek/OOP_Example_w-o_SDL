#include "Cleric.h"

void Cleric::ResetStats()
{
	ResetBuffs();
	health = maxhealth;
	mana = maxMana;
};



Cleric::Cleric(std::string name, unsigned level)
{
	this->name = name;
	this->level = level;
	maxhealth = 15;
	health = 15;
	maxDMG = 2;
	DMG = 2;

	maxmeleeDEF = 2;
	maxmagicDEF = 8;

	meleeDEF = 2;
	magicDEF = 8;

	maxMana = 10;
	mana = 10;

	wounded = false;

	while (this->level < level)
	{
		LevelUP();
	}
}

Cleric::Cleric()
{

};

Cleric::~Cleric()
{

};

void Cleric::Heal(Fighter& Target)
{
	mana -= 5;
	if (mana < 0)
	{
		Target.health += ceil( (rand() % 5 + level) * mana / ( -5 )); // heal proportional to used mana
		mana = 0;
	}
	else
	{
		Target.health += rand() % 5 + level;
	}


	//checing if overheal would occur
	if (Target.maxhealth <= Target.health)
	{
		Target.health = Target.maxhealth; //if yes set health to max value
		wounded = false;// character is no longer hurt
	}

	std::cout << "\t Cleric healed " << Target.name << " to " << Target.health << std::endl;
};

bool Cleric::Attack(Character& Target)
{
	if (mana < 5)
	{
		return Pray(Target);
	}
	mana -= 3;
	//cleric's pacifists so no dmg, debuff instead
	std::cout << "\t Cleric debuffed " << Target.name;
	if (rand() % 2)
	{
		Target.DecreaseDMG(level);
		std::cout << " damage \n ";
	}
	else
	{
		Target.DecreaseDEF(level);
		std::cout << " defence \n ";
	}
	return false;
};
bool Cleric::Attack(Character& Target, Character& Target2)
{
	if (mana < 5)
	{
		return Pray(Target);
	}

	Target.DecreaseDMG(level);
	std::cout << "\t Cleric debuffed " << Target.name << " damage \n ";

	Target.DecreaseDEF(level);
	std::cout << "\t Cleric debuffed " << Target2.name << " defence \n ";

	return false;
}
bool Cleric::Pray(Character& Target)
{
	if (rand() % 20 > 17)
	{
		mana += 2;
		Character* ClericsGOD = new Character("GOD", 15);
		Target.GetHit(ClericsGOD->getDMG(), magic);
		std::cout << "  *GOD's cursed " << Target.name << " and dealt " << ClericsGOD->getDMG() << "*\n ";
		if (Target.getHealth() == 0)
			return true;
	}
	return false;
}

bool Cleric::FindToHeal(std::vector<Fighter>& Teammates)
{
	if (Teammates.empty()) return false;

	int minHP = 10000;//needed to determine lowest halth in team
	int whichOne = -1;// which one of fighter is the most hurted
	int iterator = 0;
	for (auto& tmpF : Teammates)
	{
		if (!wounded)
		{
			continue;
		}
		if (tmpF.health < minHP)
		{
			minHP == tmpF.health;
			whichOne = iterator; //remember who need the heal the most
		}
		iterator++;
	}
	if (whichOne == -1)
	{
		return false;
	}

	Heal(Teammates[whichOne]);
	return true;
};

void Cleric::LevelUP()
{
	maxMana = rand() % (level + 5) + 5;
	maxhealth += rand() % (level + 5) + 5 + level;
	maxmagicDEF += rand() % level + 15;
	maxmeleeDEF += rand() % level + 2;
	level++;
	ResetStats();// setting actual stats to max limits
};