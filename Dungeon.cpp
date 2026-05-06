#include "Dungeon.h"
#include "MonsterSlime.h"
#include "MonsterGoblin.h"
#include "MonsterOrc.h"
#include "MonsterDragon.h"

using namespace std;

Dungeon::Dungeon(__int32 monsterCnt, string dungeonName, vector<MonsterType> types) {

	_maxFloor = monsterCnt;
	_clearCnt = 0;
	_dungeonName = dungeonName;

	for (const auto& t : types) {
		switch (t) {
		case SLIME: {
			_rooms.push_back(new MonsterSlime);
			break;
		}
		case GOBLIN: {
			_rooms.push_back(new MonsterGoblin);
			break;
		}
		case ORC: {
			_rooms.push_back(new MonsterOrc);
			break;
		}
		case DRAGON: {
			_rooms.push_back(new MonsterDragon);
			break;
		}
		}
	}
}
Dungeon::~Dungeon() {
	for (const auto& r : _rooms) {
		delete r._monster;
	}
}