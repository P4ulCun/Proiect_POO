#include "inventoryBuilder.h"

InventoryBuilder::InventoryBuilder() 
{ 
	inventory = std::make_shared<PlayerInventory>(); 
}

InventoryBuilder& InventoryBuilder::addItem(const std::shared_ptr<Item>& item)
{
	inventory->addItem(item);
	return *this;
}

std::shared_ptr<PlayerInventory> InventoryBuilder::build()
{
	return inventory;
}