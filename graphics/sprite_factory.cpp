/*
 * sprite_factory.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#include <string>
#include <iostream>

#include "sprite_factory.hpp"
#include "sprite.hpp"
#include "game_window.hpp"

using namespace std;

Sprite SpriteFactory::makeDemoSprite( const GameWindow& window )
{
	string imageFile = "res/4LinkGreen1.bmp";

	SdlSurface loadedSurface{ imageFile.c_str() };
	cout << "Loaded surface!" << endl;

	SdlTexture texture;
	if( loadedSurface.surface == NULL )
	{
		//_logger.log( LogSeverities::ERROR, "Failed to load image!" );
		cout << "Failed to load image!" << endl;
	}
	else
	{
		cout << "Loaded image!" << endl;
		loadedSurface.setColorKey( true, 0xFF, 0xFF, 0xFF );
		texture = window.makeTexture( loadedSurface );
		if( texture.texture/*->ptr*/ == NULL )
		{
			cout << "Failed to create texture!" << endl;
			//_logger.log( LogSeverities::ERROR, "Failed to create texture!" );
		}
		else
		{
			cout << "Created texture!" << endl;
		}
	}
	Sprite testSprite{
		texture,
		{pair<int, vector<SDL_Rect>>{ 0,
				{
						{ 0, 0, 24, 32},
						{ 24, 0, 24, 32},
						{ 48, 0, 24, 32},
						{ 72, 0, 24, 32},
						{ 96, 0, 24, 32},
						{ 120, 0, 24, 32},
						{ 144, 0, 24, 32},
						{ 168, 0, 24, 32},
						{ 192, 0, 24, 32},
						{ 216, 0, 24, 32},
						{ 240, 0, 24, 32},
						{ 264, 0, 24, 32},
						{ 0, 128, 24, 32},
						{ 24, 128, 24, 32},
						{ 48, 128, 24, 32},
						{ 72, 128, 24, 32},
						{ 96, 128, 24, 32},
						{ 120, 128, 24, 32},
						{ 144, 128, 24, 32},
						{ 168, 128, 24, 32},
						{ 192, 128, 24, 32},
						{ 216, 128, 24, 32},
						{ 240, 128, 24, 32},
						{ 264, 128, 24, 32}
				}

		}}
	};

	return testSprite;
}


