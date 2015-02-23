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
#include <data_containers/quad_tree.hpp>
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
#include <systems/ai_command_system.hpp>
#include <graphics/tracking_camera.hpp>
#include <engine/engine.hpp>

using namespace std;
using namespace Enums;

int main(int argc, char* args[])
{
	SdlUtils::init();

	Engine::init();

	cout << "Quad Tree Testing!" << endl;

	class DummyQtObj : public QuadTreeObject
	{
	public:
		DummyQtObj(int id, int x, int y, int w, int h)
		: _id(id), _x(x), _y(y), _w(w), _h(h) {}

		double _id, _x, _y, _w, _h;
		double getLeft() {return _x;}
		double getRight() {return _x+_w;}
		double getTop() {return _y;}
		double getBottom() {return _y+_h;}
	};

	QuadTree<DummyQtObj> qt(0, 3, 2, 0, 0, 1000, 1000);

	//qt.subdivide();

	DummyQtObj o1{1, 0, 0, 10, 10};
	DummyQtObj o2{2, 600, 0, 10, 10};
	DummyQtObj o3(3, 400, 400, 10, 10);

	qt.insert(&o1);
	qt.insert(&o2);
	qt.insert(&o3);

	for(auto pair : qt.getCollisions())
	{
		cout << "Collision between: " << pair.first->_id << " and " <<
				pair.second->_id << endl;
	}


	SDL_Delay(10000);

	Engine& engine = Engine::getInstance();

	engine.getSpriteFactory().loadSprites(engine.getWindow(), "res/sprite_config.json");

	InputManager* im = new InputManager();
	GameLoop* gm = new GameLoop();

	GameWindow& gw = engine.getWindow();
	EcsManager& ecs = engine.getEcsManager();

	TrackingCamera tc{{640, 480}, {640, 480}};

	RenderSystem* render = new RenderSystem(&gw, &tc);
	MoveSystem* move = new MoveSystem();
	UserCommandSystem* ucs = new UserCommandSystem();
	CollisionSystem* col = new CollisionSystem();
	SandboxSystem* sbox = new SandboxSystem();
	AiCommandSystem* ai = new AiCommandSystem();

	render->::NodeSystem<RenderNode>::setNodeList(ecs.getNodeList<RenderNode>());
	render->::NodeSystem<HealthBarNode>::setNodeList(ecs.getNodeList<HealthBarNode>());
	move->setNodeList(ecs.getNodeList<MoveNode>());
	col->setNodeList(ecs.getNodeList<CollisionNode>());
	sbox->setNodeList(ecs.getNodeList<HealthBarNode>());
	ai->setNodeList(ecs.getNodeList<AiCommandNode>());

	engine.getEntityFactory()
			.createPrototypes("res/prototypes.json")
			.populate(&engine.getEcsManager(), "res/entities.json");

	Entity* playerEntity = ecs.getFlaggedEntities("player").front();

	ucs->setPlayerNode(MoveNode::createFrom(playerEntity));
	ai->setPlayerNode(MoveNode::createFrom(playerEntity));
	tc.setNode(TrackingCameraNode::createFrom(playerEntity));

	gm->addFixedRunnable(im);
	gm->addFixedRunnable(render);
	gm->addFixedRunnable(ucs);
	gm->addFixedRunnable(move);
	gm->addFixedRunnable(col);
	gm->addFixedRunnable(sbox);
	gm->addFixedRunnable(ai);
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


