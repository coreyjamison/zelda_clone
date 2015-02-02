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

SdlRenderer::SdlRenderer( const SdlWindow& window, int index, Uint32 flags )
{
	renderer = SDL_CreateRenderer( window.window, index, flags );
}

SdlRenderer::SdlRenderer()
:	renderer(nullptr)
{}

SdlRenderer::~SdlRenderer()
{
	if(renderer) {
		SDL_DestroyRenderer( renderer );
		renderer = nullptr;
	}
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

void SdlRenderer::renderCopy( const SdlTexture& texture, SDL_Rect source, SDL_Rect dest )
{
	SDL_RenderCopy( renderer, texture.texture/*->ptr*/, &source, &dest );
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

TexturePointer::TexturePointer(SDL_Texture* texture)
{
	ptr = texture;
	refCount = 1;
}

TexturePointer::~TexturePointer()
{
	if(--refCount == 0)
	{
		//SDL_DestroyTexture(ptr);
	}
}

TexturePointer* TexturePointer::copy()
{
	++refCount;
	return this;
}

SdlTexture::SdlTexture()
:	texture(nullptr)
{}

SdlTexture::SdlTexture( const SdlRenderer& renderer, const SdlSurface& surface )
{
	texture = /*new TexturePointer{*/ SDL_CreateTextureFromSurface( renderer.renderer, surface.surface ) ;//};
}

SdlTexture::SdlTexture( const SdlTexture& other )
{
	texture = other.texture;//->copy();
}

SdlTexture::~SdlTexture()
{
	/*if(texture)
	{
		delete texture;
	}*/
}

Vec2<int> SdlTexture::getDimensions()
{
	Vec2<int> dimensions;
	SDL_QueryTexture(texture, nullptr, nullptr, &dimensions.x, &dimensions.y);
	return dimensions;
}
