/*
 * effect.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Corey
 */

#include "effect.hpp"


void SequentialEffectList::addEffect(Effect* e)
{
	_effects.push_back(e);
}

bool SequentialEffectList::execute()
{
	if(_effects.size() > 0)
	{
		if(_effects.front()->execute())
		{
			_effects.pop_front();
		}
		return _effects.size() == 0;
	}
	return true;
}
