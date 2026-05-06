#pragma once
#include "Player.h"
#include "Dungeon.h"
#include "PotionShop.h"

class GameManager {
private:
	static GameManager* _instance;
	PotionShop _potionShop;
	GameManager();
public:
	
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	~GameManager();

	Player _player;

	std::vector<Dungeon*> _dungeons;
	unsigned __int32 _currentDungeonIndex;

	static GameManager* GetInstance(void);
	void StartPlayerSetting(void);
	void MainMenuProc(void);
	void StartBattle(void);
};