#pragma once
#include <string>
#include "statusEffect.h"
#include "fighterClasses.h"
// item selection will also be turn based

class Item
{
protected:
	std::string m_itemName;
	std::string m_itemDesc;
	bool m_isEquipped;
	// an item can be equipped by only one character
public:
	Item(std::string itemName, std::string itemDesc) : m_itemName(itemName), m_itemDesc(itemDesc), m_isEquipped(0) {};
	virtual ~Item() = default;

	virtual void applyPassive(Character& player) = 0;
	virtual void useItemAbility(Character&) {}; // let the active item classes implement this
	virtual std::string getName();
	
	friend std::ostream& operator<<(std::ostream& out, Item& item);
};


// BASIC / PASSIVE abilities NOT for specific classes
class BasicSword : public Item
{
private:
	int m_power;
public:
	BasicSword(std::string itemName, std::string itemDesc, int power) : Item(itemName, itemDesc), m_power(power) {};
	void applyPassive(Character& player) override;
};

class BasicHeal : public Item
{
private:
	int m_HP;
	// increase base HP
public:
	BasicHeal(std::string itemName, std::string itemDesc, int HP) : Item(itemName, itemDesc), m_HP(HP) {};
	void applyPassive(Character& player) override;
};

class BasicArmour : public Item
{
private:
	int m_armour;
public:
	BasicArmour(std::string itemName, std::string itemDesc, int armour) : Item(itemName, itemDesc), m_armour(armour) {};
	void applyPassive(Character& player) override;
};


// ACTIVE abilities need a button press to apply an effect
class ActiveSword : public BasicSword, public Cooldown
{
	// bleeding, crit chance
	int m_activePower;
public:
	ActiveSword(std::string itemName, std::string itemDesc, int power, int activePower, int cooldown)
		: BasicSword(itemName, itemDesc, power), m_activePower(activePower),
		Cooldown(cooldown) {};
	void useItemAbility(Character& target) override;
};

class ActiveHeal : public BasicHeal, public Cooldown
{
	// more heal for druid maybe
	int m_activeHeal;
public:
	ActiveHeal(std::string itemName, std::string itemDesc, int HP, int activeHeal, int cooldown)
		: BasicHeal(itemName, itemDesc, HP), m_activeHeal(activeHeal),
		Cooldown(cooldown) {};
	void useItemAbility(Character& player) override;
};


// need status effects for this  ;  maybe later
//class ActiveArmour : public BasicArmour
//{
//	int m_activeArmour;
//public:
//	ActiveArmour(std::string itemName, std::string itemDesc, int armour, int activeArmour)
//		: BasicArmour(itemName, itemDesc, armour), m_activeArmour(activeArmour) {
//	};
//	void useItemAbility(Character& player);
//	~ActiveArmour() {};
//};