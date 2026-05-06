#include <iostream>
#include "MonsterGoblin.h"

MonsterGoblin::MonsterGoblin() {
	_hp = 200;
	_maxHp = 200;
	_attackPower = 100;
	_defence = 50;
	_name = "Goblin";
	_expReward = 70;

	_dropItem = Item::MakeItem(GOBLIN_EAR);
}

void MonsterGoblin::MonsterAttackProc(void) {
	
}