/*
 * component_factory.hpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Corey
 */

#ifndef ECS_COMPONENT_FACTORY_HPP_
#define ECS_COMPONENT_FACTORY_HPP_

#include <iostream>

#include <include/rapidjson/document.h>
#include <ecs/component.hpp>

using namespace std;
class ComponentFactory
{
public:
	Component* initComponent(string type, const rapidjson::Value& config);

	PositionComponent* initPositionComponent(const rapidjson::Value& config);
	RenderComponent* initRenderComponent(const rapidjson::Value& config);
	StateComponent* initStateComponent(const rapidjson::Value& config);
	MoveComponent* initMoveComponent(const rapidjson::Value& config);
	CollisionComponent* initCollisionComponent(const rapidjson::Value& config);
	HealthComponent* initHealthComponent(const rapidjson::Value& config);
};
/*
template <>
PositionComponent* ComponentFactory::initFrom<PositionComponent>(rapidjson::Value& config);
*/


#endif /* ECS_COMPONENT_FACTORY_HPP_ */
