/*
 * sdl_wrappers.hpp
 *
 *  Created on: Aug 16, 2014
 *      Author: Corey
 */

#ifndef SDL_WRAPPERS_HPP_
#define SDL_WRAPPERS_HPP_

#include <SDL.h>

struct SdlWindow
{
	SdlWindow( const char* title, int x, int y, int w, int h, Uint32 flags);
	~SdlWindow();

	SDL_Window* window;
};

struct SdlTexture;

struct SdlRenderer
{
	SdlRenderer( SDL_Window* window, int index, Uint32 flags );
	~SdlRenderer();

	void setRenderDrawColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a );
	void clear();
	void renderPresent();

	void renderCopy( SdlTexture texture, SDL_Rect source, SDL_Rect dest );
	void renderDrawRect( SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a );

	SDL_Renderer* renderer;
};

struct SdlSurface
{
	SdlSurface( const char* file );
	~SdlSurface();

	void setColorKey( bool enable, Uint8 r, Uint8 g, Uint8 b );

	SDL_Surface* surface;
};

struct SdlTexture
{
	SdlTexture( SDL_Renderer* renderer, SDL_Surface* surface );
	~SdlTexture();

	SDL_Texture* texture;
};



#endif /* SDL_WRAPPERS_HPP_ */
