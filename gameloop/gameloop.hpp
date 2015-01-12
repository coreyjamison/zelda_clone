/*
 * gameloop.hpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Corey
 */

#ifndef GAMELOOP_HPP_
#define GAMELOOP_HPP_

#include <list>
#include "runnable.hpp"

using namespace std;

class GameLoop {
private:
	list<VariableRunnable*> variableTimeRunnables;
	list<FixedRunnable*> fixedTimeRunnables;

public:
	void addVariableRunnable(VariableRunnable* r);
	void addFixedRunnable(FixedRunnable* r);

	void run();
};



#endif /* GAMELOOP_HPP_ */
