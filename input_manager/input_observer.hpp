/*
 * input_observer.hpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Corey
 */

#ifndef INPUT_OBSERVER_HPP_
#define INPUT_OBSERVER_HPP_

struct InputState;

class InputObserver {
public:
	virtual ~InputObserver() {}
	virtual void notify(InputState state) = 0;
};


#endif /* INPUT_OBSERVER_HPP_ */
