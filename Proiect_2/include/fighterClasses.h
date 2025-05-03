#pragma once
#include "statusEffect.h"
#include <string>
#include <iostream>
#include <memory>
#include <cmath>

//Compile-time constants
namespace CharacterStats {
	constexpr int ROGUE_HP = 100;
	constexpr int ROGUE_POWER = 23;
	constexpr int ROGUE_ARMOR = 2;
	constexpr int ROGUE_SPECIAL1_COOLDOWN = 2;

	constexpr int DRUID_HP = 120;
	constexpr int DRUID_POWER = 13;
	constexpr int DRUID_ARMOR = 4;
	constexpr int DRUID_SPECIAL1_COOLDOWN = 3;

	constexpr int WARRIOR_HP = 160;
	constexpr int WARRIOR_POWER = 15;
	constexpr int WARRIOR_ARMOR = 3;
	constexpr int WARRIOR_SPECIAL1_COOLDOWN = 1;

	constexpr int PALADIN_HP = 130;
	constexpr int PALADIN_POWER = 18;
	constexpr int PALADIN_ARMOR = 4;
}

//template<typename T>
//void increaseStats(T& stat, T& boost);

class Character
{
private:
	int m_baseHP;
	int m_basePower; // no limit
	int m_baseArmour; // max base armour 7
	// int m_stamina;
protected:
	Cooldown m_special1Cooldown;
	int m_currHP;
	int m_currPower;
	int m_currArmour;
	std::string m_name;
public:
	Character() = default;
	Character(std::string name, int HP, int power, int armour, int cooldown1) : m_name(name), m_baseHP(HP), 
		m_basePower(power), m_baseArmour(armour), m_currHP(HP), m_currPower(power), 
		m_currArmour(armour), m_special1Cooldown(cooldown1) {};
	virtual ~Character() = default;


	virtual void increaseBaseHP(int value);
	virtual void increaseBasePower(int value);
	virtual int increaseBaseArmour(int value);

	//OR
	//LINE 24
	
	// for item passives

	virtual int takeDamage(int value);
	virtual int heal(int value);

	virtual void basicAttack(Character& target);
	virtual int specialAttack1(Character& target) = 0;
	//virtual void specialAttack2() = 0;

	virtual void showStats();
	virtual bool isAlive();
	virtual std::string& getName();
	virtual void applyAbilityCooldownTicks();
	virtual int getCooldown();

	virtual std::string getHealth();
	//friend std::ostream& operator<<(std::ostream& out, Character player);
};

// SPECIFIC CLASSES
class Rogue : public Character
{
	// high damage ; lower hp/armour ; proficiency with daggers
public:
	Rogue(std::string name) : Character(name, CharacterStats::ROGUE_HP, CharacterStats::ROGUE_POWER, 
		CharacterStats::ROGUE_ARMOR, CharacterStats::ROGUE_SPECIAL1_COOLDOWN) {};

	int specialAttack1(Character& target) override; // backstab
	//void specialAttack2();
	//backstab
	//knife throw ?
};

class Druid : public Character
{
	//  high armour ; average health/dmg ; improved healing (proficiency with ALL healing items)
public:
	Druid(std::string name) : Character(name, CharacterStats::DRUID_HP, CharacterStats::DRUID_POWER, 
		CharacterStats::DRUID_ARMOR, CharacterStats::DRUID_SPECIAL1_COOLDOWN) {};

	int specialAttack1(Character& target) override;
	//void specialAttack2();
	// bear claw
	// wolf bite
};

class Warrior : public Character
{
	// high healh ; average dmg/armour ; proficiency with GreatSwords
public:
	Warrior(std::string name) : Character(name, CharacterStats::WARRIOR_HP, CharacterStats::WARRIOR_POWER, 
		CharacterStats::WARRIOR_ARMOR, CharacterStats::WARRIOR_SPECIAL1_COOLDOWN) {};

	int specialAttack1(Character& target) override;
	//void specialAttack2();
	// shield bash
	// charge ceva
};

//class Paladin : public Character
//{
//	// average ALL ; proficiency with holy items
//public:
//	Paladin() : Character(CharacterStats::PALADIN_HP, CharacterStats::PALADIN_POWER, CharacterStats::PALADIN_ARMOR) {};
//
//	/*void basicAttack();
//	void specialAttack1();
//	void specialAttack2();*/
//	//smite
//	//holy(divine) ceva - poate heal
//};