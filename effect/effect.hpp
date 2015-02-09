/*
 * event.hpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Corey
 */

#ifndef EFFECT_HPP_
#define EFFECT_HPP_

#include <list>

#include <ecs/entity.hpp>

class Effect
{
public:
	virtual ~Effect() = default;

	virtual bool execute() = 0;
};


class SequentialEffectList : public Effect
{
public:
	virtual void addEffect(Effect* e);
	virtual bool execute();

private:
	list<Effect*> _effects;
};


#endif /* EFFECT_HPP_ */
