/*
 * move_system.hpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Corey
 */

#ifndef MOVE_SYSTEM_HPP_
#define MOVE_SYSTEM_HPP_

#include <vector>

#include <gameloop/runnable.hpp>
#include <ecs/ecs_manager.hpp>
#include <ecs/node.hpp>
#include <ecs/node_system.hpp>
#include <input_manager/input_observer.hpp>
#include <input_manager/input_manager.hpp>
#include <graphics/camera.hpp>

class MoveSystem: public FixedRunnable, public InputObserver, public NodeSystem<MoveNode>
{
public:
	MoveSystem();

	virtual bool run();
	virtual void notify(InputState state);

private:
	InputState _input;
};



#endif /* MOVE_SYSTEM_HPP_ */
