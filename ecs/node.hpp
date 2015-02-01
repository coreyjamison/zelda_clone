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

struct Node {
	virtual ~Node() = default;
	//virtual Node* createFrom(Entity* c) = 0;
};

struct RenderNode : public Node{
	RenderNode(PositionComponent* p, RenderComponent* r);

	PositionComponent* position;
	RenderComponent* render;

	static int test();

	static RenderNode* createFrom(Entity* c);
};



#endif /* NODE_HPP_ */
