/*
 * sandbox_system.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Corey
 */

#include "sandbox_system.hpp"

bool SandboxSystem::run()
{
	return true;
}

void SandboxSystem::notify(InputState state)
{
	_input = state;
}
