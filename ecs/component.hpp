/*
 * component.hpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <vector>

#include <data_containers/vec2.hpp>
#include <graphics/sprite.hpp>

#include "node.hpp"

class Node;

struct Component
{
	virtual ~Component();

	vector<Node*> nodes;
};

struct PositionComponent : public Component
{
	PositionComponent(Vec2<int> pos);

	void setPos(Vec2<int> newPos);
	void movePos(Vec2<int> move);

	Vec2<int> curPos;
	Vec2<int> lastPos;
};

struct RenderComponent : public Component
{
	RenderComponent(Sprite* s);

	Sprite* sprite;
	unsigned int frame;
};

struct StateComponent : public Component
{
	StateComponent(unsigned int s);


	unsigned int state;

	enum Direction
	{
		LEFT = 0x0,
		RIGHT = 0x1,
		UP = 0x2,
		DOWN = 0x3
	};

	enum Action
	{
		IDLE = 0x0,
		MOVE = 0x4
	};

	void setDirection(Direction d);
	void setAction(Action a);
};

struct MoveComponent : public Component
{
	MoveComponent(int s);

	int speed;
};



#endif /* COMPONENT_HPP_ */
