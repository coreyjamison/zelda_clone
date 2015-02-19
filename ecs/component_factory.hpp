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
	PositionComponent* initPositionComponent(rapidjson::Value& config);
	RenderComponent* initRenderComponent(rapidjson::Value& config);
};
/*
template <>
PositionComponent* ComponentFactory::initFrom<PositionComponent>(rapidjson::Value& config);
*/


#endif /* ECS_COMPONENT_FACTORY_HPP_ */
