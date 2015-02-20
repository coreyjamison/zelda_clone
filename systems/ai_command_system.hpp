/*
 * ai_command_system.hpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Corey
 */

#ifndef SYSTEMS_AI_COMMAND_SYSTEM_HPP_
#define SYSTEMS_AI_COMMAND_SYSTEM_HPP_

#include <gameloop/runnable.hpp>
#include <ecs/node_system.hpp>


class AiCommandSystem : public FixedRunnable, public NodeSystem<AiCommandNode>
{
public:
	AiCommandSystem();
	AiCommandSystem(MoveNode* playerNode);

	void setPlayerNode(MoveNode* playerNode);

	virtual bool run();
private:
	MoveNode* _playerNode;
};



#endif /* SYSTEMS_AI_COMMAND_SYSTEM_HPP_ */
