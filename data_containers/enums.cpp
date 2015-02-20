/*
 * enums.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Corey
 */

#include "enums.hpp"

#include <iostream>
using namespace std;

using namespace Enums;
RenderLayer Enums::layerFromString(string s)
{
	if(s == "terrain")
		return RenderLayer::TERRAIN;
	else if(s == "terrain_blending")
		return RenderLayer::TERRAIN_BLENDING;
	else if(s == "decoration")
		return RenderLayer::DECORATION;
	else if(s == "shadows")
		return RenderLayer::SHADOWS;
	else if(s == "entities")
		return RenderLayer::ENTITIES;
	else /*if(s == "ui")*/
		return RenderLayer::UI;
}

Direction Enums::directionFromString(string s)
{
	if(s == "left" || s == "l")
		return Direction::LEFT;
	else if(s == "right" || s == "r")
		return Direction::RIGHT;
	else if(s == "up" || s == "u")
		return Direction::UP;
	else /*if(s == "down")*/
		return Direction::DOWN;
}

Action Enums::actionFromString(string s)
{
	if(s == "idle")
		return Action::IDLE;
	else /*if(s == "move")*/
		return Action::MOVE;
}

CollisionType Enums::collisionTypeFromString(string s)
{
	cout << "collisionTypeFromString :: " << s << endl;
	if(s == "entity") {
		cout << "returning " << CollisionType::ENTITY << endl;
		return CollisionType::ENTITY;
	} else if(s == "projectile") {
		cout << "returning " << CollisionType::PROJECTILE << endl;
		return CollisionType::PROJECTILE;
	} else {
		cout << "returning " << CollisionType::NONE << endl;
		return CollisionType::NONE;
	}
}

unsigned int Enums::collisionMaskFromString(string s)
{
	cout << "collisionMaskFromString :: " << s << endl;
	unsigned int mask = 0;

	size_t position = 0;
	string type = "";
	string delimiter = "|";

	cout << s << endl;

	while ((position = s.find(delimiter)) != std::string::npos) {
	    type = s.substr(0, position);

	    cout << "type: " << type << endl;

	    mask |= collisionTypeFromString(type);
	    s.erase(0, position + delimiter.length());
	}

	mask |= collisionTypeFromString(s);

	return mask;
}
