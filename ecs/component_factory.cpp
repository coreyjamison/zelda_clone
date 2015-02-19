/*
 * component_factory.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Corey
 */

#include "component_factory.hpp"
#include "component.hpp"
#include <graphics/game_window.hpp>
#include <engine/engine.hpp>

using namespace rapidjson;
PositionComponent* ComponentFactory::initPositionComponent(Value& config)
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

RenderComponent* ComponentFactory::initRenderComponent(Value& config)
{
	if(config.HasMember("name") &&
			config.HasMember("layer"))
	{
		SpriteFactory& sf = Engine::getInstance().getSpriteFactory();
		unsigned int spriteId = sf.getId(config["name"].GetString());
		Sprite* sprite = sf.getSprite(spriteId);
		RenderLayer l;
		string layer = config["layer"].GetString();
		if(layer == "entities") {
			l = RenderLayer::ENTITIES;
		} else if(layer == "terrain") {
			l = RenderLayer::TERRAIN;
		}
		return new RenderComponent(sprite, l);
	}
	return nullptr;
}
