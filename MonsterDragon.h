#pragma once
#include "Monster.h"

class MonsterDragon : public Monster {
public:
	MonsterDragon();

	virtual void MonsterAttackProc(void);
};