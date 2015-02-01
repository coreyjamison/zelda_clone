/*
 * render_system.hpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#ifndef RENDER_SYSTEM_HPP_
#define RENDER_SYSTEM_HPP_

#include <vector>

#include <gameloop/runnable.hpp>
#include <ecs/node.hpp>

#include "game_window.hpp"

class RenderSystem : public VariableRunnable, public FixedRunnable
{
public:
	RenderSystem(GameWindow* window);

	//TEST
	void addNode(RenderNode* node);

	virtual bool run();
	virtual bool run(double alpha);

private:
	GameWindow* _window;
	vector<RenderNode*> _nodes;
	int	_frame = 0;
};



#endif /* RENDER_SYSTEM_HPP_ */
