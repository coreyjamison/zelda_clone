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
#include <ecs/node_list.hpp>
#include <ecs/node.hpp>

class CollisionSystem : public FixedRunnable
{
public:
	void setNodeList(NodeList<CollisionNode>* nodes);

	virtual bool run();

private:
	NodeList<CollisionNode>* _nodes;
};



#endif /* SYSTEMS_COLLISION_SYSTEM_HPP_ */
