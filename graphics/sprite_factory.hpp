/*
 * sprite_factory.hpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#ifndef SPRITE_FACTORY_HPP_
#define SPRITE_FACTORY_HPP_

#include <unordered_map>

#include "sprite.hpp"
#include "game_window.hpp"

class SpriteFactory
{
public:
	Sprite makeDemoSprite( const GameWindow& window );
	Sprite makeSprite(const GameWindow& window, std::string name);
	SdlTexture makeTexture(string imageFile, const GameWindow& window);
	unordered_map<string, Sprite*> loadSprites(const GameWindow& window, string configFile);

	Sprite* getSprite(unsigned int spriteId);
	unsigned int getId(string spriteName);
private:
	unsigned int _nextId = 1;

	unordered_map<unsigned int, Sprite*> _sprites;
	unordered_map<string, unsigned int> _spriteIds;
};



#endif /* SPRITE_FACTORY_HPP_ */
