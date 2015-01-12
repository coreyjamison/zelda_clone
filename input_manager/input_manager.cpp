/*
 * input_manager.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Corey
 */

#include "input_manager.hpp"
#include <SDL_keycode.h>
#include <SDL_keyboard.h>
#include <SDL_events.h>
#include <SDL_mouse.h>

#include <iostream>

using namespace std;

map<int, ButtonType> InputManager::_scanCodes = {
		{ SDL_SCANCODE_0, ButtonType::ZERO },
		{ SDL_SCANCODE_1, ButtonType::ONE },
		{ SDL_SCANCODE_2, ButtonType::TWO },
		{ SDL_SCANCODE_3, ButtonType::THREE },
		{ SDL_SCANCODE_4, ButtonType::FOUR },
		{ SDL_SCANCODE_5, ButtonType::FIVE },
		{ SDL_SCANCODE_6, ButtonType::SIX },
		{ SDL_SCANCODE_7, ButtonType::SEVEN },
		{ SDL_SCANCODE_8, ButtonType::EIGHT },
		{ SDL_SCANCODE_9, ButtonType::NINE },
		{ SDL_SCANCODE_A, ButtonType::A },
		{ SDL_SCANCODE_B, ButtonType::B },
		{ SDL_SCANCODE_C, ButtonType::C },
		{ SDL_SCANCODE_D, ButtonType::D },
		{ SDL_SCANCODE_E, ButtonType::E },
		{ SDL_SCANCODE_F, ButtonType::F },
		{ SDL_SCANCODE_G, ButtonType::G },
		{ SDL_SCANCODE_H, ButtonType::H },
		{ SDL_SCANCODE_I, ButtonType::I },
		{ SDL_SCANCODE_J, ButtonType::J },
		{ SDL_SCANCODE_K, ButtonType::K },
		{ SDL_SCANCODE_L, ButtonType::L },
		{ SDL_SCANCODE_M, ButtonType::M },
		{ SDL_SCANCODE_N, ButtonType::N },
		{ SDL_SCANCODE_O, ButtonType::O },
		{ SDL_SCANCODE_P, ButtonType::P },
		{ SDL_SCANCODE_Q, ButtonType::Q },
		{ SDL_SCANCODE_R, ButtonType::R },
		{ SDL_SCANCODE_S, ButtonType::S },
		{ SDL_SCANCODE_T, ButtonType::T },
		{ SDL_SCANCODE_U, ButtonType::U },
		{ SDL_SCANCODE_V, ButtonType::V },
		{ SDL_SCANCODE_W, ButtonType::W },
		{ SDL_SCANCODE_X, ButtonType::X },
		{ SDL_SCANCODE_Y, ButtonType::Y },
		{ SDL_SCANCODE_Z, ButtonType::Z },
		{ SDL_SCANCODE_SPACE, ButtonType::SPACE },
		{ SDL_SCANCODE_LSHIFT, ButtonType::LSHIFT },
		{ SDL_SCANCODE_LCTRL, ButtonType::LCTRL },
		{ SDL_SCANCODE_RSHIFT, ButtonType::RSHIFT },
		{ SDL_SCANCODE_RCTRL, ButtonType::RCTRL },
		{ SDL_SCANCODE_ESCAPE, ButtonType::ESCAPE }
};

map<int, ButtonType> InputManager::_actionCodes = {
		{ SDLK_0, ButtonType::ZERO },
		{ SDLK_1, ButtonType::ONE },
		{ SDLK_2, ButtonType::TWO },
		{ SDLK_3, ButtonType::THREE },
		{ SDLK_4, ButtonType::FOUR },
		{ SDLK_5, ButtonType::FIVE },
		{ SDLK_6, ButtonType::SIX },
		{ SDLK_7, ButtonType::SEVEN },
		{ SDLK_8, ButtonType::EIGHT },
		{ SDLK_9, ButtonType::NINE },
		{ SDLK_a, ButtonType::A },
		{ SDLK_b, ButtonType::B },
		{ SDLK_c, ButtonType::C },
		{ SDLK_d, ButtonType::D },
		{ SDLK_e, ButtonType::E },
		{ SDLK_f, ButtonType::F },
		{ SDLK_g, ButtonType::G },
		{ SDLK_h, ButtonType::H },
		{ SDLK_i, ButtonType::I },
		{ SDLK_j, ButtonType::J },
		{ SDLK_k, ButtonType::K },
		{ SDLK_l, ButtonType::L },
		{ SDLK_m, ButtonType::M },
		{ SDLK_n, ButtonType::N },
		{ SDLK_o, ButtonType::O },
		{ SDLK_p, ButtonType::P },
		{ SDLK_q, ButtonType::Q },
		{ SDLK_r, ButtonType::R },
		{ SDLK_s, ButtonType::S },
		{ SDLK_t, ButtonType::T },
		{ SDLK_u, ButtonType::U },
		{ SDLK_v, ButtonType::V },
		{ SDLK_w, ButtonType::W },
		{ SDLK_x, ButtonType::X },
		{ SDLK_y, ButtonType::Y },
		{ SDLK_z, ButtonType::Z },
		{ SDLK_SPACE, ButtonType::SPACE },
		{ SDLK_LSHIFT, ButtonType::LSHIFT },
		{ SDLK_LCTRL, ButtonType::LCTRL },
		{ SDLK_RSHIFT, ButtonType::RSHIFT },
		{ SDLK_RCTRL, ButtonType::RCTRL },
		{ SDLK_ESCAPE, ButtonType::ESCAPE }
};

InputManager::InputManager() {
	_keyboardState = SDL_GetKeyboardState(nullptr);
}

bool InputManager::run() {
	InputState input;

	SDL_Event event;

	SDL_GetMouseState( &input.mousePosition.x, &input.mousePosition.y );

	SDL_PumpEvents();

	for( auto pair : InputManager::_scanCodes ) {
		if( _keyboardState[pair.first] )
		{
			input.heldButtons.insert(pair.second);
		}
	}

	while(SDL_PollEvent(&event) != 0) {
		SDL_Keycode keycode;
		switch(event.type) {
		case SDL_QUIT:
			return false;
			break;
		case SDL_KEYDOWN:
			keycode = event.key.keysym.sym;
			if(InputManager::_actionCodes.find(keycode) != InputManager::_actionCodes.end()) {
				input.pressedButtons.insert(InputManager::_actionCodes[keycode]);
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			cout << "Mouse button down!" << endl;
			if(event.button.button == SDL_BUTTON_LEFT) {
				input.pressedButtons.insert(ButtonType::LMOUSE);
			}
			else if(event.button.button == SDL_BUTTON_RIGHT) {
				input.pressedButtons.insert(ButtonType::RMOUSE);
			}
			else {
				cout << "Button pressed: " << event.button.button << endl;
			}
			break;
		}
	}
	for(InputObserver* observer : _observers) {
		observer->notify(input);
	}
	return true;
}

void InputManager::addObserver(InputObserver* o) {
	_observers.push_back(o);
}
