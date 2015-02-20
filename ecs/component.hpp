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
#include <data_containers/enums.hpp>
#include <graphics/sprite.hpp>
#include <graphics/game_window.hpp>

#include "node.hpp"

class Node;

using namespace Enums;

struct Component
{
	virtual ~Component();

	virtual Component* copy() = 0;

	unsigned long parentId = -1;
	vector<Node*> nodes;
};

struct PositionComponent : public Component
{
	PositionComponent(Vec2<double> pos);

	virtual Component* copy();

	void setPos(Vec2<double> newPos);
	void movePos(Vec2<double> move);

	Vec2<double> curPos;
	Vec2<double> lastPos;
};


struct RenderComponent : public Component
{
	RenderComponent(Sprite* s, RenderLayer l);

	virtual Component* copy();

	Sprite* sprite;
	unsigned int frame;
	RenderLayer layer;
};

struct StateComponent : public Component
{
	StateComponent(unsigned int s);

	virtual Component* copy();

	unsigned int state;

	void setDirection(Direction d);
	void setAction(Action a);
};

struct MoveComponent : public Component
{
	MoveComponent(double s);

	virtual Component* copy();

	double speed;
	Vec2<double> goalMove;
};

struct CollisionComponent : public Component
{
	CollisionComponent(Vec2<double> s, unsigned int t, unsigned int m, int w, unsigned int tm);

	virtual Component* copy();

	Vec2<double> size; // for now, all colliders are rectangles
	set<unsigned int> ignoredIds;
	unsigned int type;
	unsigned int mask;
	unsigned int team;	// don't run effects on same team
	int weight;			// -1 to make unmoveable
};

struct HealthComponent : public Component
{
	HealthComponent(int h, int m);

	virtual Component* copy();

	void damage(int amount);
	void heal(int amount);

	int health;
	int maxHealth;
};

struct PlayerCommandComponent : public Component
{};

struct AiCommandComponent : public Component
{
	virtual Component* copy();
};



#endif /* COMPONENT_HPP_ */
