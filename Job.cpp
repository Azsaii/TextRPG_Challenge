#include "Job.h"

std::string Job::GetJobName() {
	switch (_jobName)
	{
	case WARRIOR: return "Warrior";
	case MAGE: return "Mage";
	case ROGUE: return "Rogue";
	case ARCHER: return "Archer";
	}

	return "InvalidJobName";
}