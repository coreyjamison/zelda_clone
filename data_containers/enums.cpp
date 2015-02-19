/*
 * enums.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Corey
 */

#include "enums.hpp"

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
