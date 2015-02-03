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

RenderComponent::RenderComponent(Sprite* s)
:	sprite(s),
 	frame(0)
{}

StateComponent::StateComponent(unsigned int s)
:	state(s)
{}

void StateComponent::setAction(Action a)
{
	cout << "Before: " << state << endl;
	state = (state & 0x3) | a;
	cout << "After: " << state << endl;
}

void StateComponent::setDirection(Direction d)
{
	cout << "Before: " << state << endl;
	state = (state & 0xFC) | d;
	cout << "After: " << state << endl;
}

MoveComponent::MoveComponent(int s)
:	speed(s)
{}
