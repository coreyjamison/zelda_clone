/*
 * component.hpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <vector>
#include <set>

#include <data_containers/vec2.hpp>
#include <graphics/sprite.hpp>
#include <graphics/game_window.hpp>

#include "node.hpp"

class Node;

struct Component
{
	virtual ~Component();

	unsigned long parentId = -1;
	vector<Node*> nodes;
};

struct PositionComponent : public Component
{
	PositionComponent(Vec2<double> pos);

	void setPos(Vec2<double> newPos);
	void movePos(Vec2<double> move);

	Vec2<double> curPos;
	Vec2<double> lastPos;
};


struct RenderComponent : public Component
{
	RenderComponent(Sprite* s, RenderLayer l);

	Sprite* sprite;
	unsigned int frame;
	RenderLayer layer;
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
	MoveComponent(double s);

	double speed;
	Vec2<double> goalMove;
};

struct CollisionComponent : public Component
{
	CollisionComponent(Vec2<double> s, unsigned int t, unsigned int m, int w);

	enum CollisionType
	{
		ENTITY = 0x1,
		PROJECTILE = 0x2
	};

	Vec2<double> size; // for now, all colliders are rectangles
	set<unsigned int> ignoredIds;
	unsigned int type;
	unsigned int mask;
	int weight;			// -1 to make unmoveable
};

struct HealthComponent : public Component
{
	HealthComponent(int h, int m);

	int health;
	int maxHealth;
};



#endif /* COMPONENT_HPP_ */
