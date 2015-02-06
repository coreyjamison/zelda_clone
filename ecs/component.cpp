/*
 * component.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Corey
 */

#include <iostream>
using namespace std;

#include "component.hpp"

Component::~Component()
{
	for(Node* node : nodes) {
		node->valid = false;
	}
}

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

RenderComponent::RenderComponent(Sprite* s, RenderLayer l)
:	sprite(s),
 	frame(0),
 	layer(l)
{}

StateComponent::StateComponent(unsigned int s)
:	state(s)
{}

void StateComponent::setAction(Action a)
{
	state = (state & 0x3) | a;
}

void StateComponent::setDirection(Direction d)
{
	state = (state & 0xFC) | d;
}

MoveComponent::MoveComponent(int s)
:	speed(s), goalMove({0, 0})
{}
