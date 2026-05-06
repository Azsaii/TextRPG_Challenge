#pragma once
#include <string>
#include "ItemDefine.h"

class Character {
public:
	__int32 _hp;
	__int32 _maxHp;
	__int32 _mp;
	__int32 _maxMp;
	unsigned __int32 _attackPower;
	unsigned __int32 _defence;
	unsigned __int32 _level;

	Character() : _hp(0), _maxHp(0), _mp(0), _maxMp(0), _attackPower(0), _defence(0), _level(0){}

	std::string _name;
};