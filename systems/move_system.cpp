/*
 * move_system.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Corey
 */

#include <iostream>

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

MoveSystem::MoveSystem()
:	_nodes(), _input()
{}

bool MoveSystem::run()
{
	for(MoveNode* node : _nodes)
	{
		Vec2<double> goal = node->move->goalMove.scaleBack(node->move->speed);
		node->position->movePos(goal);

		if(goal.getDist() > 0)
		{
			node->state->setAction(StateComponent::Action::MOVE);
		} else {
			node->state->setAction(StateComponent::Action::IDLE);
		}

		if(goal.y < 0) {
			node->state->setDirection(StateComponent::Direction::UP);
		} else if(goal.y > 0) {
			node->state->setDirection(StateComponent::Direction::DOWN);
		} else if(goal.x > 0) {
			node->state->setDirection(StateComponent::Direction::RIGHT);
		} else if(goal.x < 0) {
			node->state->setDirection(StateComponent::Direction::LEFT);
		}
	}
	return true;
}

void MoveSystem::onNodeChange(Node* node)
{
	_nodes.push_back(static_cast<MoveNode*>(node));
}
void MoveSystem::notify(InputState state)
{
	_input = state;
}
