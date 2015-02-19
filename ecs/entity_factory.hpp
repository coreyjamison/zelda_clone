/*
 * entity_factory.hpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Corey
 */

#ifndef ECS_ENTITY_FACTORY_HPP_
#define ECS_ENTITY_FACTORY_HPP_

#include <unordered_map>

#include <include/rapidjson/document.h>

#include "ecs_manager.hpp"
#include "component_factory.hpp"


using namespace std;
using namespace rapidjson;
class EntityFactory
{
public:
	EntityFactory& populate(EcsManager* ecs, string entityFile);
	EntityFactory& createPrototypes(string prototypeConfig);
	Entity* createEntity(const Value& config);

private:
	ComponentFactory _componentFactory;
	unsigned int _nextPrototypeId = 1;
	unordered_map<string, unsigned int> _prototypeIds;
	unordered_map<unsigned int, Entity*> _prototypes;
};



#endif /* ECS_ENTITY_FACTORY_HPP_ */
