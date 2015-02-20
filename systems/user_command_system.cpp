/*
 * user_command_system.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Corey
 */

#include <iostream>
using namespace std;

#include "user_command_system.hpp"

UserCommandSystem::UserCommandSystem()
:	_playerNode{nullptr}, _input{}
{}

UserCommandSystem::UserCommandSystem(MoveNode* playerNode)
:	_playerNode{playerNode}, _input{}
{}

void UserCommandSystem::setPlayerNode(MoveNode* playerNode)
{
	cout << "set player node!" << endl;
	_playerNode = playerNode;
}

bool UserCommandSystem::run()
{
	if(_playerNode)
	{
		Vec2<double> totalMove = {0, 0};

		if(_input.held(ButtonType::W)) {
			totalMove += {0, -1};
		}
		if(_input.held(ButtonType::S)) {
			totalMove += {0, 1};
		}
		if(_input.held(ButtonType::A)) {
			totalMove += {-1, 0};
		}
		if(_input.held(ButtonType::D)) {
			totalMove += {1, 0};
		}

		totalMove = totalMove.scale(_playerNode->move->speed);
		_playerNode->move->goalMove = totalMove;
	}

	return true;
}

void UserCommandSystem::notify(InputState state)
{
	_input = state;
}
