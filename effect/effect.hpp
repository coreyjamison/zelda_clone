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
	virtual ~Effect() = 0;

	bool execute();

	virtual void init();
	virtual bool step();
	virtual void finish();

private:
	bool _initialized;
};
inline Effect::~Effect() {}


class SequentialEffectList : public Effect
{
public:
	virtual void addEffect(Effect* e);
	virtual bool step();

private:
	list<Effect*> _effects;
};

class SimultaneousEffectList : public Effect
{
public:
	virtual void addEffect(Effect* e);
	virtual bool step();

	struct EffectRunner : public unary_function<Effect*, bool>
		{
			bool operator()(Effect* e) const
			{
				bool finished = e->execute();
				if(finished)
					delete e;
				return finished;
			}
		};

private:
	vector<Effect*> _effects;
};

class WaitEffect : public Effect
{
public:
	WaitEffect(unsigned int ticks);

	virtual bool step();
private:
	unsigned int _ticksRemaining;
};

class DamageEffect : public Effect
{
public:
	DamageEffect(Entity* entity, int amount);

	virtual void finish();
private:
	Entity* _entity;
	int _amount;
};

class DotEffect : public Effect
{
public:
	DotEffect(Entity* entity, int tickAmount, unsigned int ticks, unsigned int tickLength);

	virtual bool step();
private:
	Entity* _entity;
	int _tickAmount;
	unsigned int _ticks;
	unsigned int _tickLength;
};

class PushEffect : public Effect
{
public:
	PushEffect(Entity* entity, Vec2<double> push, unsigned int duration);

	virtual bool step();
private:
	Entity* _entity;
	Vec2<double> _push;
	unsigned int _duration;
};


#endif /* EFFECT_HPP_ */
