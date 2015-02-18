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
#include <effect/effect_system.hpp>

using namespace std;
class Engine
{
public:
	static Engine& getInstance();

	GameWindow& getWindow();
	EcsManager& getEcsManager();
	EffectSystem& getEffectSystem();

	void loadSprites(string configFile);

private:
	Engine();

	// Delete these to ensure only one instance.
	Engine(Engine& other) = delete;
	Engine operator=(Engine& other) = delete;

	GameWindow _window;
	EcsManager _ecsManager;
	EffectSystem _effectSystem;

	unordered_map<string, Sprite*> _sprites;
};



#endif /* ENGINE_ENGINE_HPP_ */
