/*
 * sprite_factory.hpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#ifndef SPRITE_FACTORY_HPP_
#define SPRITE_FACTORY_HPP_

#include "sprite.hpp"
#include "game_window.hpp"

class SpriteFactory
{
public:
	Sprite makeDemoSprite( const GameWindow& window );
};



#endif /* SPRITE_FACTORY_HPP_ */
