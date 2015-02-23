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

unsigned int EcsManager::addEntity(Entity* e)
{
	if(e->getId() == -1)
	{
		cout << "Setting entity id to " << _nextId << endl;
		e->setId(_nextId++);
	}
	_entities[e->getId()] = e;
	checkNodes(e);
	return e->getId();
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

void EcsManager::flagEntity(unsigned int id, vector<string> flags)
{
	cout << "trying to flag entity " << id << endl;
	if(_entities.find(id) != _entities.end())
	{
		for(string flag : flags)
		{
			//if(_flaggedEntities.find(flag) != _flaggedEntities.end())
			//{
				cout << "Entity " << id << " flagged as \"" << flag << "\"" << endl;
				_flaggedEntities[flag].push_back(_entities[id]);
			//}
		}
	}
	else
	{
		cout << "didn't find entity!" << endl;
	}
}

vector<Entity*> EcsManager::getFlaggedEntities(string flag)
{
	if(_flaggedEntities.find(flag) != _flaggedEntities.end())
	{
		return _flaggedEntities[flag];
	}
	else
	{
		return {};
	}
}

void EcsManager::removeInvalids()
{
	for(auto pair : _nodeLists)
	{
		pair.second->removeInvalids();
	}
}


unsigned int EcsManager::createEntity()
{
	Entity* newEntity = new Entity{_nextId};
	_entities[_nextId] = newEntity;

	return _nextId++;
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
