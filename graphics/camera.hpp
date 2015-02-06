/*
 * camera.hpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Corey
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

// TODO - implement zooming functionality (have to scale sprites and such)
struct Camera
{
	virtual ~Camera() = default;

	virtual Vec2<int> getScreenPosition(Vec2<double> wPos) = 0;
	virtual Vec2<double> getWorldPosition(Vec2<int> sPos) = 0;
};



#endif /* CAMERA_HPP_ */
