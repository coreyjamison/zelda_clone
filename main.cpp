/*
 * main.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Corey
 */
#include <SDLutil/sdl_utils.hpp>
#include <iostream>

#include <data_containers/enums.hpp>
#include <data_containers/vec2.hpp>
#include <input_manager/input_manager.hpp>
#include <gameloop/gameloop.hpp>
#include <SDLutil/sdl_wrappers.hpp>
#include <graphics/sprite_factory.hpp>
#include <graphics/game_window.hpp>
#include <graphics/render_system.hpp>
#include <ecs/component.hpp>
#include <ecs/entity.hpp>
#include <ecs/ecs_manager.hpp>
#include <ecs/component_factory.hpp>
#include <systems/move_system.hpp>
#include <systems/user_command_system.hpp>
#include <systems/collision_system.hpp>
#include <systems/sandbox_system.hpp>
#include <graphics/tracking_camera.hpp>
#include <engine/engine.hpp>

using namespace std;
using namespace Enums;

int main(int argc, char* args[])
{
	SdlUtils::init();

	Engine::init();

	Engine& engine = Engine::getInstance();

	engine.getSpriteFactory().loadSprites(engine.getWindow(), "res/sprite_config.json");

	InputManager* im = new InputManager();
	GameLoop* gm = new GameLoop();

	GameWindow& gw = Engine::getInstance().getWindow();
	EcsManager& ecs = Engine::getInstance().getEcsManager();

	TrackingCamera tc{{640, 480}, {640, 480}};

	RenderSystem* render = new RenderSystem(&gw, &tc);
	MoveSystem* move = new MoveSystem();
	UserCommandSystem* ucs = new UserCommandSystem();
	CollisionSystem* col = new CollisionSystem();
	SandboxSystem* sbox = new SandboxSystem();

	render->::NodeSystem<RenderNode>::setNodeList(ecs.getNodeList<RenderNode>());
	render->::NodeSystem<HealthBarNode>::setNodeList(ecs.getNodeList<HealthBarNode>());
	move->setNodeList(ecs.getNodeList<MoveNode>());
	col->setNodeList(ecs.getNodeList<CollisionNode>());
	sbox->setNodeList(ecs.getNodeList<HealthBarNode>());

	engine.getEntityFactory()
			.createPrototypes("res/prototypes.json")
			.populate(&engine.getEcsManager(), "res/entities.json");

	Entity* playerEntity = ecs.getFlaggedEntities("player").front();

	ucs->setPlayerNode(MoveNode::createFrom(playerEntity));
	tc.setNode(TrackingCameraNode::createFrom(playerEntity));\

	gm->addFixedRunnable(im);
	gm->addFixedRunnable(render);
	gm->addFixedRunnable(ucs);
	gm->addFixedRunnable(move);
	gm->addFixedRunnable(col);
	gm->addFixedRunnable(sbox);
	gm->addFixedRunnable(&Engine::getInstance().getEffectSystem());

	gm->addVariableRunnable(render);

	im->addObserver(move);
	im->addObserver(ucs);
	im->addObserver(sbox);

	gm->run();

	delete render;
	delete move;
	delete ucs;
	delete gm;
	delete im;
	delete col;
	delete sbox;

	SdlUtils::quit();

	return 0;
}


