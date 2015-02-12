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

class EntityEffect : public Effect
{
public:
	EntityEffect(Entity* e);
	virtual ~EntityEffect() = default;

	virtual bool execute() = 0;

protected:
	Entity* _entity;
};

class MoveEffect : public EntityEffect
{
public:
	MoveEffect(Entity* e, Vec2<double> direction);

	virtual bool execute();

private:
	Vec2<double> _direction;
};


#endif /* EFFECT_HPP_ */
