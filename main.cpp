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
#include <systems/collision_system.hpp>
#include <systems/sandbox_system.hpp>
#include <graphics/tracking_camera.hpp>
#include <engine/engine.hpp>

using namespace std;

int main(int argc, char* args[])
{
	SdlUtils::init();

	InputManager* im = new InputManager();
	GameLoop* gm = new GameLoop();

	SpriteFactory sf;

	GameWindow gw{"Test!", {640, 480}};

	Sprite guySprite = sf.makeSprite(gw, "guy1");
	Sprite slimeSprite = sf.makeSprite(gw, "slime");
	Sprite bkgSprite = sf.makeSprite(gw, "background");

	EcsManager* ecs = Engine::getInstance().getEcsManager();

	Entity* e = ecs->createEntity();

	PositionComponent p{{100, 100}};
	RenderComponent r{&guySprite, RenderLayer::ENTITIES};
	StateComponent s{StateComponent::Direction::RIGHT|StateComponent::Action::IDLE};
	MoveComponent m{2};
	CollisionComponent c{{25, 15}, CollisionComponent::ENTITY, CollisionComponent::ENTITY, 1};
	HealthComponent h{50, 100};

	e->addComponent(&p);
	e->addComponent(&r);
	e->addComponent(&s);
	e->addComponent(&m);
	e->addComponent(&c);
	e->addComponent(&h);

	Entity* slime = ecs->createEntity();

	PositionComponent ps{{400, 400}};
	RenderComponent rs{&slimeSprite, RenderLayer::ENTITIES};
	StateComponent ss{StateComponent::Direction::DOWN|StateComponent::Action::IDLE};
	MoveComponent ms{2};
	CollisionComponent cs{{25, 15}, CollisionComponent::ENTITY, 0, 1};
	HealthComponent hs{20, 25};

	slime->addComponent(&ps);
	slime->addComponent(&rs);
	slime->addComponent(&ss);
	slime->addComponent(&ms);
	slime->addComponent(&cs);
	slime->addComponent(&hs);

	Entity* bkg = ecs->createEntity();

	// TODO - maybe make multiple sprite types so our background doesn't need
	// a direction and an action
	PositionComponent p_bkg{{0, 0}};
	RenderComponent r_bkg{&bkgSprite, RenderLayer::TERRAIN};
	StateComponent s_bkg{StateComponent::Direction::UP|StateComponent::Action::IDLE};

	bkg->addComponent(&p_bkg);
	bkg->addComponent(&r_bkg);
	bkg->addComponent(&s_bkg);

	TrackingCamera tc{TrackingCameraNode::createFrom(slime), {640, 480}, {640, 480}};

	RenderSystem* render = new RenderSystem(&gw, &tc);
	MoveSystem* move = new MoveSystem();
	UserCommandSystem* ucs = new UserCommandSystem();
	CollisionSystem* col = new CollisionSystem();
	SandboxSystem* sbox = new SandboxSystem();
	EffectSystem* fx = Engine::getInstance().getEffectSystem();

	//ecs->addNodeListener<RenderNode>(render);
	//ecs->addNodeListener<MoveNode>(move);
	//ecs->addNodeListener<MoveNode>(ucs);
	//ecs->addNodeListener<CollisionNode>(col);
	render->::NodeSystem<RenderNode>::setNodeList(ecs->getNodeList<RenderNode>());
	render->::NodeSystem<HealthBarNode>::setNodeList(ecs->getNodeList<HealthBarNode>());
	move->setNodeList(ecs->getNodeList<MoveNode>());
	col->setNodeList(ecs->getNodeList<CollisionNode>());
	sbox->setNodeList(ecs->getNodeList<HealthBarNode>());

	ucs->setPlayerNode(MoveNode::createFrom(slime));

	ecs->checkNodes(e);
	ecs->checkNodes(slime);
	ecs->checkNodes(bkg);

	gm->addFixedRunnable(im);
	gm->addFixedRunnable(render);
	gm->addFixedRunnable(ucs);
	gm->addFixedRunnable(move);
	gm->addFixedRunnable(col);
	gm->addFixedRunnable(sbox);
	gm->addFixedRunnable(fx);

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


