/*
 * effect.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Corey
 */

#include "effect.hpp"
#include <ecs/component.hpp>

#include <iostream>
using namespace std;

bool Effect::execute()
{
	if(!_initialized)
	{
		init();
		_initialized = true;
	}
	if(step())
	{
		finish();
		return true;
	}
	return false;
}

/* These do essentially nothing, so subclasses can overwrite only the ones
 * they need, leaving the rest to harmlessly do nothing.
 */
void Effect::init() {}
bool Effect::step() {return true;}
void Effect::finish() {}

void SequentialEffectList::addEffect(Effect* e)
{
	_effects.push_back(e);
}

bool SequentialEffectList::step()
{
	if(_effects.size() > 0)
	{
		if(_effects.front()->execute())
		{
			delete _effects.front();
			_effects.pop_front();
		}
		return _effects.size() == 0;
	}
	return true;
}

WaitEffect::WaitEffect(unsigned int ticks)
:	_ticksRemaining(ticks)
{}

bool WaitEffect::step()
{
	return _ticksRemaining-- <= 0;
}

DamageEffect::DamageEffect(Entity* entity, int amount)
:	_entity(entity), _amount(amount)
{}

void DamageEffect::finish()
{
	HealthComponent* h = _entity->getComponent<HealthComponent>();
	if(h)
	{
		h->damage(_amount);
	}
}

DotEffect::DotEffect(Entity* entity, int tickAmount, unsigned int ticks, unsigned int tickLength)
:	_entity(entity), _tickAmount(tickAmount), _ticks(ticks * tickLength), _tickLength(tickLength)
{}

bool DotEffect::step()
{
	HealthComponent* h = _entity->getComponent<HealthComponent>();
	if(h && _ticks % _tickLength == 0)
	{
		h->damage(_tickAmount);
		cout << h->health << " HP" << endl;
	}
	return --_ticks <= 0;
}
