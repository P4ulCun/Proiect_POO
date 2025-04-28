#include "statusEffect.h"

void Cooldown::tick() { m_cooldownTime = (m_cooldownTime > 0) ? m_cooldownTime - 1 : 0; }
bool Cooldown::isOffCooldown() { return (m_cooldownTime <= 0) ? true : false; }
void Cooldown::applyCooldown() { m_cooldownTime = m_cooldownTotalDuration; }

int Cooldown::getCooldown() { return m_cooldownTime; }
//void StatusEffect::tick()
//{
//	m_effectDuration -= 1;
//}
//
//bool StatusEffect::isExpired()
//{
//	return m_effectDuration <= 0;
//}
//
//void BleedingStatusEffect::applyStatusEffect(Character& player)
//{
//	if (m_effectDuration > 0)
//	{
//		//display icon
//		player.takeDamage(m_damagePerTurn);
//		std::cout << "took bleeding damage!\n";
//	}
//}