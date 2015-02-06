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

class RenderSystem : public VariableRunnable, public FixedRunnable, public NodeListener
{
public:
	RenderSystem(GameWindow* window, Camera* camera);

	virtual bool run();
	virtual bool run(double alpha);
	virtual void onNodeChange(Node* r)
	{
		_nodes.push_back(static_cast<RenderNode*>(r));
	}

private:
	GameWindow* _window;
	vector<RenderNode*> _nodes;
	int	_frame = 0;
	Camera* _camera;
};



#endif /* RENDER_SYSTEM_HPP_ */
