/*
 * renderable_bar.hpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Corey
 */

#ifndef RENDERABLE_BAR_HPP_
#define RENDERABLE_BAR_HPP_

#include "renderable.hpp"

class RenderableBar : public Renderable
{
public:
	RenderableBar(double filled, Vec2<int> offset, Vec2<int> size);

	virtual void render( SdlRenderer* renderer, Vec2<int> renderPos );

private:
	double _filled;
	Vec2<int> _offset;
	Vec2<int> _size;
};



#endif /* RENDERABLE_BAR_HPP_ */
