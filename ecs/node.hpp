/*
 * node.hpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include "component.hpp"
#include "entity.hpp"

class PositionComponent;
class RenderComponent;
class StateComponent;
class MoveComponent;
class CollisionComponent;
class HealthComponent;

class Entity;

struct Node
{
	Node();
	virtual ~Node() = default;

	bool valid;
};

struct RenderNode : public Node
{
	RenderNode(PositionComponent* p, RenderComponent* r, StateComponent* s);

	PositionComponent* position;
	RenderComponent* render;
	StateComponent* state;

	static RenderNode* createFrom(Entity* e);
};

struct MoveNode : public Node
{
	MoveNode(PositionComponent* p, MoveComponent* m, StateComponent* s);

	PositionComponent* position;
	MoveComponent* move;
	StateComponent* state;

	static MoveNode* createFrom(Entity* e);
};

struct CollisionNode : public Node
{
	CollisionNode(PositionComponent* p, CollisionComponent* c);

	PositionComponent* position;
	CollisionComponent* collision;

	static CollisionNode* createFrom(Entity* e);
};

struct HealthBarNode : public Node
{
	HealthBarNode(PositionComponent* p, HealthComponent* h);

	PositionComponent* position;
	HealthComponent* health;

	static HealthBarNode* createFrom(Entity* e);
};

/* Static Nodes -> not handled by ECS Manager */
struct TrackingCameraNode : public Node
{
	TrackingCameraNode(PositionComponent* p);

	PositionComponent* position;

	static TrackingCameraNode* createFrom(Entity* e);
};



#endif /* NODE_HPP_ */
