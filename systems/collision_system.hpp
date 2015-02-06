/*
 * collision_system.hpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Corey
 */

#ifndef SYSTEMS_COLLISION_SYSTEM_HPP_
#define SYSTEMS_COLLISION_SYSTEM_HPP_

#include <vector>

#include <gameloop/runnable.hpp>
#include <ecs/ecs_manager.hpp>
#include <ecs/node.hpp>

class CollisionSystem : public FixedRunnable, public NodeListener
{
public:
	virtual bool run();
	virtual void onNodeChange(Node* node);

private:
	vector<CollisionNode*> _nodes;
};



#endif /* SYSTEMS_COLLISION_SYSTEM_HPP_ */
