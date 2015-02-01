/*
 * component.hpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <data_containers/vec2.hpp>
#include <graphics/sprite.hpp>

struct Component
{
	virtual ~Component() = 0;
};

inline Component::~Component() {}

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
};



#endif /* COMPONENT_HPP_ */
