/*
 * input_manager.hpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Corey
 */

#ifndef INPUT_MANAGER_HPP_
#define INPUT_MANAGER_HPP_

#include <gameloop/runnable.hpp>
#include <data_containers/vec2.hpp>
#include <set>
#include <list>
#include <map>
#include <cstdint>

#include "input_observer.hpp"

using namespace std;

enum class ButtonType
{
	ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T,
	U, V, W, X, Y, Z, SPACE, LMOUSE, RMOUSE, MMOUSE, QUIT, ESCAPE,
	LSHIFT, LCTRL, RSHIFT, RCTRL
};

struct InputState {
	Vec2<int> mousePosition;
	set<ButtonType> pressedButtons;
	set<ButtonType> heldButtons;

	bool pressed(ButtonType b) {
		return pressedButtons.find(b) != pressedButtons.end();
	}

	bool held(ButtonType b) {
		return heldButtons.find(b) != heldButtons.end();
	}
};

class InputManager : public FixedRunnable
{
private:
	list<InputObserver*> _observers;
	const uint8_t* _keyboardState;

	static map<int, ButtonType> _scanCodes;
	static map<int, ButtonType> _actionCodes;

public:
	InputManager();

	bool run();
	void addObserver(InputObserver* o);
};



#endif /* INPUT_MANAGER_HPP_ */
