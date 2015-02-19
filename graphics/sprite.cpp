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
:	_texture{}, _offset{}, _scale{1}
#ifdef __DEBUG
,	_id{_nextId++}
#endif
{}

Sprite::Sprite(SdlTexture& texture, Vec2<int> offset, double scale)
:	_texture{texture}, _offset{offset}, _scale{scale}
{}

void Sprite::setTexture(SdlTexture& texture)
{
	_texture = texture;
}

void Sprite::setOffset(Vec2<int> offset)
{
	_offset = offset;
}

void Sprite::setScale(double scale)
{
	_scale = scale;
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

	SpriteState s = _states[state];

	cout << s.frames.size() << " frames!" << endl;

	if(s.frames.size() == 0)
	{
		return nullptr;
	}

	SDL_Rect f = s.frames[frame];

	RenderableTexture* rt = new RenderableTexture(_texture, f, _offset, _scale, s.flipped);
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
