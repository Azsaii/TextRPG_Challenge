#pragma once
#include "Job.h"

class JobRogue : public Job {
public:
	JobRogue();
	virtual void JobAttackProc(unsigned __int32 attackPower, Character* target);
};