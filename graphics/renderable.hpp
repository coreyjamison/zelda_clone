/*
 * renderable.hpp
 *
 *  Created on: Jan 26, 2015
 *      Author: Corey
 */

#ifndef RENDERABLE_HPP_
#define RENDERABLE_HPP_

#include <SDLutil/sdl_wrappers.hpp>
#include <data_containers/vec2.hpp>

class Renderable
{
public:
	virtual ~Renderable() {}

	virtual void render( SdlRenderer* renderer, Vec2<int> renderPos ) = 0;
};



#endif /* RENDERABLE_HPP_ */
