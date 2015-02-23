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

	if(_input.pressed(ButtonType::F))
	{
		Engine& e = Engine::getInstance();
		EffectSystem& es = e.getEffectSystem();
		EcsManager& ecs = e.getEcsManager();

		Entity* player = ecs.getFlaggedEntities("player").front();

		if(player)
		{
			EntityConfig config;
			config.position = player->getComponent<PositionComponent>()->curPos;
			config.position += {100, 0};
			config.prototype = "slime";

			StateComponent* state = new StateComponent(0);
			config.components.push_back(state);

			AiCommandComponent* ai = new AiCommandComponent();
			config.components.push_back(ai);

			cout << "Adding CreateEntityEffect!" << endl;
			es.addEffect(new CreateEntityEffect(config));
		}
	}

	return true;
}

void SandboxSystem::notify(InputState state)
{
	_input = state;
}
