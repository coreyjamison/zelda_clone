/*
 * component_factory.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Corey
 */

#include "component_factory.hpp"
#include "component.hpp"


PositionComponent* ComponentFactory::initFrom2(rapidjson::Value& config)
{
	if(config.HasMember("x") &&
			config.HasMember("y"))
	{
		Vec2<double> position = {
				config["x"].GetDouble(),
				config["y"].GetDouble()
		};
		return new PositionComponent(position);
	}
	return nullptr;
}
