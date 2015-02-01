/*
 * ecs_manager.hpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#ifndef ECS_MANAGER_HPP_
#define ECS_MANAGER_HPP_

#include <vector>

#include "component.hpp"
#include "entity.hpp"
#include "node.hpp"

using namespace std;

class NodeListener {
	virtual ~NodeListener() = default;

	virtual void onNodeCreate(vector<Node*> nodes) = 0;
	virtual void onNodeDestroy(vector<Node*> nodes) = 0;
};

class EcsManager {


private:
	vector<Entity*> _entities;
	unsigned int _nextId;
};



#endif /* ECS_MANAGER_HPP_ */
