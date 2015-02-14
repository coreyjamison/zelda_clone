/*
 * engine.hpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Corey
 */

#ifndef ENGINE_ENGINE_HPP_
#define ENGINE_ENGINE_HPP_

#include <unordered_map>

#include <graphics/game_window.hpp>
#include <ecs/ecs_manager.hpp>

class Engine
{
public:
	Engine& getInstance();

	GameWindow& getWindow();
	EcsManager& getEcsManager();

private:
	Engine();

	// Delete these to ensure only one instance.
	Engine(Engine& other) = delete;
	Engine operator=(Engine& other) = delete;

	GameWindow _window;
	EcsManager _ecsManager;
};



#endif /* ENGINE_ENGINE_HPP_ */
