#include <iostream>
#include "Player.h"
#include "JobWarrior.h"
#include "JobMage.h"
#include "JobRogue.h"
#include "JobArcher.h"

using namespace std;

Player::Player() {
	_hp_potion = 0;
	_mp_potion = 0;

	_exp = 0;
	_maxExp = 100;
	_job = nullptr;

	_level = 1;
	_LevelUpHpAdd = 10;
	_LevelUpMpAdd = 5;
	_LevelUpAttackPowerAdd = 5;
	_LevelUpDefenceAdd = 10;
}

Player::~Player() {
	if(_job != nullptr) delete _job;
}

void Player::CreateCharacter(void) {

	cout << "===========================================\n\t[Dungeon Escape Text RPG]\n===========================================\n";
	
	cout << "Enter your hero's name: ";
	getline(cin, _name);

	unsigned __int32 hp;
	unsigned __int32 mp;
	while (1) {	
		cout << "\nEnter HP and MP: ";

		if (!(cin >> hp >> mp)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input. Try again.\n";
			continue;
		}

		if (hp > 50 && mp > 50 && hp <= _statLimit && mp <= _statLimit) {
			_hp = hp;
			_maxHp = hp;
			_mp = mp;
			_maxMp = mp;
			break;
		}
		else {
			cout << "HP or MP is invalid. Try again.";
		}
	}

	unsigned __int32 JobAttackProc;
	unsigned __int32 defence;
	while (1) {
		cout << "Enter Attack and Defense: ";
		
		if (!(cin >> JobAttackProc >> defence)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input. Try again.\n";
			continue;
		}

		if (JobAttackProc > 50 && defence > 50 && JobAttackProc <= _statLimit && defence <= _statLimit) {
			_attackPower = JobAttackProc;
			_defence = defence;
			break;
		}
		else {
			cout << "Attack or Defense is invalid. Try again.\n";
		}
	}

	cout << "\n\n";
}

void Player::PrintStatus(void) const {

	cout << "\n====================================\n";
	cout << "\t" << _name << " stats\n";
	cout << "====================================\n";
	cout << "HP: " << _hp << "\t\tMP: " << _mp << '\n';
	cout << "Attack: " << _attackPower << "\tDefence: " << _defence << '\n';
	cout << "Level: " << _level << "\tExp: " << _exp << '\n';
	cout << "====================================\n";

	cout << "\n";
}

void Player::StatusUpgrade(void) {

	cout << "* You received 5 HP Potions and 5 MP Potions.\n";

	__int32 in;
	bool loop = true;
	while (loop) {
		cout << "\n============================================\n";
		cout << "< Character Upgrade >\n";
		cout << "1. HP UP\t2. MP UP\t3. Attack  x2\n4. Defense x2\t5. Show Stats\t0. Start Game\n";
		cout << "============================================\n";
		cout << "Choose: ";
		
		if (!(cin >> in)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input. Try again.\n";
			continue;
		}

		switch (in) {
		case 0: {
			cout << "Starting the game!";
			loop = false;

			for (__int32 i = 0; i < _hp_potion; i++) {
				_inventory.AddItem(Item::MakeItem(HP_POTION));
			}
			for (__int32 i = 0; i < _mp_potion; i++) {
				_inventory.AddItem(Item::MakeItem(MP_POTION));
			}
			break;
		}
		case 1: {
			if (_hp_potion == 0) {
				cout << "There's no hp potion!\n";
			}
			else {
				_hp_potion--;
				_hp += 20;
				cout << "* HP increased by 20. ";
				cout << "(HP Potion used: " << _hp_potion << " left)\n";
			}
			
			break;
		}
		case 2: {
			if (_mp_potion == 0) {
				cout << "There's no mp potion!\n";
			}
			else {
				_mp_potion--;
				_mp += 20;
				cout << "* MP increased by 20. ";
				cout << "(MP Potion used: " << _mp_potion << " left)\n";
			}
			
			break;
		}
		case 3: {
			_attackPower *= 2;
			if (_attackPower <= _statLimit) {
				cout << "* Attack increased by x2.\n";
			}
			else {
				_attackPower = _statLimit;
				cout << "* Attack is max!\n";
			}
			cout << "Current Attack: " << _attackPower << '\n';
			
			break;
		}
		case 4: {
			_defence *= 2;
			if (_defence <= _statLimit) {
				cout << "* Defence increased by x2.\n";
			}
			else {
				_defence = _statLimit;
				cout << "* Defence is max!\n";
			}
			cout << "Current Defence: " << _defence << '\n';

			break;
		}
		case 5: {
			PrintStatus();
			break;
		}
		default: {
			cout << "Invalid input.\n";
			break;
		}
		}
	}

	cout << "\n\n";
}

void Player::JobSelection(void) {

	__int32 in;
	bool loop = true;

	while (loop) {
		loop = false;
		cout << "< Job Selection >\n";
		cout << _name << ", choose your job!\n";
		cout << "1. Warrior   2. Mage   3. Rogue   4. Archer\n";
		cout << "Choose: ";
		
		if (!(cin >> in)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input. Try again.\n";
			continue;
		}

		switch (in) {
		case 1: {
			cout << "* You became a Warrior! (HP +30)\n";
			_hp += 30;
			_job = new JobWarrior;
			cout << WARRIOR_ATTACK;
			break;
		}
		case 2: {
			cout << "* You became a Mage! (MP +30)\n";
			_mp += 30;
			_job = new JobMage;
			cout << MAGE_ATTACK;
			break;
		}
		case 3: {
			cout << "* You became a Rogue! (Attack +30)\n";
			_attackPower += 30;
			_job = new JobRogue;
			cout << ROGUE_ATTACK;
			break;
		}
		case 4: {
			cout << "* You became a Archer! (Defence +30)\n";
			_defence += 30;
			_job = new JobArcher;
			cout << ARCHER_ATTACK;
			break;
		}
		default: {
			cout << "Invalid input.\n";
			loop = true;
			break;
		}
		}
	}

	cout << "------------------------------------\n";
	cout << "Name: " << _name << "\tJob: " << _job->GetJobName() << "\tLv." << _level << '\n';
	cout << "HP: " << _hp << "\t\tMP: " << _mp << "\t\tAttack: " << _attackPower << "\tDefense: " << _defence << '\n';
	cout << "------------------------------------\n";
	
	cout << "\n\n";
}

bool Player::AddExp(unsigned __int32 exp) {
	_exp += exp;
	if (_exp >= _maxExp) {
		_level++;
		_exp -= _maxExp;

		_hp += _LevelUpHpAdd;
		_mp += _LevelUpMpAdd;
		_attackPower += _LevelUpAttackPowerAdd;
		_defence += _LevelUpDefenceAdd;

		return true;
	}

	return false;
}

ItemName Player::GetItemNameByIndex(unsigned __int32 index) {
	return _inventory._Items[index]->_name;
}

void Player::UseItem(ItemName itemName) {
	switch (itemName) {
	case HP_POTION: {
		cout << "* HP Potion used! HP restored by 50 (" << _hp << " -> " << _hp + 50 << ")\n";
		_hp += 50;
		_hp_potion--;
		_inventory.RemoveItem(HP_POTION);
		_inventory.AddItem(Item::MakeItem(EMPTY_BOTTLE));
		break;
	}
	case MP_POTION: {
		cout << "* MP Potion used! MP restored by 50 (" << _mp << " -> " << _mp + 50 << ")\n";
		_mp += 50;
		_mp_potion--;
		_inventory.RemoveItem(MP_POTION);
		_inventory.AddItem(Item::MakeItem(EMPTY_BOTTLE));
		break;
	}
	case STAMINA_POTION: {
		cout << "* Stamina Potion used!\n";
		_inventory.RemoveItem(STAMINA_POTION);
		_inventory.AddItem(Item::MakeItem(EMPTY_BOTTLE));
		break;
	}
	default: {
		cout << "* Unavailable Items.\n";
		break;
	}
	}

	cout << "\n\n";
}