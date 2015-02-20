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
#include <data_containers/enums.hpp>

using namespace rapidjson;
Component* ComponentFactory::initComponent(string type, const Value& config)
{
	if(type == "position")
		return initPositionComponent(config);
	else if(type == "render")
		return initRenderComponent(config);
	else if(type == "state")
		return initStateComponent(config);
	else if(type == "move")
		return initMoveComponent(config);
	else if(type == "collision")
		return initCollisionComponent(config);
	else if(type == "health")
		return initHealthComponent(config);
	else if(type == "ai_command")
		return initAiCommandComponent(config);
	else
		return nullptr;
}

PositionComponent* ComponentFactory::initPositionComponent(const Value& config)
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

RenderComponent* ComponentFactory::initRenderComponent(const Value& config)
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

StateComponent* ComponentFactory::initStateComponent(const Value& config)
{
	if(config.HasMember("action") &&
			config.HasMember("direction"))
	{
		string action = config["action"].GetString();
		string direction = config["direction"].GetString();

		using namespace Enums;
		Action a = actionFromString(action);
		Direction d = directionFromString(direction);
		return new StateComponent(a | d);
	}
	return nullptr;
}

MoveComponent* ComponentFactory::initMoveComponent(const Value& config)
{
	if(config.HasMember("speed"))
	{
		double speed = config["speed"].GetDouble();
		return new MoveComponent(speed);
	}
	return nullptr;
}

CollisionComponent* ComponentFactory::initCollisionComponent(const Value& config)
{
	if(config.HasMember("w") &&
			config.HasMember("h") &&
			config.HasMember("type") &&
			config.HasMember("mask") &&
			config.HasMember("team") &&
			config.HasMember("weight"))
	{
		Vec2<double> size = {
				config["w"].GetDouble(),
				config["h"].GetDouble()
		};
		unsigned int type = collisionTypeFromString(config["type"].GetString());
		unsigned int mask = collisionMaskFromString(config["mask"].GetString());

		cout << "type: " << type << "  mask: " << mask << endl;

		unsigned int weight = config["weight"].GetInt();
		unsigned int team = config["team"].GetInt();

		return new CollisionComponent(size, type, mask, weight, team);
	}
	return nullptr;
}

HealthComponent* ComponentFactory::initHealthComponent(const Value& config)
{
	if(config.HasMember("hp") &&
			config.HasMember("max"))
	{
		unsigned int hp = config["hp"].GetInt();
		unsigned int maxHp = config["max"].GetInt();

		return new HealthComponent(hp, maxHp);
	}
	return nullptr;
}

AiCommandComponent* ComponentFactory::initAiCommandComponent(const Value& config)
{
	return new AiCommandComponent();
}
