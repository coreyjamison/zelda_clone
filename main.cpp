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


using namespace std;

int main(int argc, char* args[])
{
	SdlUtils::init();

	cout << "Hello World!" << endl;

	InputManager* im = new InputManager();
	GameLoop* gm = new GameLoop();

	SpriteFactory sf;

	GameWindow gw{"Test!", {640, 480}};

	cout << "Done Test!" << endl;

	//SdlWindow* win = new SdlWindow{ "Test!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN };

	cout << "Making Sprite!" << endl;

	Sprite testSprite = sf.makeDemoSprite(gw);

	cout << "Queuing render!" << endl;

	gw.queueRenderable(testSprite.getRenderable(), RenderLayer::ENTITIES, {50,50});

	cout << "Rendering!" << endl;

	gw.render();

	cout << "Done Rendering!" << endl;

	Entity e;
	PositionComponent p{{100, 100}};
	RenderComponent r{&testSprite};
	e.addComponent(&p);
	e.addComponent(&r);

	class DummyRunnable : public FixedRunnable, public InputObserver {
	public:
		virtual void notify(InputState state) {
			_state = state;
		}

		virtual bool run() {
			cout << "Mouse is here: (" << _state.mousePosition.x << ", " << _state.mousePosition.y << ")" << endl;
			if(_state.held(ButtonType::A)) {
				cout << "A Held!" << endl;
			}
			if(_state.pressed(ButtonType::LMOUSE)) {
				cout << "LMB Pressed!" << endl;
			}
			return true;
		}
	private:
		InputState _state;

	};

	class DummyAnimator : public FixedRunnable, public InputObserver {
	public:
		DummyAnimator(RenderNode* node)
		:	_node( node ), count(0)
		{}

		virtual void notify(InputState state) {
			_state = state;
			if(_state.pressed(ButtonType::LMOUSE)) {
				clicked = _state.mousePosition;
			}
		}

		virtual bool run() {
			if(++count > 2)
			{
				if(_state.held(ButtonType::W)) {
					_node->position->movePos({0,-4});
					_node->render->sprite->setState(0);
					cout << "W" << endl;
				}
				if(_state.held(ButtonType::S)) {
					_node->position->movePos({0,4});
					_node->render->sprite->setState(1);
					cout << "S" << endl;
				}
				if(_state.held(ButtonType::A)) {
					_node->position->movePos({-4,0});
					_node->render->sprite->setState(3);
				}
				if(_state.held(ButtonType::D)) {
					_node->position->movePos({4,0});
					_node->render->sprite->setState(2);
				}
				count = 0;
			}
			return true;
		}

	private:
		RenderNode* _node;
		InputState _state;
		int count;
		Vec2<int> clicked;
	};

	DummyRunnable* dr = new DummyRunnable();
	DummyAnimator* da = new DummyAnimator(RenderNode::createFrom(&e));
	RenderSystem* render = new RenderSystem(&gw);

	render->addNode(RenderNode::createFrom(&e));

	gm->addFixedRunnable(im);
	//gm->addFixedRunnable(dr);
	gm->addFixedRunnable(da);

	gm->addFixedRunnable(render);
	gm->addVariableRunnable(render);

	//im->addObserver(dr);
	im->addObserver(da);

	gm->run();

	//delete win;
	delete render;
	delete dr;
	delete da;
	delete gm;
	delete im;


	SdlUtils::quit();

	return 0;
}


