/*
 * sprite.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */


#include "sprite.hpp"
#include "renderable_texture.hpp"

Sprite::Sprite(SdlTexture& texture)
:	_texture{texture}
{}

Renderable* Sprite::getRenderable(unsigned int state, unsigned int frame)
{
	frame = validateFrame(state, frame);
	RenderableTexture* rt = new RenderableTexture(_texture, _states[state].frames[frame], _states[state].offset);
	return rt;
}

unsigned int Sprite::nextFrame(unsigned int state, unsigned int frame)
{
	frame++;
	return validateFrame(state, frame);
}

unsigned int Sprite::validateFrame(unsigned int state, unsigned int frame)
{
	if(frame >= _states[state].frames.size()) {
		frame = 0;
	}
	return frame;

}


void Sprite::addState(unsigned int state, SpriteState data)
{
	_states[state] = data;
}
