#include <iostream>
#include "JobMage.h"

using namespace std;

JobMage::JobMage() {
	_jobName = MAGE;
	_attackCount = 1;
}

void JobMage::JobAttackProc(unsigned __int32 attackPower, Character* target) {
	cout << MAGE_ATTACK;
	__int32 damageEach = (attackPower - target->_defence) / _attackCount;
	if (damageEach < 0) damageEach = 1;

	__int32 damageTotal = damageEach * _attackCount;
	__int32 prevHp = target->_hp;

	if (prevHp - damageTotal < 0) {
		target->_hp = 0;
	}
	else target->_hp -= damageTotal;

	cout << damageEach << " damage to " << target->_name;
	if (_attackCount == 1) cout << "!\n";
	else cout << "! (x" << _attackCount << ")\n";

	cout << target->_name << " HP: " << prevHp << " -> " << target->_hp;
}