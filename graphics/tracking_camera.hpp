/*
 * TrackingCamera.hpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Corey
 */

#ifndef TRACKING_CAMERA_HPP_
#define TRACKING_CAMERA_HPP_

#include <data_containers/vec2.hpp>
#include <ecs/node.hpp>

#include "camera.hpp"

struct TrackingCamera : public Camera
{
	TrackingCamera(TrackingCameraNode* node, Vec2<double> wSize, Vec2<int> sSize);
	virtual ~TrackingCamera() = default;

	virtual Vec2<int> getScreenPosition(Vec2<double> wPos);
	virtual Vec2<double> getWorldPosition(Vec2<int> sPos);

	TrackingCameraNode* tcn; 	// Node to track
	Vec2<double> worldSize;		// Size of visible region in world
	Vec2<int> screenSize;		// Size of screen to draw to
};


#endif /* TRACKING_CAMERA_HPP_ */
