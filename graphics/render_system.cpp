/*
 * render_system.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include <iostream>

#include "render_system.hpp"

using namespace std;

RenderSystem::RenderSystem(GameWindow* window)
:	_window( window )
{}

void RenderSystem::addNode(RenderNode* node) {
	_nodes.push_back(node);
}

bool RenderSystem::run() {
	if(++_frame > 2) {
		_frame = 0;
		for(RenderNode* node : _nodes) {
			node->render->sprite->tick();
		}
	}
	return true;
}

bool RenderSystem::run(double alpha) {
	if(alpha < 0 || alpha > 1) {
		return true;
	}
	cout << "alpha: " << alpha << endl;
	for(RenderNode* node : _nodes) {
		// TODO: Actually interpolate
		Vec2<int> interpolated = node->position->curPos;

		_window->queueRenderable(node->render->sprite->getRenderable(),
				RenderLayer::ENTITIES,
				interpolated);
	}
	_window->render();
	return true;
}
