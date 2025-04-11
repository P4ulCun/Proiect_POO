#pragma once
#include <string>

#include "fighterClasses.h"

class Item
{
private:
	std::string m_itemName;
	std::string m_itemDesc;
public:
	Item(std::string itemName, std::string itemDesc) : m_itemName(itemName), m_itemDesc(itemDesc) {};
	virtual void applyEffect() = 0;
	virtual ~Item() {};
};

// basic as in passive abilities and NOT for specific classes

class BasicSword : public Item
{
private:
	int m_power;
public:
	BasicSword(std::string itemName, std::string itemDesc) : Item(itemName, itemDesc), m_power(10) {};
	void applyEffect(Character& player);
	~BasicSword() {};
};

class BasicHealing : public Item
{
private:
	int m_healing;
public:
	BasicHealing(std::string itemName, std::string itemDesc) : Item(itemName, itemDesc), m_healing(10) {};
	void applyEffect(Character& player);
	~BasicHealing() {};
};

class BasicArmour : public Item
{
private:
	int m_armour;
public:
	BasicArmour(std::string itemName, std::string itemDesc) : Item(itemName, itemDesc), m_armour(10) {};
	void applyEffect(Character& player);
	~BasicArmour() {};
};