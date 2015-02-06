/*
 * render_system.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include <iostream>

#include "render_system.hpp"

using namespace std;

RenderSystem::RenderSystem(GameWindow* window, Camera* camera)
:	_window( window ), _camera( camera )
{}

bool RenderSystem::run() {
	if(++_frame > 2) {
		_frame = 0;
		// TODO: remove invalid nodes
		for(RenderNode* node : _nodes) {
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
	for(RenderNode* node : _nodes) {

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
	_window->render();
	return true;
}
