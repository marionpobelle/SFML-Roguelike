#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>


#ifndef GAME_H
#define GAME_H

class Game
{
public:
	std::vector< std::vector<Tile*> > Tiles;
	int GridLength;
	//Player
	void MoveLeft();
	void MoveUp();
	void MoveRight();
	void MoveDown();

	Game();
private:
	sf::Vector2i _exitPos;
	sf::Vector2i _playerPos;
	std::vector<sf::Vector2i> _enemyPositions;
	void SetupInitialState();
	void SetupEnemyPositions();
	void SetupTiles();
	void RedrawSprites();
	//Player
	std::vector<sf::Vector2i> GetFreeCoordinates(sf::Vector2i);
	bool CheckIfPositionIsFree(sf::Vector2i);
	//Enemies
	void MoveEnemies();
	//Reset
	bool CheckIfReachedExit();
	bool CheckIfTouchedEnemy();
	void CheckCollisionsAndMoveEnemies();



};

#endif

