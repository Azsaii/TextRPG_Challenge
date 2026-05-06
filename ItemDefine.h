#pragma once
#include <string>

enum ItemName {
	HP_POTION,
	MP_POTION,
	STAMINA_POTION,
	EMPTY_BOTTLE,
	POTION_END,

	SLIME_JELLY,
	GOBLIN_EAR,
	ORC_LEATHER,
	DRAGON_HEART,
	ITEM_END,
	INVALID,
};

enum IngredientName {
	HERB,
	CLEAR_WATER,
	BERRY
};

class Item {
private:
	
	Item(ItemName name, unsigned __int32 price) : _name(name), _price(price) {}

public:
	Item() = default;
	ItemName _name;
	unsigned __int32 _price;

	bool operator>(const Item& other) const {
		return _price > other._price;
	}

	static std::string GetItemNameToString(ItemName);
	static ItemName GetStringToItemName(std::string);
	static __int32 GetItemPriceByItemName(ItemName);
	static std::string GetIngredientName(IngredientName);
	static Item* MakeItem(ItemName);
};