/*
 * sandbox_system.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Corey
 */

#include "sandbox_system.hpp"

bool SandboxSystem::run()
{
	if(_input.pressed(ButtonType::Z))
	{
		if(_nodes->nodes.size() > 0)
		{
			_nodes->nodes[0]->health->heal(10);
		}
	}
	if(_input.pressed(ButtonType::X))
	{
		if(_nodes->nodes.size() > 0)
		{
			_nodes->nodes[0]->health->damage(10);
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
