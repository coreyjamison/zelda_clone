/*
 * renderable_texture.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#include "renderable_texture.hpp"

#include <iostream>
using namespace std;

RenderableTexture::RenderableTexture(const SdlTexture& texture, SDL_Rect source, Vec2<int> offset, double scale, bool flipped)
:	_texture(texture),
 	_source(source),
 	_offset(offset),
 	_scale(scale),
 	_flipped(flipped)
{}

void RenderableTexture::render(SdlRenderer* renderer, Vec2<int> renderPos)
{
	SDL_Rect dest{
		renderPos.x - _offset.x,
		renderPos.y - _offset.y,
		static_cast<int>(_source.w * _scale),
		static_cast<int>(_source.h * _scale)
	};

	if(_flipped)
	{
		//cout << "Flipped!" << endl;
		renderer->renderCopyFlipped(_texture, _source, dest, true);
	}
	else
	{
		renderer->renderCopy(_texture, _source, dest);
	}
}
