/*
 * node.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include "node.hpp"

Node::Node(unsigned int id)
:	valid(true), parentId(id)
{}

RenderNode::RenderNode(unsigned int id, PositionComponent* p, RenderComponent* r, StateComponent* s)
:	Node(id), position(p), render(r), state(s)
{}


RenderNode* RenderNode::createFrom(Entity* e) {
	PositionComponent* p = e->getComponent<PositionComponent>();
	RenderComponent* r = e->getComponent<RenderComponent>();
	StateComponent* s = e->getComponent<StateComponent>();
	if(p && r) {
		RenderNode* node = new RenderNode(e->getId(), p, r, s);
		p->nodes.push_back(node);
		r->nodes.push_back(node);
		s->nodes.push_back(node);
		return node;
	}
	else {
		return nullptr;
	}
}

MoveNode::MoveNode(unsigned int id, PositionComponent* p, MoveComponent* m, StateComponent* s)
:	Node(id), position(p), move(m), state(s)
{}

MoveNode* MoveNode::createFrom(Entity* e) {
	PositionComponent* p = e->getComponent<PositionComponent>();
	MoveComponent* m = e->getComponent<MoveComponent>();
	StateComponent* s = e->getComponent<StateComponent>();
	if(p && m) {
		MoveNode* node = new MoveNode(e->getId(), p, m, s);
		p->nodes.push_back(node);
		m->nodes.push_back(node);
		s->nodes.push_back(node);
		return node;
	}
	else {
		return nullptr;
	}
}

CollisionNode::CollisionNode(unsigned int id, PositionComponent* p, CollisionComponent* c)
:	Node(id), position(p), collision(c)
{}

CollisionNode* CollisionNode::createFrom(Entity* e)
{
	PositionComponent* p = e->getComponent<PositionComponent>();
	CollisionComponent* c = e->getComponent<CollisionComponent>();
	if(p && c)
	{
		CollisionNode* node = new CollisionNode(e->getId(), p, c);
		p->nodes.push_back(node);
		return node;
	}
	else
	{
		return nullptr;
	}
}

TrackingCameraNode::TrackingCameraNode(unsigned int id, PositionComponent* p)
:	Node(id), position(p)
{}

TrackingCameraNode* TrackingCameraNode::createFrom(Entity* e)
{
	PositionComponent* p = e->getComponent<PositionComponent>();
	if(p)
	{
		TrackingCameraNode* node = new TrackingCameraNode(e->getId(), p);
		p->nodes.push_back(node);
		return node;
	}
	else
	{
		return nullptr;
	}
}

HealthBarNode::HealthBarNode(unsigned int id,PositionComponent* p, HealthComponent* h)
:	Node(id), position(p), health(h)
{}

HealthBarNode* HealthBarNode::createFrom(Entity* e)
{
	PositionComponent* p = e->getComponent<PositionComponent>();
	HealthComponent* h = e->getComponent<HealthComponent>();
	if(p && h)
	{
		HealthBarNode* node = new HealthBarNode(e->getId(), p, h);
		p->nodes.push_back(node);
		h->nodes.push_back(node);
		return node;
	}
	else
	{
		return nullptr;
	}
}
