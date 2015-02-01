/*
 * renderable_texture.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#include "renderable_texture.hpp"

RenderableTexture::RenderableTexture(const SdlTexture& texture, SDL_Rect source, Vec2<int> offset)
:	_texture(texture),
 	_source(source),
 	_offset(offset)
{}

void RenderableTexture::render(SdlRenderer* renderer, Vec2<int> renderPos)
{
	SDL_Rect dest{
		renderPos.x - _offset.x,
		renderPos.y - _offset.y,
		_source.w,
		_source.h
	};

	renderer->renderCopy(_texture, _source, dest);
}
