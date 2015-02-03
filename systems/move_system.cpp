/*
 * move_system.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Corey
 */

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

bool MoveSystem::run()
{
	// temp stuff
	if(_nodes.size() == 0) {
		return true;
	}
	MoveNode* node = _nodes.front();
	// TODO input stuff should be pulled out of this system

	Vec2<int> totalMove = {0, 0};

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

	if(totalMove.getDist() > 0)
	{
		node->state->setAction(StateComponent::Action::MOVE);
	} else {
		node->state->setAction(StateComponent::Action::IDLE);
	}

	if(totalMove.y < 0) {
		node->state->setDirection(StateComponent::Direction::UP);
	} else if(totalMove.y > 0) {
		node->state->setDirection(StateComponent::Direction::DOWN);
	} else if(totalMove.x > 0) {
		node->state->setDirection(StateComponent::Direction::RIGHT);
	} else if(totalMove.x < 0) {
		node->state->setDirection(StateComponent::Direction::LEFT);
	}

	node->position->movePos(totalMove.scale(node->move->speed));

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
