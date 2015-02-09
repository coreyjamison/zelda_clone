/*
 * renderable_texture.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */
#include <data_containers/vec2.hpp>

#include "renderable.hpp"

class RenderableTexture : public Renderable
{
public:
	RenderableTexture(const SdlTexture& texture, SDL_Rect source, Vec2<int> offset, bool flipped);

	virtual void render( SdlRenderer* renderer, Vec2<int> renderPos );

private:
	const SdlTexture& _texture;
	SDL_Rect _source;
	Vec2<int> _offset;
	bool _flipped;
};

