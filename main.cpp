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
#include <systems/user_command_system.hpp>
#include <graphics/tracking_camera.hpp>

using namespace std;

int main(int argc, char* args[])
{
	SdlUtils::init();

	InputManager* im = new InputManager();
	GameLoop* gm = new GameLoop();

	SpriteFactory sf;

	GameWindow gw{"Test!", {640, 480}};

	Sprite testSprite = sf.makeSprite(gw, "slime");
	Sprite bkgSprite = sf.makeSprite(gw, "background");

	Entity e;

	PositionComponent p{{100, 100}};
	RenderComponent r{&testSprite, RenderLayer::ENTITIES};
	StateComponent s{StateComponent::Direction::UP|StateComponent::Action::MOVE};
	MoveComponent m{2};

	e.addComponent(&p);
	e.addComponent(&r);
	e.addComponent(&s);
	e.addComponent(&m);

	Entity bkg;

	// TODO - maybe make multiple sprite types so our background doesn't need
	// a direction and an action
	PositionComponent p_bkg{{0, 0}};
	RenderComponent r_bkg{&bkgSprite, RenderLayer::TERRAIN};
	StateComponent s_bkg{StateComponent::Direction::UP|StateComponent::Action::IDLE};

	bkg.addComponent(&p_bkg);
	bkg.addComponent(&r_bkg);
	bkg.addComponent(&s_bkg);

	TrackingCamera tc{TrackingCameraNode::createFrom(&e), {640, 480}, {640, 480}};

	RenderSystem* render = new RenderSystem(&gw, &tc);
	MoveSystem* move = new MoveSystem(&tc);
	EcsManager* ecs = new EcsManager();
	UserCommandSystem* ucs = new UserCommandSystem();

	ecs->addNodeListener<RenderNode>(render);
	ecs->addNodeListener<MoveNode>(move);
	ecs->addNodeListener<MoveNode>(ucs);
	ecs->addEntity(&e);
	ecs->addEntity(&bkg);

	gm->addFixedRunnable(im);
	gm->addFixedRunnable(render);
	gm->addFixedRunnable(ucs);
	gm->addFixedRunnable(move);

	gm->addVariableRunnable(render);

	im->addObserver(move);
	im->addObserver(ucs);

	gm->run();

	delete render;
	delete move;
	delete ecs;
	delete ucs;
	delete gm;
	delete im;

	SdlUtils::quit();

	return 0;
}


