/*
 * sdl_wrappers.cpp
 *
 *  Created on: Aug 16, 2014
 *      Author: Corey
 */

#include "sdl_wrappers.hpp"

SdlWindow::SdlWindow( const char* title, int x, int y, int w, int h, Uint32 flags )
:	window( NULL )
{
	window = SDL_CreateWindow( title, x, y, w, h, flags );
}

SdlWindow::~SdlWindow()
{
	SDL_DestroyWindow( window );
	window = nullptr;
}

SdlRenderer::SdlRenderer( SDL_Window* window, int index, Uint32 flags )
{
	renderer = SDL_CreateRenderer( window, index, flags );
}

SdlRenderer::~SdlRenderer()
{
	SDL_DestroyRenderer( renderer );
	renderer = nullptr;
}

void SdlRenderer::setRenderDrawColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a )
{
	SDL_SetRenderDrawColor( renderer, r, g, b, a );
}

void SdlRenderer::clear()
{
	SDL_RenderClear( renderer );
}

void SdlRenderer::renderPresent()
{
	SDL_RenderPresent( renderer );
}

void SdlRenderer::renderCopy( SdlTexture texture, SDL_Rect source, SDL_Rect dest )
{
	SDL_RenderCopy( renderer, texture.texture, &source, &dest );
}

void SdlRenderer::renderDrawRect( SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a )
{
	SDL_SetRenderDrawColor( renderer, r, g, b, a );
	SDL_RenderDrawRect( renderer, &rect );
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

SdlSurface::SdlSurface( const char* file )
{
	surface = SDL_LoadBMP( file );
}

SdlSurface::~SdlSurface()
{
	SDL_FreeSurface( surface );
	surface = nullptr;
}

void SdlSurface::setColorKey( bool enable, Uint8 r, Uint8 g, Uint8 b )
{
	int flag = enable ? SDL_TRUE : SDL_FALSE;
	SDL_SetColorKey( surface, flag, SDL_MapRGB( surface->format, r, g, b ) );
}

SdlTexture::SdlTexture( SDL_Renderer* renderer, SDL_Surface* surface )
{
	texture = SDL_CreateTextureFromSurface( renderer, surface );
}

SdlTexture::~SdlTexture()
{
	SDL_DestroyTexture( texture );
	texture = nullptr;
}
