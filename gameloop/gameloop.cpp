/*
 * gameloop.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Corey
 */

#include "gameloop.hpp"
#include <chrono>

void GameLoop::addFixedRunnable(FixedRunnable* r) {
	fixedTimeRunnables.push_back(r);
}

void GameLoop::addVariableRunnable(VariableRunnable* r) {
	variableTimeRunnables.push_back(r);
}

void GameLoop::run() {
	using namespace std::chrono;

	steady_clock::time_point loopStart;
	steady_clock::time_point prevLoopStart = steady_clock::now();

	double t = 0.0;
	double dt = 0.01;

	double accumulator = 0.0;

	bool loop = true;
	while(loop) {
		loopStart = steady_clock::now();

		steady_clock::duration chronoFrameTime = loopStart - prevLoopStart;

		prevLoopStart = loopStart;

		double frameTime = double( chronoFrameTime.count() ) *
				steady_clock::period::num /
				steady_clock::period::den;

		// TODO: Fix magic number!
		if( frameTime > 0.25 ) {
			frameTime = 0.25;
		}

		accumulator += frameTime;

		while( accumulator >= dt ) {
			for(FixedRunnable* r : fixedTimeRunnables) {
				if(!r->run()) {
					loop = false;
				}
			}
			t += dt;
			accumulator -= dt;
		}

		double alpha = accumulator / dt;

		for(VariableRunnable* r : variableTimeRunnables) {
			if(!r->run(alpha)) {
				loop = false;
			}
		}
	}

}
