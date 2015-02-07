/*
 * entity.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include "entity.hpp"

Entity::Entity(unsigned long id)
:	_id(id)
{}

void Entity::addComponent(Component* c)
{
	c->parentId = _id;
	_components[&typeid(*c)] = c;
}

bool Entity::hasComponent(const type_info* componentType)
{
	return _components.count(componentType) != 0;
}
