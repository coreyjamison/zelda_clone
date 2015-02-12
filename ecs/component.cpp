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

PositionComponent::PositionComponent(Vec2<double> pos)
:	curPos(pos), lastPos(pos)
{}

void PositionComponent::setPos(Vec2<double> newPos)
{
	lastPos = curPos;
	curPos = newPos;
}

void PositionComponent::movePos(Vec2<double> move)
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

MoveComponent::MoveComponent(double s)
:	speed(s), goalMove({0, 0})
{}

CollisionComponent::CollisionComponent(Vec2<double> s, unsigned int t, unsigned int m, int w)
:	size(s), type(t), mask(m), weight(w)
{}

HealthComponent::HealthComponent(int h, int m)
:	health(h), maxHealth(m)
{}

void HealthComponent::damage(int amount)
{
	health -= amount;
	if(health < 0)
	{
		health = 0;
	}
}

void HealthComponent::heal(int amount)
{
	health += amount;
	if(health > maxHealth)
	{
		health = maxHealth;
	}
}
