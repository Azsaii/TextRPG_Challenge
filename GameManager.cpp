#include <iostream>
#include "GameManager.h"
#include "Dungeon.h"

using namespace std;

// 현재 던전 1개만 존재함.
GameManager::GameManager(void) {
	_currentDungeonIndex = 0;

	vector<MonsterType> t1 = { SLIME, GOBLIN, ORC, DRAGON };
	Dungeon* d1 = new Dungeon(4, "Dungeon Floot 1", t1);
	_dungeons.push_back(d1);

	/*vector<MonsterType> t2 = { SLIME, GOBLIN, GOBLIN, ORC, ORC, DRAGON };
	Dungeon* d2 = new Dungeon(6, "Dungeon Floot 2", t2);
	_dungeons.push_back(d2);*/
}

GameManager::~GameManager(void) {
	for (const auto& d : _dungeons) {
		delete d;
	}
}

GameManager* GameManager::GetInstance(void) {
	if (_instance == nullptr) {
		_instance = new GameManager();
	}
	return _instance;
}

// 도전과제 step 1
void setPotion(int cnt, unsigned __int32* p_HPPotion, unsigned __int32* p_MPPotion) {
	*p_HPPotion = cnt;
	*p_MPPotion = cnt;
}

void GameManager::StartPlayerSetting(void) {
	_player.CreateCharacter();

	// 도전과제 step 1
	setPotion(5, &_player._hp_potion, &_player._mp_potion);

	_player.PrintStatus();
	_player.StatusUpgrade();
	_player.JobSelection();

	
}

void GameManager::MainMenuProc(void) {

	bool ch = true;
	__int32 in;

	while (ch) {

		cout << "=== Main Menu ===\n";
		cout << "1. Enter Dungeon\n";
		cout << "2. Check Inventory\n";
		cout << "3. Potion Shop\n";
		cout << "0. Quit\n";

		cout << "\nChoose: ";
		if (!(cin >> in)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input.\n";
			continue;
		}

		switch (in) {
		case 0: {
			cout << "Good Bye.";
			ch = false;
			break;
		}
		case 1: {
			StartBattle();
			break;
		}
		case 2: {
			_player._inventory.PrintAllItems();
			break;
		}
		case 3: {
			_potionShop.ShowPotionShopMenu();
			break;
		}
		default: {
			cout << "Invalid input.\n";
			ch = true;
			break;
		}
		}
	}
}

void GameManager::StartBattle(void) {

	cout << "\n\n";

	Dungeon* currentDungeon = _dungeons[_currentDungeonIndex];
	cout << "[ " << currentDungeon->_dungeonName << " ]\n";
	Monster* targetMonster = currentDungeon->_rooms[currentDungeon->_clearCnt]._monster;

	for (__int32 floor = 0; floor < currentDungeon->_maxFloor - 1; floor++) {
		const auto& room = currentDungeon->_rooms[floor];
		Monster* currentMonster = room._monster;

		cout << "Room " << floor + 1 << ": " << currentMonster->_name;
		cout << "\t(HP " << currentMonster->_maxHp << ", Attack " << currentMonster->_attackPower << ")";

		if (floor < currentDungeon->_clearCnt) {
			cout << "\t-> Clear!";
		}
		cout << '\n';
	}

	if (currentDungeon->_clearCnt >= currentDungeon->_maxFloor - 1) {
		Monster* boss = currentDungeon->_rooms[currentDungeon->_maxFloor - 1]._monster;
		cout << "\n★ Boss Room Unlocked!\n";
		cout << "Boss Dragon appears!";
		cout << "\t(HP " << boss->_maxHp << ", Attack " << boss->_attackPower << ", Defense " << boss->_defence << ")";
		cout << "\n\n";
	}
	if (currentDungeon->_clearCnt == currentDungeon->_maxFloor) {
		cout << "Dragon defeated!\n";
		cout << "=== GAME CLEAR! ===\n";
		cout << "\n\n";
		return;
	}

	cout << "\n[ Battle Start! ] " << _player._name << " vs " << targetMonster->_name;

	bool isPlayerTurn = true;
	bool isBattleNotEnd = true;
	while (isBattleNotEnd) {

		if (isPlayerTurn == true) {
			cout << "\n\n--- Player Turn ---\n";
			bool ch = true;
			while (ch) {
				ch = false;
				cout << "1. Attack\n";
				cout << "2. Use Item\n";
				cout << "Choose: ";

				__int32 in;
				if (!(cin >> in)) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Invalid input. Try again.\n";
					continue;
				}

				cout << '\n';

				switch (in) {
				case 1: {
					_player._job->JobAttackProc(_player._attackPower, targetMonster);
					if (targetMonster->_hp == 0) {

						cout << " (Dead)\n";
						isBattleNotEnd = false;		

						cout << "\n★ Victory!\n";
						currentDungeon->_clearCnt++;

						cout << "  -> Got: " << Item::GetItemNameToString(targetMonster->_dropItem->_name) << "!\n";
						cout << "\nSave to inventory.\n";
						_player._inventory.AddItem(targetMonster->_dropItem);

						cout << "  -> +" << targetMonster->_expReward << " EXP! (EXP: ";
						cout << _player._exp + targetMonster->_expReward << "/" << _player._maxExp << ")\n\n";

						if (_player.AddExp(targetMonster->_expReward) == true) {
							cout << "... Level up condition met\n";
							cout << "  -> Level Up! Lv." << _player._level - 1 << " -> Lv." << _player._level << '\n';
							cout << "  -> HP +" << _player._LevelUpHpAdd << ", MP +" << _player._LevelUpMpAdd;
							cout << ", Attack +" << _player._LevelUpAttackPowerAdd << ", Defence +" << _player._LevelUpDefenceAdd;
						}
					}
					break;
				}
				case 2: {
					_player._inventory.PrintAllItems();

					while (1) {
						cout << "Choose: ";
						__int32 itemIndex;
						if (!(cin >> itemIndex)) {
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							cout << "Invalid input. Try again.\n";
							continue;
						}

						_player.UseItem(_player.GetItemNameByIndex(itemIndex - 1));
						break;
					}
					break;
				}
				default: {
					cout << "Invalid input.\n";
					ch = true;
					break;
				}
				}
			}
		}
		else {
			cout << "\n\n--- Monster Turn ---\n";
			bool isPlayerDead = targetMonster->AttackTarget(&_player);
			if (isPlayerDead == true) {
				cout << "\n▶ YOU DIE! ◀\n";
				isBattleNotEnd = false;
			}
		}

		isPlayerTurn = !isPlayerTurn;
	}

	cout << "\n\n";
}

GameManager* GameManager::_instance;