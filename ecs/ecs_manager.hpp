/*
 * ecs_manager.hpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#ifndef ECS_MANAGER_HPP_
#define ECS_MANAGER_HPP_

#include <vector>
#include <unordered_map>

#include "component.hpp"
#include "entity.hpp"
#include "node.hpp"

using namespace std;

class NodeListener {
public:
	virtual ~NodeListener() = default;

	virtual void onNodeChange(Node* node) = 0;
};

class EcsManager {
public:
	template<typename T>
	void addNodeListener(NodeListener* listener)
	{
		_nodeListeners[&typeid(T)].push_back(listener);
	}

	void addEntity(Entity* e);

	void checkNodes(Entity* e);

private:
	unordered_map<unsigned long, Entity*> _entities;
	unordered_map<const type_info*, vector<NodeListener*>> _nodeListeners;
	unsigned int _nextId;
};



#endif /* ECS_MANAGER_HPP_ */
