/*
 * entity.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include "entity.hpp"

void Entity::addComponent(Component* c)
{
	_components[&typeid(*c)] = c;
}
