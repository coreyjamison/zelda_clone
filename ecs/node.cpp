/*
 * node.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include "node.hpp"

Node::Node()
:	valid(true), parentId(-1)
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
		node->parentId = e->getId();
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
		node->parentId = e->getId();
		p->nodes.push_back(node);
		m->nodes.push_back(node);
		s->nodes.push_back(node);
		return node;
	}
	else {
		return nullptr;
	}
}

CollisionNode::CollisionNode(PositionComponent* p, CollisionComponent* c)
:	position(p), collision(c)
{}

CollisionNode* CollisionNode::createFrom(Entity* e)
{
	PositionComponent* p = e->getComponent<PositionComponent>();
	CollisionComponent* c = e->getComponent<CollisionComponent>();
	if(p && c)
	{
		CollisionNode* node = new CollisionNode(p, c);
		node->parentId = e->getId();
		p->nodes.push_back(node);
		return node;
	}
	else
	{
		return nullptr;
	}
}

TrackingCameraNode::TrackingCameraNode(PositionComponent* p)
:	position(p)
{}

TrackingCameraNode* TrackingCameraNode::createFrom(Entity* e)
{
	PositionComponent* p = e->getComponent<PositionComponent>();
	if(p)
	{
		TrackingCameraNode* node = new TrackingCameraNode(p);
		node->parentId = e->getId();
		p->nodes.push_back(node);
		return node;
	}
	else
	{
		return nullptr;
	}
}

HealthBarNode::HealthBarNode(PositionComponent* p, HealthComponent* h)
:	position(p), health(h)
{}

HealthBarNode* HealthBarNode::createFrom(Entity* e)
{
	PositionComponent* p = e->getComponent<PositionComponent>();
	HealthComponent* h = e->getComponent<HealthComponent>();
	if(p && h)
	{
		HealthBarNode* node = new HealthBarNode(p, h);
		node->parentId = e->getId();
		p->nodes.push_back(node);
		h->nodes.push_back(node);
		return node;
	}
	else
	{
		return nullptr;
	}
}

AiCommandNode::AiCommandNode(AiCommandComponent* a, PositionComponent* p, MoveComponent* m, StateComponent* s)
:	ai(a), position(p), move(m), state(s)
{}

AiCommandNode* AiCommandNode::createFrom(Entity* e)
{
	AiCommandComponent* ai = e->getComponent<AiCommandComponent>();
	PositionComponent* p = e->getComponent<PositionComponent>();
	MoveComponent* m = e->getComponent<MoveComponent>();
	StateComponent* s = e->getComponent<StateComponent>();
	if(ai && p && m && s) {
		AiCommandNode* node = new AiCommandNode(ai, p, m, s);
		node->parentId = e->getId();
		ai->nodes.push_back(node);
		p->nodes.push_back(node);
		m->nodes.push_back(node);
		s->nodes.push_back(node);
		return node;
	}
	else {
		return nullptr;
	}
}
