#pragma once
#include <string>
#include <iostream>

//Compile-time constants
namespace CharacterStats {
	constexpr int ROGUE_HP = 100;
	constexpr int ROGUE_POWER = 23;
	constexpr int ROGUE_ARMOR = 1;

	constexpr int DRUID_HP = 120;
	constexpr int DRUID_POWER = 13;
	constexpr int DRUID_ARMOR = 5;

	constexpr int WARRIOR_HP = 160;
	constexpr int WARRIOR_POWER = 15;
	constexpr int WARRIOR_ARMOR = 3;

	constexpr int PALADIN_HP = 130;
	constexpr int PALADIN_POWER = 18;
	constexpr int PALADIN_ARMOR = 4;
}

class Character
{
private:
	int m_baseHP;
	int m_basePower;
	int m_baseArmour;
	// int m_stamina;
	int m_currHP;
	int m_currPower;
	int m_currArmour;
public:
	Character(int HP, int power, int armour) : m_baseHP(HP), m_basePower(power), m_baseArmour(armour), 
	m_currHP(HP), m_currPower(power), m_currArmour(armour) {};
	virtual ~Character() = default;


	void increaseBaseHP(int value);
	void increaseBasePower(int value);
	void increaseBaseArmour(int value);
	// for item passives

	void takeDamage(int value);
	void heal(int value);

	virtual void basicAttack(Character& target);
	/*virtual void specialAttack1() = 0;
	virtual void specialAttack2() = 0;*/

	

	//friend std::ostream& operator<<(std::ostream& out, FighterClass player);
};

// SPECIFIC CLASSES
class Rogue : public Character
{
	// high damage ; lower hp/armour ; proficiency with daggers
public:
	Rogue() : Character(CharacterStats::ROGUE_HP, CharacterStats::ROGUE_POWER, CharacterStats::ROGUE_ARMOR) {};

	/*void basicAttack();
	void specialAttack1();
	void specialAttack2();*/
	//backstab
	//knife throw ?
};

class Druid : public Character
{
	//  high armour ; average health/dmg ; improved healing (proficiency with ALL healing items)
public:
	Druid() : Character(CharacterStats::DRUID_HP, CharacterStats::DRUID_POWER, CharacterStats::DRUID_ARMOR) {};

	/*void basicAttack();
	void specialAttack1();
	void specialAttack2();*/
	// bear claw
	// wolf bite
};

class Warrior : public Character
{
	// high healh ; average dmg/armour ; proficiency with GreatSwords
public:
	Warrior() : Character(CharacterStats::WARRIOR_HP, CharacterStats::WARRIOR_POWER, CharacterStats::WARRIOR_ARMOR) {};

	/*void basicAttack();
	void specialAttack1();
	void specialAttack2();*/
	// shield bash
	// charge ceva
};

class Paladin : public Character
{
	// average ALL ; proficiency with holy items
public:
	Paladin() : Character(CharacterStats::PALADIN_HP, CharacterStats::PALADIN_POWER, CharacterStats::PALADIN_ARMOR) {};

	/*void basicAttack();
	void specialAttack1();
	void specialAttack2();*/
	//smite
	//holy(divine) ceva - poate heal
};