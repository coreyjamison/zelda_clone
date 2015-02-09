/*
 * sprite.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */


#include "sprite.hpp"
#include "renderable_texture.hpp"

#include <iostream>
using namespace std;

SpriteState::SpriteState()
:	frames{}, flipped{false}
{}

SpriteState::SpriteState(vector<SDL_Rect> f, bool flip)
:	frames(f), flipped{flip}
{}

Sprite::Sprite()
:	_texture{}, _offset{}
{}

Sprite::Sprite(SdlTexture& texture, Vec2<int> offset)
:	_texture{texture}, _offset{offset}
{}

void Sprite::setTexture(SdlTexture& texture)
{
	_texture = texture;
}

void Sprite::setOffset(Vec2<int> offset)
{
	_offset = offset;
}

Renderable* Sprite::getRenderable(unsigned int state, unsigned int frame)
{
	frame = validateFrame(state, frame);

	if(_states[state].flipped)
	{
		//cout << "Flipped!" << endl;
	}
	else
	{
		//cout << "Not Flipped!" << endl;
	}

	RenderableTexture* rt = new RenderableTexture(_texture, _states[state].frames[frame], _offset, _states[state].flipped);
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
