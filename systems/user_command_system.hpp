/*
 * user_command_system.hpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Corey
 */

#ifndef USER_COMMAND_SYSTEM_HPP_
#define USER_COMMAND_SYSTEM_HPP_

#include <gameloop/runnable.hpp>
#include <input_manager/input_observer.hpp>
#include <input_manager/input_manager.hpp>
#include <ecs/node.hpp>
#include <ecs/ecs_manager.hpp>

class UserCommandSystem : public FixedRunnable, public InputObserver, public NodeListener
{
public:
	UserCommandSystem();
	UserCommandSystem(MoveNode* playerNode);

	void setPlayerNode(MoveNode* playerNode);

	virtual bool run();
	virtual void notify(InputState state);
	virtual void onNodeChange(Node* node);

private:
	MoveNode* _playerNode;
	InputState _input;
};



#endif /* USER_COMMAND_SYSTEM_HPP_ */
