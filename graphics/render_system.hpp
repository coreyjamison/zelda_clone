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
#include <ecs/ecs_manager.hpp>
#include <ecs/node.hpp>

#include "game_window.hpp"
#include "camera.hpp"

class RenderSystem : public VariableRunnable, public FixedRunnable
{
public:
	RenderSystem(GameWindow* window, Camera* camera);

	void setNodeList(NodeList<RenderNode>* nodes);

	virtual bool run();
	virtual bool run(double alpha);

private:
	GameWindow* _window;
	int	_frame = 0;
	Camera* _camera;
	NodeList<RenderNode>* _nodes;
};



#endif /* RENDER_SYSTEM_HPP_ */
