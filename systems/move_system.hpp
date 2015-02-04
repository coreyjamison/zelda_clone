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

class MoveSystem: public FixedRunnable, public NodeListener, public InputObserver
{
public:
	virtual bool run();
	virtual void onNodeChange(Node* node);
	virtual void notify(InputState state);

private:
	vector<MoveNode*> _nodes;
	InputState _input;
};



#endif /* MOVE_SYSTEM_HPP_ */