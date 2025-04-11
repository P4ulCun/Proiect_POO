#include "fighterClasses.h"


void Character::increaseHP(int value) { m_HP += value; }
void Character::increasePower(int value) { m_power += value; }
void Character::increaseArmour(int value) { m_armour += value; }

//std::ostream& operator<<(std::ostream& out, FighterClass player)
//{
//	std::cout << player.m_HP << '\n'
//		<< player.m_power << '\n'
//		<< player.m_armour << '\n';
//	return out;
//}