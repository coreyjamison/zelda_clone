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
	SpriteState(vector<SDL_Rect> f, bool flip);

	vector<SDL_Rect> frames;
	bool flipped;
};

class Sprite
{
public:
	Sprite();
	Sprite(SdlTexture& texture, Vec2<int> offset, double scale);

	void setTexture(SdlTexture& texture);
	void setOffset(Vec2<int> offset);
	void setScale(double scale);

	Renderable* getRenderable(unsigned int state, unsigned int frame);
	unsigned int nextFrame(unsigned int state, unsigned int frame);
	unsigned int validateFrame(unsigned int state, unsigned int frame);

	void addState(unsigned int state, SpriteState data);

#ifdef __DEBUG
	static int _nextId = 1;
	int _id;
#endif

private:
	SdlTexture _texture;
	map<unsigned int, SpriteState> _states;
	Vec2<int> _offset;
	double _scale;
};



#endif /* SPRITE_HPP_ */
