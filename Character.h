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

	std::string _name;
};