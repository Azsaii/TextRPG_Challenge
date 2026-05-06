#pragma once
#include "Job.h"

class JobMage : public Job {
public:
	JobMage();
	virtual void JobAttackProc(unsigned __int32 attackPower, Character* target);
};