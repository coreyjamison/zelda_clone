/*
 * runnable.hpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Corey
 */

#ifndef RUNNABLE_HPP_
#define RUNNABLE_HPP_

class FixedRunnable {
public:
	virtual ~FixedRunnable() {}

	// Return false to exit the game loop
	virtual bool run() = 0;
};

class VariableRunnable {
public:
	virtual ~VariableRunnable() {}

	// return false to exit the game loop
	virtual bool run(double alpha) = 0;
};


#endif /* RUNNABLE_HPP_ */
