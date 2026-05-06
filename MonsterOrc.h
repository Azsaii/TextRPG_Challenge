#pragma once
#include "Monster.h"

class MonsterOrc : public Monster {
public:
	MonsterOrc();

	virtual void MonsterAttackProc(void);
};