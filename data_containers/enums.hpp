/*
 * enums.hpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Corey
 */

#ifndef DATA_CONTAINERS_ENUMS_HPP_
#define DATA_CONTAINERS_ENUMS_HPP_

#include <string>

using namespace std;
namespace Enums
{
	enum class RenderLayer
	{
		TERRAIN,
		TERRAIN_BLENDING,
		DECORATION,
		SHADOWS,
		ENTITIES,
		UI
	};

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


	RenderLayer layerFromString(string s);
	Direction directionFromString(string s);
	Action actionFromString(string s);
};



#endif /* DATA_CONTAINERS_ENUMS_HPP_ */
