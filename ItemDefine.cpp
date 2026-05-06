
#include "ItemDefine.h"

using namespace std;

string Item::GetItemNameToString(ItemName name) {

	switch (name) {
	case HP_POTION: return "HP Potion";
	case MP_POTION: return "MP Potion";
	case STAMINA_POTION: return "Stamina Potion";
	case EMPTY_BOTTLE: return "Empty Bottle";

	case SLIME_JELLY: return "Slime Jelly";
	case GOBLIN_EAR: return "Goblin Ear";
	case ORC_LEATHER: return "Orc Leather";
	case DRAGON_HEART: return "Dragon Heart";
	}

	return "InvalidItemName";
}

ItemName Item::GetStringToItemName(string name) {
	if (name == "HP Potion") return HP_POTION;
	else if (name == "MP Potion") return MP_POTION;
	else if (name == "Stamina Potion") return STAMINA_POTION;
	else if (name == "Empty Bottle") return EMPTY_BOTTLE;

	return INVALID;
}

__int32 Item::GetItemPriceByItemName(ItemName name) {

	switch (name) {
	case HP_POTION: return 50;
	case MP_POTION: return 50;
	case STAMINA_POTION: return 60;
	case EMPTY_BOTTLE: return 0;

	case SLIME_JELLY: return 444;
	case GOBLIN_EAR: return 555;
	case ORC_LEATHER: return 111;
	case DRAGON_HEART: return 999;
	}

	return 0;
}

string Item::GetIngredientName(IngredientName name) {

	switch (name) {
	case HERB: return "Herb";
	case CLEAR_WATER: return "Clear Water";
	case BERRY: return "Berry";
	}

	return "InvalidIngredientName";
}

Item* Item::MakeItem(ItemName name) {
	return new Item(name, Item::GetItemPriceByItemName(name));
}