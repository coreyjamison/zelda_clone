/*
 * node.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include "node.hpp"

Node::Node()
:	valid(true)
{}

RenderNode::RenderNode( PositionComponent* p, RenderComponent* r, StateComponent* s)
:	position(p), render(r), state(s)
{}


RenderNode* RenderNode::createFrom(Entity* e) {
	PositionComponent* p = e->getComponent<PositionComponent>();
	RenderComponent* r = e->getComponent<RenderComponent>();
	StateComponent* s = e->getComponent<StateComponent>();
	if(p && r) {
		RenderNode* node = new RenderNode(p, r, s);
		p->nodes.push_back(node);
		r->nodes.push_back(node);
		s->nodes.push_back(node);
		return node;
	}
	else {
		return nullptr;
	}
}

MoveNode::MoveNode(PositionComponent* p, MoveComponent* m, StateComponent* s)
:	position(p), move(m), state(s)
{}

MoveNode* MoveNode::createFrom(Entity* e) {
	PositionComponent* p = e->getComponent<PositionComponent>();
	MoveComponent* m = e->getComponent<MoveComponent>();
	StateComponent* s = e->getComponent<StateComponent>();
	if(p && m) {
		MoveNode* node = new MoveNode(p, m, s);
		p->nodes.push_back(node);
		m->nodes.push_back(node);
		s->nodes.push_back(node);
		return node;
	}
	else {
		return nullptr;
	}
}
