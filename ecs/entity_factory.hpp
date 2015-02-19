/*
 * entity_factory.hpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Corey
 */

#ifndef ECS_ENTITY_FACTORY_HPP_
#define ECS_ENTITY_FACTORY_HPP_


#include "ecs_manager.hpp"

using namespace std;
class EntityFactory
{
public:
	static void populate(EcsManager* ecs, string entityFile);
};



#endif /* ECS_ENTITY_FACTORY_HPP_ */
