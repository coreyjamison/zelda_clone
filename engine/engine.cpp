/*
 * engine.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Corey
 */

#include "engine.hpp"

Engine::Engine()
:	_window("Test!", {640, 480})
{

}

void Engine::init()
{
	getInstance();
}

Engine& Engine::getInstance()
{
	static Engine instance{};
	return instance;
}

GameWindow& Engine::getWindow()
{
	return _window;
}

EcsManager& Engine::getEcsManager()
{
	return _ecsManager;
}

EffectSystem& Engine::getEffectSystem()
{
	return _effectSystem;
}

SpriteFactory& Engine::getSpriteFactory()
{
	return _spriteFactory;
}

