/*
 * renderable_bar.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Corey
 */

#include "renderable_bar.hpp"

RenderableBar::RenderableBar(double filled, Vec2<int> offset, Vec2<int> size)
:	_filled(filled), _offset(offset), _size(size)
{}

void RenderableBar::render( SdlRenderer* renderer, Vec2<int> renderPos )
{
	if(_filled < 0)
		_filled = 0;

	if(_filled > 1)
		_filled = 1;
	Vec2<int> pos = renderPos + _offset - (_size/2);

	int filledWidth = static_cast<int>((_size.x-2)*_filled);

	SDL_Rect background = { pos.x, pos.y, _size.x, _size.y };
	SDL_Rect filled = { pos.x+1, pos.y+1, filledWidth, _size.y-2};
	SDL_Rect unfilled = { pos.x+1+filledWidth, pos.y+1, _size.x-2-filledWidth, _size.y-2};

	renderer->renderDrawRect(background, 0x00, 0x00, 0x00, 0xFF);
	renderer->renderFillRect(filled, 0x00, 0xFF, 0x00, 0xFF);
	renderer->renderFillRect(unfilled, 0xFF, 0x00, 0x00, 0xFF);
}

