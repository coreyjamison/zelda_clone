/*
 * sprite.hpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <memory>
#include <map>
#include <vector>
#include <SDLutil/sdl_wrappers.hpp>

#include "renderable.hpp"

using namespace std;

struct SpriteState
{
	SpriteState();
	SpriteState(vector<SDL_Rect> f, Vec2<int> o);

	vector<SDL_Rect> frames;
	Vec2<int> offset;
};

class Sprite
{
public:
	Sprite();
	Sprite(SdlTexture& texture);

	void setTexture(SdlTexture& texture);

	Renderable* getRenderable(unsigned int state, unsigned int frame);
	unsigned int nextFrame(unsigned int state, unsigned int frame);
	unsigned int validateFrame(unsigned int state, unsigned int frame);

	void addState(unsigned int state, SpriteState data);

private:
	SdlTexture _texture;
	map<unsigned int, SpriteState> _states;
};



#endif /* SPRITE_HPP_ */
