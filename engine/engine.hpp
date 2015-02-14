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

using namespace std;
class Engine
{
public:
	Engine& getInstance();

	GameWindow& getWindow();
	EcsManager& getEcsManager();

	void loadSprites(string configFile);

private:
	Engine();

	// Delete these to ensure only one instance.
	Engine(Engine& other) = delete;
	Engine operator=(Engine& other) = delete;

	GameWindow _window;
	EcsManager _ecsManager;

	unordered_map<string, Sprite*> _sprites;
};



#endif /* ENGINE_ENGINE_HPP_ */
