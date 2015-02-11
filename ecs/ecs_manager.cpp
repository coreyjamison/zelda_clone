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

EcsManager::~EcsManager()
{
	for(auto pair : _nodeLists)
	{
		delete pair.second;
	}
}

void EcsManager::addEntity(Entity* e)
{
	_entities[e->getId()] = e;
	checkNodes(e);
}

void EcsManager::checkNodes(Entity* e)
{
	RenderNode* r = RenderNode::createFrom(e);
	if(r)
	{
		cout << "Added render!" << endl;
		this->_nodeLists[&typeid(RenderNode)]->addNode(r);
	}
	MoveNode* m = MoveNode::createFrom(e);
	if(m)
	{
		cout << "Added move!" << endl;
		this->_nodeLists[&typeid(MoveNode)]->addNode(m);
	}
	CollisionNode* c = CollisionNode::createFrom(e);
	if(c)
	{
		cout << "Added collision!" << endl;
		this->_nodeLists[&typeid(CollisionNode)]->addNode(c);
	}
}

void EcsManager::removeInvalids()
{
	for(auto pair : _nodeLists)
	{
		pair.second->removeInvalids();
	}
}
