#pragma once
#include <string>
#include <iostream>

namespace CharacterStats {
	constexpr int DRUID_HP = 120;
	constexpr int DRUID_DMG = 15;
	constexpr int DRUID_ARMOR = 5;

	constexpr int ROGUE_HP = 100;
	constexpr int ROGUE_DMG = 20;
	constexpr int ROGUE_ARMOR = 3;
}

class Character
{
private:
	int m_HP;
	int m_power;
	int m_armour;
	// int m_stamina;
public:
	Character(int hp, int power, int armour) : m_HP(hp), m_power(power), m_armour(armour) {};
	void increaseHP(int value);
	void increasePower(int value);
	void increaseArmour(int value);
	// for item passives

	virtual void basicAttack();
	virtual void specialAttack1() = 0;
	virtual void specialAttack2() = 0;

	//friend std::ostream& operator<<(std::ostream& out, FighterClass player);
};

class Rogue : public Character
{
public:
	Rogue() : Character(60, 120, 2) {};

	void basicAttack();
	void specialAttack1();
	void specialAttack2();
};