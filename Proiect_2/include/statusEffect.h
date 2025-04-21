#pragma once
#include "fighterClasses.h"
#include <string>

class Cooldown
{
private:
	int m_cooldownTime;
public:
	Cooldown(int cooldownTime) : m_cooldownTime(cooldownTime) {};
	virtual ~Cooldown() = default;

	virtual void tick();
	virtual bool isOffCooldown();
};

class StatusEffect
{
protected:
	std::string m_effectName;
	int m_effectDuration; // in rounds ; 2 turns
public:
	StatusEffect(std::string effectName, int effectDuration) : m_effectName(effectName), m_effectDuration(effectDuration) {};
	virtual ~StatusEffect() = default;

	virtual void applyStatusEffect(Character& player) = 0;
	virtual void tick();
	virtual bool isExpired();
};

class PowerStatusEffect : public StatusEffect
{
private:
	int m_power;
public:
	void applyStatusEffect(Character& player) override;
};

class StunStatusEffect : public StatusEffect
{
public:
	void applyStatusEffect(Character& player) override;
};

class BleedingStatusEffect : public StatusEffect
{
private:
	int m_damagePerTurn;
public:
	BleedingStatusEffect(std::string name, int duration, int damage)
		: StatusEffect(name, duration), m_damagePerTurn(damage) {};
	void applyStatusEffect(Character& player) override;
};

class HealingStatusEffect : public StatusEffect
{
public:
	void applyStatusEffect(Character& player) override;
};

class CoolDown;