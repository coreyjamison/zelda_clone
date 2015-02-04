/*
 * ecs_manager.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: Corey
 */

#include <iostream>

#include "ecs_manager.hpp"

/*class EcsManager {
public:
	template<typename T>
	void addNodeListener(NodeListener* listener);

	void addEntity(Entity* e);

	void checkNodes(Entity* e);

private:
	vector<Entity*> _entities;
	unordered_map<type_info*, NodeListener*> _nodeListeners;
	unsigned int _nextId;
};*/

using namespace std;

void EcsManager::addEntity(Entity* e)
{
	_entities.push_back(e);
	checkNodes(e);
}

void EcsManager::checkNodes(Entity* e)
{
	RenderNode* r = RenderNode::createFrom(e);
	if(r)
	{
		for(NodeListener* l : _nodeListeners[&typeid(RenderNode)])
		{
			cout << "Render Node!" << endl;
			l->onNodeChange(r);
		}
	}
	MoveNode* m = MoveNode::createFrom(e);
	if(m)
	{
		for(NodeListener* l : _nodeListeners[&typeid(MoveNode)])
		{
			cout << "Move Node!" << endl;
			l->onNodeChange(m);
		}
	}
}
