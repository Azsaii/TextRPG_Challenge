#pragma once
#include "Job.h"
#include "Inventory.h"

class Player: public Character {

private:
	unsigned __int32 _statLimit = 1000;
	
public:
	Player();
	~Player();

	unsigned __int32 _hp_potion;
	unsigned __int32 _mp_potion;

	unsigned __int32 _exp;
	unsigned __int32 _maxExp;

	unsigned __int32 _LevelUpHpAdd;
	unsigned __int32 _LevelUpMpAdd;
	unsigned __int32 _LevelUpAttackPowerAdd;
	unsigned __int32 _LevelUpDefenceAdd;

	Job* _job;
	Inventory<Item> _inventory;

	void CreateCharacter(void);
	void PrintStatus(void) const;
	void StatusUpgrade(void);
	void JobSelection(void);
	bool AddExp(unsigned __int32);

	ItemName GetItemNameByIndex(unsigned __int32);
	void UseItem(ItemName itemName);
};