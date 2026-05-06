#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Monster.h"

struct DungeonRoom {
	Monster* _monster;

	DungeonRoom(Monster* monster) : _monster(monster){}
};

class Dungeon {
public:

	__int32 _maxFloor;
	__int32 _clearCnt;
	std::string _dungeonName;
	std::vector<DungeonRoom> _rooms;

	Dungeon(__int32 monsterCnt, std::string dungeonName, std::vector<MonsterType> types);
	~Dungeon();
};