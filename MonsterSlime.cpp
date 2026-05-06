#include <iostream>
#include "MonsterSlime.h"

MonsterSlime::MonsterSlime() {
	_hp = 100;
	_maxHp = 100;
	_attackPower = 70;
	_defence = 10;
	_name = "Slime";
	_expReward = 50;

	_dropItem = Item::MakeItem(SLIME_JELLY);
}

void MonsterSlime::MonsterAttackProc(void) {
	
}