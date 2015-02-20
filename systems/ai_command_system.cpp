/*
 * ai_command_system.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Corey
 */


#include "ai_command_system.hpp"

AiCommandSystem::AiCommandSystem()
:	_playerNode(nullptr)
{}

AiCommandSystem::AiCommandSystem(MoveNode* playerNode)
:	_playerNode(playerNode)
{}

void AiCommandSystem::setPlayerNode(MoveNode* playerNode)
{
	_playerNode = playerNode;
}

bool AiCommandSystem::run()
{
	for(AiCommandNode* node : _nodes->nodes)
	{
		Vec2<double> goal = _playerNode->position->curPos - node->position->curPos;

		node->move->goalMove = goal.scale(node->move->speed);
	}

	return true;
}
