/*
 * component.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include "component.hpp"

PositionComponent::PositionComponent(Vec2<int> pos)
:	curPos(pos), lastPos(pos)
{}

void PositionComponent::setPos(Vec2<int> newPos)
{
	lastPos = curPos;
	curPos = newPos;
}

void PositionComponent::movePos(Vec2<int> move)
{
	lastPos = curPos;
	curPos += move;
}

RenderComponent::RenderComponent(Sprite* s)
:	sprite(s)
{}
