#pragma once
#include "Job.h"

class JobArcher : public Job {
public:
	JobArcher();
	virtual void JobAttackProc(unsigned __int32 attackPower, Character* target);
};