#pragma once
#include "items.h"
#include <string>
#include <memory>
#include <vector>


//class Item;

class Inventory
{
protected:
	std::vector<std::shared_ptr<Item>> items;
public:
	Inventory() = default;
	virtual ~Inventory() = default;

	virtual void addItem(std::shared_ptr<Item> item) = 0;
	virtual void removeItem(std::shared_ptr<Item> item) = 0;
	//virtual void listItems() = 0;
	// asta pt afisare cu sprites si chestii
};

class ItemShop : public Inventory
{
public:
	void addItem(std::shared_ptr<Item> item);
	void removeItem(std::shared_ptr<Item> item);
};

class PlayerInventory : public Inventory
{
	int m_maxItems;
public:
	PlayerInventory() : m_maxItems(3) {};
	void addItem(std::shared_ptr<Item> item);
	void removeItem(std::shared_ptr<Item> item);
};