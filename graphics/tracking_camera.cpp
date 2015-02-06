/*
 * tracking_camera.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Corey
 */

#include "tracking_camera.hpp"

TrackingCamera::TrackingCamera(TrackingCameraNode* node, Vec2<double> wSize, Vec2<int> sSize)
:	tcn(node), worldSize(wSize), screenSize(sSize)
{}

Vec2<int> TrackingCamera::getScreenPosition(Vec2<double> wPos)
{
	Vec2<double> topLeft = tcn->position->curPos - (worldSize / 2);

	return {
		static_cast<int>(wPos.x - topLeft.x),
		static_cast<int>(wPos.y - topLeft.y)
	};
}

Vec2<double> TrackingCamera::getWorldPosition(Vec2<int> sPos)
{
	Vec2<double> topLeft = tcn->position->curPos - (worldSize / 2);

	return {
		static_cast<double>(sPos.x) + topLeft.x,
		static_cast<double>(sPos.y) + topLeft.y
	};
}

