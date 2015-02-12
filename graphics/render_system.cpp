/*
 * render_system.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include <iostream>

#include "render_system.hpp"
#include "renderable_bar.hpp"

using namespace std;

RenderSystem::RenderSystem(GameWindow* window, Camera* camera)
:	_window( window ), _camera( camera )
{}

bool RenderSystem::run() {
	if(++_frame > 2) {
		_frame = 0;
		for(RenderNode* node : ::NodeSystem<RenderNode>::_nodes->nodes) {
			if(node->valid) {
				node->render->frame = node->render->sprite->nextFrame(node->state->state, node->render->frame);
			}
		}
	}
	return true;
}

bool RenderSystem::run(double alpha) {
	if(alpha < 0 || alpha > 1) {
		return true;
	}
	for(RenderNode* node : ::NodeSystem<RenderNode>::_nodes->nodes) {

		Vec2<int> interpolated = _camera->getScreenPosition(
				node->position->curPos.average(node->position->lastPos)
		);

		Renderable* r = node->render->sprite->getRenderable(
				node->state->state,
				node->render->frame
				);

		_window->queueRenderable(r,
				node->render->layer,
				interpolated);
	}

	// TODO: figure out where this should go
	for(HealthBarNode* node : ::NodeSystem<HealthBarNode>::_nodes->nodes)
	{
		RenderableBar* bar = new RenderableBar(
					static_cast<double>( node->health->health ) / static_cast<double>( node->health->maxHealth ),
					{0, -60},
					{30, 10}
				);
		_window->queueRenderable(bar,
				RenderLayer::UI,
				_camera->getScreenPosition(node->position->curPos)
				);
	}

	_window->render();
	return true;
}
