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



#endif /* NODE_HPP_ */
