#pragma once
#include "pch.h"

enum dmgtype
{
	physic = 0,
	magic = 1,
};


class CharacterInterface
{
public:
	virtual void ResetStats() = 0;
	virtual void LevelUP() = 0;
	virtual void GetHit(int, dmgtype) = 0;

};

