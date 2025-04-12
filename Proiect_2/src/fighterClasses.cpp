#include "fighterClasses.h"


void Character::increaseBaseHP(int value) { m_baseHP += value; }
void Character::increaseBasePower(int value) { m_basePower += value; }
void Character::increaseBaseArmour(int value) { m_baseArmour += value; }

void Character::takeDamage(int value) { m_currHP -= value; }
void Character::heal(int value) { m_currHP = (m_currHP + value > m_baseHP) ? m_baseHP : m_currHP + value; }

void Character::basicAttack(Character& target)
{
	target.takeDamage(m_currPower);
}

//std::ostream& operator<<(std::ostream& out, FighterClass player)
//{
//	std::cout << player.m_HP << '\n'
//		<< player.m_power << '\n'
//		<< player.m_armour << '\n';
//	return out;
//}