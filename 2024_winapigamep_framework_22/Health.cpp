#include "pch.h"
#include "Health.h"
#include "Object.h"
#include "MapManager.h"
#include "GDISelector.h"
#include "Enemy.h"

Health::Health()
	: m_maxHealth(10)
	, m_currnetHealth(10)
	, m_isDead(false)
{
}

Health::~Health()
{
}

void Health::LateUpdate()
{
}

void Health::Render(HDC _hdc)
{
}

void Health::SetMaxHealth(int _maxHealth, bool _isSetCurrentHealth)
{
	m_maxHealth = _maxHealth;
	if (_isSetCurrentHealth)
		m_currnetHealth = m_maxHealth;
}

void Health::ApplyDamage(int _damage)
{
	if (m_isDead) return;

	m_currnetHealth -= _damage;
	if (m_currnetHealth <= 0)
	{
		m_currnetHealth = 0;
		onDieEvent.Invoke();
		m_isDead = true;
	}
}