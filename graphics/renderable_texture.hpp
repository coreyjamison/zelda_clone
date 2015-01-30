/*
 * renderable_texture.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#include "renderable.hpp"

class RenderableTexture : public Renderable
{
public:
	RenderableTexture(const SdlTexture& texture, SDL_Rect source);

	virtual void render( SdlRenderer* renderer, Vec2<int> renderPos );

private:
	const SdlTexture& _texture;
	SDL_Rect _source;
};

