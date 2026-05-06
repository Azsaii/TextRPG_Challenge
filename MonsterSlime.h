#pragma once
#include "Monster.h"

class MonsterSlime : public Monster {
public:
	MonsterSlime();

	virtual void MonsterAttackProc(void);
};