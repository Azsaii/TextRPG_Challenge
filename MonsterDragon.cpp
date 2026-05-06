#include <iostream>
#include "MonsterDragon.h"

MonsterDragon::MonsterDragon() {
	_hp = 500;
	_maxHp = 500;
	_attackPower = 200;
	_defence = 150;
	_name = "Dragon";
	_expReward = 200;

	_dropItem = Item::MakeItem(DRAGON_HEART);
}

void MonsterDragon::MonsterAttackProc(void) {

}