#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef TILE_H
#define TILE_H

class Tile
{
public:
	bool IsPassable;
	bool IsExit;
	sf::Vector2f TilePos;
	sf::Texture TileTexture;
	sf::Sprite TileSprite;
	Tile(std::string, float, float, bool, bool);
	bool SetupTileSprite(std::string);
};

#endif

