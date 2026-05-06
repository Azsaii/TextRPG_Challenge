#pragma once
#include "Job.h"

class JobWarrior : public Job {
public:
	JobWarrior();
	virtual void JobAttackProc(unsigned __int32 attackPower, Character* target);
};