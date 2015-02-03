/*
 * main.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Corey
 */
#include <SDLutil/sdl_utils.hpp>
#include <iostream>

#include <input_manager/input_manager.hpp>
#include <gameloop/gameloop.hpp>
#include <SDLutil/sdl_wrappers.hpp>
#include <graphics/sprite_factory.hpp>
#include <graphics/game_window.hpp>
#include <graphics/render_system.hpp>
#include <ecs/component.hpp>
#include <ecs/entity.hpp>
#include <ecs/ecs_manager.hpp>
#include <systems/move_system.hpp>

using namespace std;

int main(int argc, char* args[])
{
	SdlUtils::init();

	InputManager* im = new InputManager();
	GameLoop* gm = new GameLoop();

	SpriteFactory sf;

	GameWindow gw{"Test!", {640, 480}};

	Sprite testSprite = sf.makeSprite(gw, "guy1");

	Entity e;

	PositionComponent p{{100, 100}};
	RenderComponent r{&testSprite};
	StateComponent s{StateComponent::Direction::UP|StateComponent::Action::MOVE};
	MoveComponent m{2};

	e.addComponent(&p);
	e.addComponent(&r);
	e.addComponent(&s);
	e.addComponent(&m);

	RenderSystem* render = new RenderSystem(&gw);
	MoveSystem* move = new MoveSystem();
	EcsManager* ecs = new EcsManager();

	ecs->addNodeListener<RenderNode>(render);
	ecs->addNodeListener<MoveNode>(move);
	ecs->addEntity(&e);

	gm->addFixedRunnable(im);
	gm->addFixedRunnable(render);
	gm->addFixedRunnable(move);

	gm->addVariableRunnable(render);

	im->addObserver(move);

	gm->run();

	delete render;
	delete move;
	delete ecs;
	delete gm;
	delete im;

	SdlUtils::quit();

	return 0;
}


