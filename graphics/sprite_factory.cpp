/*
 * sprite_factory.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#include <string>
#include <iostream>

#include <ecs/component.hpp>

#include "sprite_factory.hpp"
#include "sprite.hpp"
#include "game_window.hpp"

using namespace std;

Sprite SpriteFactory::makeDemoSprite( const GameWindow& window )
{
	string imageFile = "res/4LinkGreen1_2.bmp";

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
	SpriteState moveUp;
	moveUp.frames = {
		{ 0, 0, 24, 32}, { 24, 0, 24, 32}, { 48, 0, 24, 32}, { 72, 0, 24, 32},
		{ 96, 0, 24, 32}, { 120, 0, 24, 32}, { 144, 0, 24, 32}, { 168, 0, 24, 32},
		{ 192, 0, 24, 32}, { 216, 0, 24, 32}, { 240, 0, 24, 32}, { 264, 0, 24, 32},
		{ 0, 128, 24, 32}, { 24, 128, 24, 32}, { 48, 128, 24, 32}, { 72, 128, 24, 32},
		{ 96, 128, 24, 32}, { 120, 128, 24, 32}, { 144, 128, 24, 32}, { 168, 128, 24, 32},
		{ 192, 128, 24, 32}, { 216, 128, 24, 32}, { 240, 128, 24, 32}, { 264, 128, 24, 32},
		{ 0, 256, 24, 32}, { 24, 256, 24, 32}, { 48, 256, 24, 32}, { 72, 256, 24, 32},
		{ 96, 256, 24, 32}, { 120, 256, 24, 32}
	};
	moveUp.offset = {12, 26};

	SpriteState moveRight;
	moveRight.frames = {
		{ 0, 32, 24, 32}, { 24, 32, 24, 32}, { 48, 32, 24, 32}, { 72, 32, 24, 32},
		{ 96, 32, 24, 32}, { 120, 32, 24, 32}, { 144, 32, 24, 32}, { 168, 32, 24, 32},
		{ 192, 32, 24, 32}, { 216, 32, 24, 32}, { 240, 32, 24, 32}, { 264, 32, 24, 32},
		{ 0, 160, 24, 32}, { 24, 160, 24, 32}, { 48, 160, 24, 32}, { 72, 160, 24, 32},
		{ 96, 160, 24, 32}, { 120, 160, 24, 32}, { 144, 160, 24, 32}, { 168, 160, 24, 32},
		{ 192, 160, 24, 32}, { 216, 160, 24, 32}, { 240, 160, 24, 32}, { 264, 160, 24, 32},
		{ 0, 288, 24, 32}, { 24, 288, 24, 32}, { 48, 288, 24, 32}, { 72, 288, 24, 32},
		{ 96, 288, 24, 32}, { 120, 288, 24, 32}
	};
	moveRight.offset = {12, 26};

	SpriteState moveDown;
	moveDown.frames =
	{
		{ 0, 64, 24, 32}, { 24, 64, 24, 32}, { 48, 64, 24, 32}, { 72, 64, 24, 32},
		{ 96, 64, 24, 32}, { 120, 64, 24, 32}, { 144, 64, 24, 32}, { 168, 64, 24, 32},
		{ 192, 64, 24, 32}, { 216, 64, 24, 32}, { 240, 64, 24, 32}, { 264, 64, 24, 32},
		{ 0, 192, 24, 32}, { 24, 192, 24, 32}, { 48, 192, 24, 32}, { 72, 192, 24, 32},
		{ 96, 192, 24, 32}, { 120, 192, 24, 32}, { 144, 192, 24, 32}, { 168, 192, 24, 32},
		{ 192, 192, 24, 32}, { 216, 192, 24, 32}, { 240, 192, 24, 32}, { 264, 192, 24, 32},
		{ 0, 320, 24, 32}, { 24, 320, 24, 32}, { 48, 320, 24, 32}, { 72, 320, 24, 32},
		{ 96, 320, 24, 32}, { 120, 320, 24, 32}
	};
	moveDown.offset = {12, 26};

	SpriteState moveLeft;
	moveLeft.frames = {
		{ 0, 96, 24, 32}, { 24, 96, 24, 32}, { 48, 96, 24, 32}, { 72, 96, 24, 32},
		{ 96, 96, 24, 32}, { 120, 96, 24, 32}, { 144, 96, 24, 32}, { 168, 96, 24, 32},
		{ 192, 96, 24, 32}, { 216, 96, 24, 32}, { 240, 96, 24, 32}, { 264, 96, 24, 32},
		{ 0, 224, 24, 32}, { 24, 224, 24, 32}, { 48, 224, 24, 32}, { 72, 224, 24, 32},
		{ 96, 224, 24, 32}, { 120, 224, 24, 32}, { 144, 224, 24, 32}, { 168, 224, 24, 32},
		{ 192, 224, 24, 32}, { 216, 224, 24, 32}, { 240, 224, 24, 32}, { 264, 224, 24, 32},
		{ 0, 352, 24, 32}, { 24, 352, 24, 32}, { 48, 352, 24, 32}, { 72, 352, 24, 32},
		{ 96, 352, 24, 32}, { 120, 352, 24, 32}
	};
	moveLeft.offset = {12, 26};

	SpriteState idleUp;
	idleUp.frames = { { 0, 0, 24, 32} };
	idleUp.offset = {12, 26};

	SpriteState idleRight;
	idleRight.frames = { { 0, 32, 24, 32} };
	idleRight.offset = {12, 26};

	SpriteState idleDown;
	idleDown.frames = { { 0, 64, 24, 32} };
	idleDown.offset = {12, 26};

	SpriteState idleLeft;
	idleLeft.frames = { { 0, 96, 24, 32} };
	idleLeft.offset = {12, 26};

	Sprite testSprite{ texture };

	testSprite.addState(StateComponent::Direction::LEFT|StateComponent::State::MOVE, moveLeft);
	testSprite.addState(StateComponent::Direction::RIGHT|StateComponent::State::MOVE, moveRight);
	testSprite.addState(StateComponent::Direction::UP|StateComponent::State::MOVE, moveUp);
	testSprite.addState(StateComponent::Direction::DOWN|StateComponent::State::MOVE, moveDown);

	testSprite.addState(StateComponent::Direction::LEFT|StateComponent::State::IDLE, idleLeft);
	testSprite.addState(StateComponent::Direction::RIGHT|StateComponent::State::IDLE, idleRight);
	testSprite.addState(StateComponent::Direction::UP|StateComponent::State::IDLE, idleUp);
	testSprite.addState(StateComponent::Direction::DOWN|StateComponent::State::IDLE, idleDown);


	return testSprite;
}


