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
#include <ecs/node_system.hpp>
#include <ecs/node.hpp>

class CollisionSystem : public FixedRunnable, public NodeSystem<CollisionNode>
{
public:
	virtual bool run();
};



#endif /* SYSTEMS_COLLISION_SYSTEM_HPP_ */
