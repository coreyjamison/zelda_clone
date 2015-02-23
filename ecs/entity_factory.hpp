/*
 * entity_factory.hpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Corey
 */

#ifndef ECS_ENTITY_FACTORY_HPP_
#define ECS_ENTITY_FACTORY_HPP_

#include <unordered_map>
#include <vector>

#include <include/rapidjson/document.h>

#include "ecs_manager.hpp"
#include "component_factory.hpp"


using namespace std;
using namespace rapidjson;

/* TODO: Think of a better way to do this */
/*
 * Contains configuration used to create an entity at runtime
 * without needing to create a json document in code.
 */
struct EntityConfig
{
	string prototype;
	Vec2<double> position;
	vector<Component*> components;
};

class EntityFactory
{
public:
	EntityFactory& populate(EcsManager* ecs, string entityFile);
	EntityFactory& createPrototypes(string prototypeConfig);
	Entity* createEntity(const Value& config);
	Entity* createEntity(const EntityConfig& config);

private:
	ComponentFactory _componentFactory;
	unsigned int _nextPrototypeId = 1;
	unordered_map<string, unsigned int> _prototypeIds;
	unordered_map<unsigned int, Entity*> _prototypes;
};



#endif /* ECS_ENTITY_FACTORY_HPP_ */
