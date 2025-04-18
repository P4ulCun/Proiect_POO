#include "statusEffect.h"

void StatusEffect::tick()
{
	m_effectDuration -= 1;
}

bool StatusEffect::isExpired()
{
	return m_effectDuration <= 0;
}

void DamagingStatusEffect::applyStatusEffect(Character& player)
{
	player.takeDamage(m_damagePerTurn);
	std::cout << "took bleeding damage!\n";
}