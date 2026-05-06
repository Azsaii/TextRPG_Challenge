#include <iostream>
#include "MonsterOrc.h"

MonsterOrc::MonsterOrc() {
	_hp = 350;
	_maxHp = 350;
	_attackPower = 130;
	_defence = 100;
	_name = "Orc";
	_expReward = 100;

	_dropItem = Item::MakeItem(ORC_LEATHER);
}

void MonsterOrc::MonsterAttackProc(void) {

}