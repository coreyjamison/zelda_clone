/*
 * sandbox_system.hpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Corey
 */

#ifndef SANDBOX_SYSTEM_HPP_
#define SANDBOX_SYSTEM_HPP_

#include <ecs/node_system.hpp>
#include <gameloop/runnable.hpp>
#include <input_manager/input_observer.hpp>
#include <input_manager/input_manager.hpp>

/* This is where temporary prototype code goes while we figure out a good home for it */
class SandboxSystem : public FixedRunnable, public InputObserver, public NodeSystem<HealthBarNode>
{
public:
	virtual bool run();
	virtual void notify(InputState state);

private:
	InputState _input;
};



#endif /* SANDBOX_SYSTEM_HPP_ */
