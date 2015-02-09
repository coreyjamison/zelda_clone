/*
 * effect_system.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Corey
 */

#include <algorithm>

#include "effect_system.hpp"

using namespace std;

bool EffectSystem::run()
{
	_effects.erase(remove_if(_effects.begin(), _effects.end(), EffectRunner()), _effects.end());
	return true;
}

void EffectSystem::addEffect(Effect* e)
{
	_effects.push_back(e);
}


