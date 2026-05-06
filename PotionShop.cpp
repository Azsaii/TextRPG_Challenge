#include <iostream>
#include "PotionShop.h"
#include "GameManager.h"

using namespace std;

void Recipe::PrintPotionInfo(void) {

	cout << "-> " << Item::GetItemNameToString(_potion->_name) << " (";

	bool isFirst = true;
	for (const auto& [key, val] : _ingredients) {
		if (!isFirst) cout << ", ";
		cout << Item::GetIngredientName(key) << " x" << val;
		isFirst = false;
	}

	cout << ")\n";
}

PotionShop::PotionShop() {

	Recipe* HPPotion = new Recipe(HP_POTION);
	HPPotion->_ingredients[HERB] = 1;
	HPPotion->_ingredients[CLEAR_WATER] = 1;
	_recipes.push_back(HPPotion);

	Recipe* MPPotion = new Recipe(MP_POTION);
	MPPotion->_ingredients[HERB] = 2;
	MPPotion->_ingredients[CLEAR_WATER] = 1;
	_recipes.push_back(MPPotion);

	Recipe* StaminaPotion = new Recipe(STAMINA_POTION);
	StaminaPotion->_ingredients[HERB] = 1;
	StaminaPotion->_ingredients[BERRY] = 1;
	_recipes.push_back(StaminaPotion);

	_potionStock[HP_POTION] = 3;
	_potionStock[MP_POTION] = 3;
	_potionStock[STAMINA_POTION] = 3;
}

PotionShop::~PotionShop() {
	for (const auto& r : _recipes) {
		delete r;
	}
}

void PotionShop::ShowPotionShopMenu(void) {

	cout << "\n\n";

	bool loop = true;
	__int32 in;
	string search;

	while (loop) {

		cout << "=== Potion Shop ===\n";
		cout << "1. Show all recipes\n";
		cout << "2. Search by potion name\n";
		cout << "3. Search by ingredient\n";
		cout << "4. Dispense potion\n";
		cout << "5. Return potion\n";
		cout << "6. Get potion stock\n";
		cout << "0. Go back\n";

		cout << "\nChoose: ";
		if (!(cin >> in)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input.\n";
			continue;
		}

		switch (in) {
		case 0: {
			cout << "Good Bye.\n\n";
			loop = false;
			break;
		}
		case 1: {
			PrintAllRecipes();
			break;
		}
		case 2: {	
			cout << "Search potion name: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, search);
			SearchByPotionName(search);
			break;
		}
		case 3: {
			cout << "Search ingredient: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, search);
			SearchByIngredient(search);
			break;
		}
		case 4: {
			cout << "Input potion name: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, search);
			DispensePotion(search);
			break;
		}
		case 5: {
			cout << "Input potion name: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, search);
			ReturnPotion(search);
			break;
		}
		case 6: {
			cout << "Input potion name: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, search);
			GetStock(search);
			break;
		}
		default: {
			cout << "Invalid input.\n";
			break;
		}
		}
	}
}

void PotionShop::PrintAllRecipes(void) {

	cout << "\n\n";
	cout << "< All recipes >\n";

	for (auto& recipe : _recipes) {
		recipe->PrintPotionInfo();
	}

	cout << "\n\n";
}

void PotionShop::SearchByPotionName(string potionName) {

	bool check = false;
	for (auto& recipe : _recipes) {
		if (Item::GetItemNameToString(recipe->_potion->_name) == potionName) {
			recipe->PrintPotionInfo();
			check = true;
			break;
		}
	}
	if (check == false) cout << "Potion not found.\n";

	cout << "\n\n";
}

void PotionShop::SearchByIngredient(string ingredientName) {

	__int32 cnt = 0;
	for (auto& recipe : _recipes) {	
		for (const auto& [key, val] : recipe->_ingredients) {
			if (recipe->_potion->GetIngredientName(key) == ingredientName) {
				recipe->PrintPotionInfo();
				cnt++;
			}
		}
	}

	cout << "Found " << cnt << " recipes.\n";
	cout << "\n\n";
}

void PotionShop::DispensePotion(string name) {

	ItemName itemName = Item::GetStringToItemName(name);
	if (itemName != INVALID) {
		if (_potionStock[itemName] > 0) {
			_potionStock[itemName]--;
			cout << "-> Dispense " << name << "\t(stock: " << _potionStock[itemName] << ")\n";
			GameManager::GetInstance()->_player._inventory.AddItem(Item::MakeItem(itemName));
		}
		else {
			cout << "-> Dispense failed: out of stock!";
		}
	}
	else cout << "Potion not found.\n\n";
}

void PotionShop::ReturnPotion(string name) {
	ItemName itemName = Item::GetStringToItemName(name);
	if (itemName != INVALID) {
		if (_potionStock[itemName] == 3) {
			cout << "-> Stock is max!\n";
		}
		else {
			_potionStock[itemName]++;
			cout << "-> Return empty bottle\t(stock: " << _potionStock[itemName] << ")\n";
			GameManager::GetInstance()->_player._inventory.RemoveItem(itemName);
		}
	}
	else cout << "Potion not found.\n\n";
}

void PotionShop::GetStock(string name) {
	ItemName itemName = Item::GetStringToItemName(name);
	if (itemName != INVALID) cout << "stock: " << _potionStock[itemName];
	else cout << "Potion not found.";
	cout << "\n\n";
}