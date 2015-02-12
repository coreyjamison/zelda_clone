/*
 * sdl_wrappers.hpp
 *
 *  Created on: Aug 16, 2014
 *      Author: Corey
 */

#ifndef SDL_WRAPPERS_HPP_
#define SDL_WRAPPERS_HPP_

#include <SDL.h>

#include <data_containers/vec2.hpp>

struct SdlWindow
{
	SdlWindow( const char* title, int x, int y, int w, int h, Uint32 flags);
	~SdlWindow();

	SDL_Window* window;
};

struct SdlTexture;

struct SdlRenderer
{
	SdlRenderer( const SdlWindow& window, int index, Uint32 flags );
	SdlRenderer();
	~SdlRenderer();

	void setRenderDrawColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a );
	void clear();
	void renderPresent();

	void renderCopy( const SdlTexture& texture, SDL_Rect source, SDL_Rect dest );
	void renderCopyFlipped( const SdlTexture& texture, SDL_Rect source, SDL_Rect dest, bool horizontal );
	void renderDrawRect( SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a );
	void renderFillRect( SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a );

	SDL_Renderer* renderer;
};

struct SdlSurface
{
	SdlSurface( const char* file );
	~SdlSurface();

	void setColorKey( bool enable, Uint8 r, Uint8 g, Uint8 b );

	SDL_Surface* surface;
};

struct TexturePointer
{
	TexturePointer(SDL_Texture* texture);
	~TexturePointer();

	TexturePointer* copy();

	int refCount;
	SDL_Texture* ptr;
};

struct SdlTexture
{
	SdlTexture();
	SdlTexture( const SdlRenderer& renderer, const SdlSurface& surface );
	SdlTexture( const SdlTexture& other );
	~SdlTexture();

	Vec2<int> getDimensions();

	SDL_Texture* texture;
};



#endif /* SDL_WRAPPERS_HPP_ */
