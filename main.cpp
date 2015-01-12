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

using namespace std;

int main(int argc, char* args[])
{
	SdlUtils::init();

	cout << "Hello World!" << endl;

	InputManager* im = new InputManager();
	GameLoop* gm = new GameLoop();

	class DummyRunnable : public FixedRunnable, public InputObserver {
	private:
		InputState _state;

		virtual void notify(InputState state) {
			_state = state;
		}

		virtual bool run() {
			//cout << "Mouse is here: (" << _state.mousePosition.x << ", " << _state.mousePosition.y << ")" << endl;
			if(_state.held(ButtonType::A)) {
				cout << "A Held!" << endl;
			}
			if(_state.pressed(ButtonType::LMOUSE)) {
				cout << "LMB Pressed!" << endl;
			}
			return true;
		}
	};

	SdlWindow* win = new SdlWindow{ "Test!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN };

	DummyRunnable* dr = new DummyRunnable();

	gm->addFixedRunnable(im);
	gm->addFixedRunnable(dr);
	im->addObserver(dr);

	gm->run();

	delete win;
	delete dr;
	delete gm;
	delete im;

	SdlUtils::quit();

	return 0;
}


