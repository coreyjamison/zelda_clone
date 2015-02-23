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
#include "node_list.hpp"

using namespace std;

class EcsManager {
public:
	~EcsManager();

	template<typename T>
	NodeList<T>* getNodeList()
	{
		if(!_nodeLists[&typeid(T)])
		{
			_nodeLists[&typeid(T)] = new NodeList<T>();
		}
		return static_cast<NodeList<T>*>(_nodeLists[&typeid(T)]);
	}

	unsigned int addEntity(Entity* e);
	void checkNodes(Entity* e);
	void checkNodes(unsigned int id);
	void flagEntity(unsigned int id, vector<string> flags);

	vector<Entity*> getFlaggedEntities(string flag);

	unsigned int createEntity();
	Entity* cloneEntity(unsigned int id);
	Entity* getEntity(unsigned int id);

	void removeInvalids();

private:
	unordered_map<unsigned long, Entity*> _entities;
	unordered_map<string, vector<Entity*>> _flaggedEntities;
	unordered_map<const type_info*, NodeListInterface*> _nodeLists;
	long _nextId;
};



#endif /* ECS_MANAGER_HPP_ */
