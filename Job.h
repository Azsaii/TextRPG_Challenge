#pragma once
#include <string>
#include <string_view>
#include "Character.h"

constexpr std::string_view WARRIOR_ATTACK = "* Swings sword!\n";
constexpr std::string_view MAGE_ATTACK = "* Fires a fireball!\n";
constexpr std::string_view ROGUE_ATTACK = "* Stabs dagger!\n";
constexpr std::string_view ARCHER_ATTACK = "* Shoots arrow!\n";

enum JobName {
	WARRIOR,
	MAGE,
	ROGUE,
	ARCHER,
};

class Job {
public:
	JobName _jobName;
	unsigned __int32 _attackCount;
	
	virtual void JobAttackProc(unsigned __int32 attackPower, Character* target) = 0;
	virtual ~Job() = default;
	
	std::string GetJobName();
};
