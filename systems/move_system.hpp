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
#include <input_manager/input_observer.hpp>
#include <input_manager/input_manager.hpp>
#include <graphics/camera.hpp>

class MoveSystem: public FixedRunnable, public InputObserver
{
public:
	MoveSystem();

	void setNodeList(NodeList<MoveNode>* nodes);

	virtual bool run();
	virtual void notify(InputState state);

private:
	NodeList<MoveNode>* _nodes;
	InputState _input;
};



#endif /* MOVE_SYSTEM_HPP_ */
