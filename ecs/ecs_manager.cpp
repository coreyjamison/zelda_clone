/*
 * ecs_manager.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: Corey
 */

#include <iostream>

#include "ecs_manager.hpp"

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
	for(auto pair : _nodeLists)
	{
		pair.second->addNodeFromEntity(e);
	}
}

void EcsManager::checkNodes(unsigned int id)
{
	if(_entities.find(id) != _entities.end())
	{
		checkNodes(_entities[id]);
	}
}

void EcsManager::removeInvalids()
{
	for(auto pair : _nodeLists)
	{
		pair.second->removeInvalids();
	}
}


Entity* EcsManager::createEntity()
{
	Entity* newEntity = new Entity{_nextId};
	_entities[_nextId++] = newEntity;

	return newEntity;
}

Entity* EcsManager::cloneEntity(unsigned int id)
{
	if(_entities.find(id) != _entities.end())
	{
		Entity* newEntity = _entities[id]->clone();
		newEntity->setId(_nextId);
		_entities[_nextId++] = newEntity;
		return newEntity;
	}
	return nullptr;
}

Entity* EcsManager::getEntity(unsigned int id)
{
	if(_entities.find(id) != _entities.end())
	{
		return _entities[id];
	}
	else
	{
		return nullptr;
	}
}
