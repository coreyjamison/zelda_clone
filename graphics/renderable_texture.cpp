/*
 * renderable_texture.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#include "renderable_texture.hpp"

RenderableTexture::RenderableTexture(const SdlTexture& texture, SDL_Rect source)
:	_texture(texture),
 	_source(source)
{}

void RenderableTexture::render(SdlRenderer* renderer, Vec2<int> renderPos)
{
	SDL_Rect dest{
		renderPos.x,
		renderPos.y,
		_source.w,
		_source.h
	};

	renderer->renderCopy(_texture, _source, dest);
}
