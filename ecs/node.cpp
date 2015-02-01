/*
 * node.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include "node.hpp"

RenderNode::RenderNode( PositionComponent* p, RenderComponent* r)
:	position(p), render(r)
{}


RenderNode* RenderNode::createFrom(Entity* c) {
	PositionComponent* p = c->getComponent<PositionComponent>();
	RenderComponent* r = c->getComponent<RenderComponent>();
	if(p && r) {
		return new RenderNode(p, r);
	}
	else {
		return nullptr;
	}
}
