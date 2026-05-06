#pragma once
#include <iostream>
#include <algorithm>

template<typename T>
class Inventory {
private:
	size_t _capacity;
	size_t _size;
public:
	T** _Items;

	Inventory() : _capacity(10) {
		_Items = new T*[_capacity];
		_size = 0;
	}

	~Inventory() {
		for (size_t i = 0; i < _size; i++) delete _Items[i];
		delete[] _Items;
	}

	Inventory(const Inventory& other) = delete;
	Inventory& operator=(const Inventory& other) = delete;

	void AddItem(T* item) {
		std::cout << "Adding item...\n";
		if (_size == _capacity) {
			std::cout << "-> Full!\n";
			std::cout << "-> Inventory auto-expanded! (" << _capacity << " -> " << _capacity + 10 << ")\n";
			_capacity += 10;

			T** tmp = new T * [_capacity];
			for (size_t i = 0; i < _size; i++) tmp[i] = _Items[i];
			delete[] _Items;
			_Items = tmp;
		}

		_Items[_size++] = item;
		std::cout << "-> Item added (" << _size << '/' << _capacity << ")\n\n";

		SortItems();
		PrintAllItems();
	}

	static bool compareByPrice(const T* a, const T* b) {
		return *a > *b;
	}

	void SortItems(void) {
		std::sort(_Items, _Items + _size, compareByPrice);
		std::cout << "[ Inventory sorted by price ]\n";
	}

	void RemoveLastItem(void) {
		if (_size > 0) {
			T* last = _Items[_size - 1];
			_Items[_size - 1] = nullptr;
			delete last;
			_size--;
		}

		SortItems();
		PrintAllItems();
	}

	void RemoveItem(ItemName name) {
		for (size_t i = 0; i < _size; i++) {
			if (_Items[i]->_name == name) {
				delete _Items[i];
				_Items[i] = _Items[_size - 1];
				_size--;
				break;
			}
		}

		SortItems();
		PrintAllItems();
	}

	void PrintAllItems(void) const {
		std::cout << "[ Inventory (" << _size << "/" << _capacity << ") ]\n";

		for (size_t i = 0; i < _size; i++) {
			std::cout << i + 1 << ". " << Item::GetItemNameToString(_Items[i]->_name) << " (" << Item::GetItemPriceByItemName(_Items[i]->_name) << "G)\n";
		}

		std::cout << "\n\n";
	}

	size_t GetSize(void) const {
		return _size;
	}

	size_t GetCapacity(void) const {
		return _capacity;
	}
};