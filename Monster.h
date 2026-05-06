#pragma once
#include "Character.h"

enum MonsterType {
	SLIME,
	GOBLIN,
	ORC,
	DRAGON,
};

class Monster : public Character {
public:

	unsigned __int32 _expReward;
	Item* _dropItem;

	virtual void MonsterAttackProc(void) = 0;
	bool AttackTarget(Character* target);
};