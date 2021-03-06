/*
 * window.hpp
 *
 *  Created on: Jan 26, 2015
 *      Author: Corey
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <map>
#include <vector>
#include <memory>

#include <data_containers/vec2.hpp>
#include <data_containers/enums.hpp>
#include "renderable.hpp"

using namespace std;
using namespace Enums;

class GameWindow {
public:
	GameWindow( string title, Vec2<int> screenSize );
	~GameWindow();

	void clear();
	void queueRenderable( Renderable* renderable, RenderLayer layer, Vec2<int> position );
	void render();

	SdlTexture makeTexture( SdlSurface& surface ) const;

private:
	SdlWindow* _window;
	SdlRenderer* _renderer;

	map<RenderLayer,
		vector<pair<Vec2<int>, Renderable*>>> _renderables;

};



#endif /* WINDOW_HPP_ */
