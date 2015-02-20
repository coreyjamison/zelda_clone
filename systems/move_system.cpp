/*
 * move_system.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Corey
 */

#include <iostream>
#include <cmath>

#include <data_containers/enums.hpp>

#include "move_system.hpp"
/*
class MoveSystem: public FixedRunnable, public NodeListener, public InputObserver
{
public:
	virtual bool run();
	virtual void onNodeChange(Node* node);
	virtual void notify(InputState state);

private:
	vector<MoveNode*> _nodes;
	InputState _input;
};*/

using namespace std;
using namespace Enums;

MoveSystem::MoveSystem()
:	_input()
{}

bool MoveSystem::run()
{
	for(MoveNode* node : _nodes->nodes)
	{
		Vec2<double> goal = node->move->goalMove.scaleBack(node->move->speed);
		node->position->movePos(goal);
		node->move->goalMove = {0, 0};

		if(goal.length() > 0)
		{
			node->state->setAction(Action::MOVE);
		} else {
			node->state->setAction(Action::IDLE);
		}
		if(goal.x != 0 || goal.y != 0)
		{
			if(abs(goal.x) > abs(goal.y))
			{
				if(goal.x > 0)
					node->state->setDirection(Direction::RIGHT);
				else
					node->state->setDirection(Direction::LEFT);
			}
			else
			{
				if(goal.y < 0)
					node->state->setDirection(Direction::UP);
				else
					node->state->setDirection(Direction::DOWN);
			}
		}
	}
	return true;
}

void MoveSystem::notify(InputState state)
{
	_input = state;
}
