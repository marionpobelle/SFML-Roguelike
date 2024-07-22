#include "Tile.h"

Tile::Tile(std::string textureName, float x, float y, bool passable, bool exit) 
{
	if (!SetupTileSprite(textureName)) {
		return;
	}
	TilePos = sf::Vector2f(x, y);
	TileSprite.setPosition(TilePos);
	IsPassable = passable;
	IsExit = exit;
}

bool Tile::SetupTileSprite(std::string textureName) {
	if (!TileTexture.loadFromFile(textureName)) {
		std::cout << "Could not load tile texture !" << std::endl;
		return false;
	}
	TileTexture.setSmooth(true);
	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
	return true;
}
