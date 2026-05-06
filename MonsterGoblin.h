#pragma once
#include "Monster.h"

class MonsterGoblin : public Monster {
public:
	MonsterGoblin();

	virtual void MonsterAttackProc(void);
};