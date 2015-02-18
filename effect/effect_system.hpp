/*
 * effect_system.hpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Corey
 */

#ifndef EFFECT_SYSTEM_HPP_
#define EFFECT_SYSTEM_HPP_

#include <vector>

#include <gameloop/runnable.hpp>

#include "effect.hpp"

using namespace std;
class EffectSystem : public FixedRunnable
{
public:
	virtual bool run();
	void addEffect(Effect* e);

private:
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

	vector<Effect*> _effects;
};



#endif /* EFFECT_SYSTEM_HPP_ */
