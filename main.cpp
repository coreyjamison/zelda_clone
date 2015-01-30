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

	class DummyAnimator : public VariableRunnable, public FixedRunnable, public InputObserver {
	public:
		DummyAnimator(Sprite& sprite, GameWindow& window)
		:	_sprite( sprite ), _window( window ), count(0)
		{}

		virtual void notify(InputState state) {
			_state = state;
			if(_state.pressed(ButtonType::LMOUSE)) {
				clicked = _state.mousePosition;
			}
		}

		virtual bool run() {
			if(++count > 5000)
			{
				_sprite.tick();
				count = 0;
			}
			cout << "Frame: " << _sprite._frame << endl;
			return true;
		}

		virtual bool run(double alpha) {
			_window.queueRenderable(_sprite.getRenderable(), RenderLayer::ENTITIES, clicked);
			_window.render();
			return true;
		}

	private:
		Sprite& _sprite;
		GameWindow& _window;
		InputState _state;
		int count;
		Vec2<int> clicked;
	};

	DummyRunnable* dr = new DummyRunnable();
	DummyAnimator* da = new DummyAnimator(testSprite, gw);

	gm->addFixedRunnable(im);
	//gm->addFixedRunnable(dr);
	gm->addFixedRunnable(da);
	gm->addVariableRunnable(da);
	//im->addObserver(dr);
	im->addObserver(da);

	gm->run();

	//delete win;
	delete dr;
	delete da;
	delete gm;
	delete im;

	SdlUtils::quit();

	return 0;
}


