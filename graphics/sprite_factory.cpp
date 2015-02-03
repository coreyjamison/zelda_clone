/*
 * sprite_factory.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Corey
 */

#include <string>
#include <iostream>
#include <fstream>

#include <include/rapidjson/document.h>
#include <ecs/component.hpp>

#include "sprite_factory.hpp"
#include "sprite.hpp"
#include "game_window.hpp"

using namespace std;

Sprite SpriteFactory::makeDemoSprite( const GameWindow& window )
{
	string imageFile = "res/sprite1.bmp";

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

	testSprite.addState(StateComponent::Direction::LEFT|StateComponent::Action::MOVE, moveLeft);
	testSprite.addState(StateComponent::Direction::RIGHT|StateComponent::Action::MOVE, moveRight);
	testSprite.addState(StateComponent::Direction::UP|StateComponent::Action::MOVE, moveUp);
	testSprite.addState(StateComponent::Direction::DOWN|StateComponent::Action::MOVE, moveDown);

	testSprite.addState(StateComponent::Direction::LEFT|StateComponent::Action::IDLE, idleLeft);
	testSprite.addState(StateComponent::Direction::RIGHT|StateComponent::Action::IDLE, idleRight);
	testSprite.addState(StateComponent::Direction::UP|StateComponent::Action::IDLE, idleUp);
	testSprite.addState(StateComponent::Direction::DOWN|StateComponent::Action::IDLE, idleDown);


	return testSprite;
}

using namespace rapidjson;
Sprite SpriteFactory::makeSprite(const GameWindow& window, string name)
{
	ifstream fs("res/sprite_config.json");
	string content{ istreambuf_iterator<char>(fs),
					istreambuf_iterator<char>() };

	Document document;
	char buffer[content.length()];
	sprintf(buffer, "%s", content.c_str());
	cout << buffer << endl;
	if(document.ParseInsitu(buffer).HasParseError())
	{
		cout << "Error reading json file!" << endl;
	}

	Sprite spr;

	if(document.IsObject())
	{
		if(document.HasMember("sprites"))
		{
			const Value& sprites = document["sprites"];
			if(sprites.HasMember(name.c_str()))
			{
				const Value& sprite = sprites[name.c_str()];
				if( sprite.HasMember("texture") &&
					sprite.HasMember("frameSize") &&
					sprite.HasMember("states") )
				{
					string imageFile = sprite["texture"].GetString();
					SdlTexture texture = makeTexture(imageFile, window);
					spr.setTexture(texture);
					const Value& fs = sprite["frameSize"];
					Vec2<int> frameSize = {
							fs["w"].GetInt(),
							fs["h"].GetInt()
					};
					Vec2<int> textureSize = texture.getDimensions();
					vector<vector<SDL_Rect>> frames;
					for(int y = 0; y < textureSize.y; y += frameSize.y)
					{
						vector<SDL_Rect> row;
						for(int x = 0; x < textureSize.x; x += frameSize.x)
						{
							row.push_back({
									x,
									y,
									frameSize.x,
									frameSize.y
								}
							);
						}
						for(SDL_Rect frame : row) {
							cout << "x:" << frame.x
									<< " y:" << frame.y
									<< " w:" << frame.w
									<< " h:" << frame.h << endl;
						}
						frames.push_back(row);
					}
					const Value& states = sprite["states"];
					for(Value::ConstValueIterator itr = states.Begin(); itr != states.End(); ++itr)
					{
						const Value& state = *itr;
						if( state.HasMember("direction") &&
							state.HasMember("action"),
							state.HasMember("row"),
							state.HasMember("columns") )
						{
							cout << "state " << state["direction"].GetString() << " " << state["action"].GetString() << " Good!" << endl;
							int row = state["row"].GetInt() - 1; // to go from 1-indexed to 0-indexed
							int columns = state["columns"].GetInt();
							cout << "row: " << row << " columns: " << columns << endl;
							string action = state["action"].GetString();
							string direction = state["direction"].GetString();
							unsigned int state = 0;
							if(action == "idle") {
								state |= StateComponent::Action::IDLE;
							} else if(action == "move") {
								state |= StateComponent::Action::MOVE;
							}

							if(direction == "u") {
								state |= StateComponent::Direction::UP;
							} else if(direction == "d") {
								state |= StateComponent::Direction::DOWN;
							} else if(direction == "l") {
								state |= StateComponent::Direction::LEFT;
							} else if(direction == "r") {
								state |= StateComponent::Direction::RIGHT;
							}

							cout << "State: " << state << endl;

							vector<SDL_Rect> spriteFrames;
							for(int i = 0; i < columns; i++) {
								SDL_Rect f = frames[row][i];
								cout << "Adding frame: " << endl
										<< "x: " << f.x << " y: " << f.y << " w: " << f.w << " h: " << f.h << endl
										<< "to state: " << state << endl;
								spriteFrames.push_back(frames[row][i]);
							}

							Vec2<int> offset = {12, 26}; // TODO: Decide where offset should go (Sprite | SpriteState) so we can load it from the json file.

							SpriteState s{spriteFrames, offset};

							spr.addState(state, s);
						}
					}
				}
				else
				{
					cout << "Missing a member of sprite " << name << endl;
				}
			}
			else
			{
				cout << "No member called " << name << endl;
			}
		}
		else
		{
			cout << "Document doesn't have sprites!" << endl;
		}
	}
	else
	{
		cout << "Document not an object" << endl;
	}

	return spr;
}

SdlTexture SpriteFactory::makeTexture(string imageFile, const GameWindow& window)
{
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
		if( texture.texture == NULL )
		{
			cout << "Failed to create texture!" << endl;
			//_logger.log( LogSeverities::ERROR, "Failed to create texture!" );
		}
		else
		{
			cout << "Created texture!" << endl;
		}
	}

	return texture;
}
