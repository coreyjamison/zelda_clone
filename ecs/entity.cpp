/*
 * entity.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include "entity.hpp"

Entity::Entity(long id)
:	_id(id)
{}

Entity::~Entity()
{
	for(auto pair : _components)
	{
		delete pair.second;
	}
}

void Entity::setId(long id)
{
	_id = id;
}

void Entity::addComponent(Component* c)
{
	c->parentId = _id;
	_components[&typeid(*c)] = c;
}

Entity* Entity::clone()
{
	Entity* e = new Entity;

	for(auto pair : _components)
	{
		e->addComponent(pair.second->copy());
	}
	return e;
}

bool Entity::hasComponent(const type_info* componentType)
{
	return _components.count(componentType) != 0;
}
