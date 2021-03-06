/*
 * game_window.cpp
 *
 *  Created on: Jan 26, 2015
 *      Author: Corey
 */

#include <iostream>
#include <algorithm>

#include "game_window.hpp"

GameWindow::GameWindow( string title, Vec2<int> screenSize )
:	_window( new SdlWindow{ title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN })
,	_renderer{ new SdlRenderer{ *_window, -1, SDL_RENDERER_ACCELERATED} }
{}

GameWindow::~GameWindow()
{
	delete _window;
}

void GameWindow::clear()
{
	_renderer->clear();
}

void GameWindow::queueRenderable(Renderable* renderable, RenderLayer layer, Vec2<int> position)
{
	_renderables[layer].push_back({position, renderable});
}

typedef pair<Vec2<int>, Renderable*> layer_t;
bool verticalSort(layer_t first, layer_t second)
{
	return first.first.y < second.first.y;
}

void GameWindow::render()
{
	clear();

	for(auto& layer : _renderables)
	{
		std::sort(layer.second.begin(), layer.second.end(), verticalSort);
		for(auto& renderData : layer.second)
		{
			Vec2<int> position = renderData.first;
			Renderable* renderable = renderData.second;

			renderable->render( _renderer, position );
			delete renderable;
		}
	}
	_renderables.clear();

	_renderer->renderPresent();
}

SdlTexture GameWindow::makeTexture( SdlSurface& surface ) const
{
	return { *_renderer, surface };
}
