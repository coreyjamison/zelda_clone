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

class Sprite
{
public:
	Sprite(SdlTexture& texture, map<int, vector<SDL_Rect>> frames, Vec2<int> offset);

	Renderable* getRenderable();
	void tick();
	void setState(unsigned int state);

//private:
	SdlTexture _texture;
	map<int, vector<SDL_Rect>> _frames;
	Vec2<int> _offset;
	unsigned int _state;
	unsigned int _frame;
};



#endif /* SPRITE_HPP_ */
