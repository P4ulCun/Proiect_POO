#pragma once
//#include "fighterClasses.h"
#include <string>

template <typename T>
class Cooldown
{
private:
	T m_cooldownTotalDuration;
	T m_cooldownTime;
public:
	//Cooldown() = default;
	Cooldown(int cooldownTime) : m_cooldownTotalDuration(cooldownTime), m_cooldownTime(0) {};
	virtual ~Cooldown() = default;

	virtual void tick();
	virtual bool isOffCooldown();
	virtual void applyCooldown();
	virtual T getCooldown()
	{
		return m_cooldownTime; 
	}
};

//class StatusEffect
//{
//protected:
//	std::string m_effectName;
//	int m_effectDuration; // in rounds ; 2 turns
//public:
//	StatusEffect(std::string effectName, int effectDuration) : m_effectName(effectName), m_effectDuration(effectDuration) {};
//	virtual ~StatusEffect() = default;
//
//	virtual void applyStatusEffect(Character& player) = 0;
//	virtual void tick();
//	virtual bool isExpired();
//};
//
//class PowerStatusEffect : public StatusEffect
//{
//private:
//	int m_power;
//public:
//	void applyStatusEffect(Character& player) override;
//};
//
//class StunStatusEffect : public StatusEffect
//{
//public:
//	void applyStatusEffect(Character& player) override;
//};
//
//class BleedingStatusEffect : public StatusEffect
//{
//private:
//	int m_damagePerTurn;
//public:
//	BleedingStatusEffect(std::string name, int duration, int damage)
//		: StatusEffect(name, duration), m_damagePerTurn(damage) {};
//	void applyStatusEffect(Character& player) override;
//};
//
//class HealingStatusEffect : public StatusEffect
//{
//public:
//	void applyStatusEffect(Character& player) override;
//};