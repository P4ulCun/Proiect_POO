#include "inventory.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

void ItemShop::addItem(std::shared_ptr<Item> item) { items.push_back(item); }
void ItemShop::removeItem(std::shared_ptr<Item> item)
{
	// remove by searching the pointer to the item or remove by index
	// idk yet
	// remove as in can't be selected in the shop, but it's still there
	// hide element
}

void PlayerInventory::addItem(std::shared_ptr<Item> item) { items.push_back(item); }
void PlayerInventory::removeItem(std::shared_ptr<Item> item)
{
	// remove by searching the pointer to the item or remove by index
	// actual remove
}