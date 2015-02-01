/*
 * sprite.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */


#include "sprite.hpp"
#include "renderable_texture.hpp"

Sprite::Sprite(SdlTexture& texture, map<int, vector<SDL_Rect>> frames, Vec2<int> offset)
:	_texture{texture},
 	_frames{frames},
 	_offset{offset},
 	// TODO: Initialize these properly
 	_state{0},
 	_frame{0}
{}

Renderable* Sprite::getRenderable()
{
	RenderableTexture* rt = new RenderableTexture(_texture, _frames[_state][_frame], _offset);
	return rt;
}

void Sprite::tick()
{
	_frame++;
	if(_frame >= _frames[_state].size()) {
		_frame = 0;
	}
}

void Sprite::setState(unsigned int state)
{
	_state = state;
	//_frame = 0; // maybe necessary? Not sure if we should reset animation on change of state
}
