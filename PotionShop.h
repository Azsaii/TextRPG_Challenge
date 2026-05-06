#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "ItemDefine.h"

struct Recipe {
	Item* _potion;
	std::unordered_map<IngredientName, __int32> _ingredients;

	Recipe(ItemName name) {
		_potion = Item::MakeItem(name);
	}

	void PrintPotionInfo(void);
};

class PotionShop {
private:
	std::vector<Recipe*> _recipes;
	std::unordered_map<ItemName, unsigned __int32> _potionStock;
public:

	PotionShop();
	~PotionShop();

	void ShowPotionShopMenu(void);
	void PrintAllRecipes(void);
	void SearchByPotionName(std::string potionName);
	void SearchByIngredient(std::string ingredientName);

	void DispensePotion(std::string);
	void ReturnPotion(std::string);
	void GetStock(std::string);
};