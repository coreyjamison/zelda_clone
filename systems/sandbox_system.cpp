/*
 * sandbox_system.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Corey
 */

#include <engine/engine.hpp>
#include <effect/effect.hpp>

#include "sandbox_system.hpp"

bool SandboxSystem::run()
{
	if(_input.pressed(ButtonType::Z))
	{
		if(_nodes->nodes.size() > 0)
		{
			Entity* e = Engine::getInstance().getEcsManager().getEntity(0);

			SequentialEffectList* ef = new SequentialEffectList();
			//ef->addEffect(new WaitEffect(100));
			ef->addEffect(new DamageEffect(e, -10));

			Engine::getInstance().getEffectSystem().addEffect(ef);
		}
	}
	if(_input.pressed(ButtonType::X))
	{
		if(_nodes->nodes.size() > 0)
		{
			Entity* e = Engine::getInstance().getEcsManager().getEntity(0);

			DotEffect* dot = new DotEffect(e, 2, 10, 20);

			Engine::getInstance().getEffectSystem().addEffect(dot);
		}
	}
	if(_input.pressed(ButtonType::C))
	{
		if(_nodes->nodes.size() > 1)
		{
			_nodes->nodes[1]->health->heal(10);
		}
	}
	if(_input.pressed(ButtonType::V))
	{
		if(_nodes->nodes.size() > 1)
		{
			_nodes->nodes[1]->health->damage(10);
		}
	}

	return true;
}

void SandboxSystem::notify(InputState state)
{
	_input = state;
}
