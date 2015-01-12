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
	virtual bool run() = 0;
};

class VariableRunnable {
public:
	virtual ~VariableRunnable() {}
	virtual bool run(double alpha) = 0;
};


#endif /* RUNNABLE_HPP_ */
