/*
 * sdl_utils.cpp
 *
 *  Created on: Aug 16, 2014
 *      Author: Corey
 */

#include "sdl_utils.hpp"

void SdlUtils::init()
{
	SDL_Init( SDL_INIT_VIDEO );
}

void SdlUtils::quit()
{
	SDL_Quit();
}
