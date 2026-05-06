#include <iostream>
#include "Monster.h"

using namespace std;

bool Monster::AttackTarget(Character* target) {

	__int32 damage = _attackPower - target->_defence;
	if (damage <= 0) damage = 1;

	__int32 prevHp = target->_hp;

	if (target->_hp - damage < 0) {
		target->_hp = 0;
	}
	else target->_hp -= damage;

	cout << "* " << _name << " is attacking!\n";
	cout << damage << " damage to " << target->_name << "!\n";
	cout << target->_name << " HP: " << prevHp << " -> " << target->_hp;

	bool targetIsDead = false;
	if (target->_hp == 0) {
		cout << " (Dead)";
		targetIsDead = true;
	}

	cout << "\n\n";
	return targetIsDead;
}