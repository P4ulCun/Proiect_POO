#include "statusEffect.h"

void Cooldown<int>::tick() { m_cooldownTime = (m_cooldownTime > 0) ? m_cooldownTime - 1 : 0; }
bool Cooldown<int>::isOffCooldown() { return (m_cooldownTime <= 0) ? true : false; }
void Cooldown<int>::applyCooldown() { m_cooldownTime = m_cooldownTotalDuration; }

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