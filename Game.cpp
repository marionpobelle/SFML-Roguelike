#include "Game.h"

Game::Game() 
{
	GridLength = 8;
	SetupInitialState();
}

void Game::SetupEnemyPositions() 
{
	_enemyPositions.clear();
	_enemyPositions.push_back(sf::Vector2i(0, 2));
	_enemyPositions.push_back(sf::Vector2i(6, 0));
	_enemyPositions.push_back(sf::Vector2i(2, 7));
}

void Game::SetupTiles()
{
	Tiles.clear();
	std::vector<Tile*> firstRow;
	firstRow.push_back(new Tile("Assets/wall.png", 0, 0, false, false));
	firstRow.push_back(new Tile("Assets/door.png", 96, 0, true, true));
	firstRow.push_back(new Tile("Assets/wall.png", 192, 0, false, false));
	firstRow.push_back(new Tile("Assets/wall.png", 288, 0, false, false));
	firstRow.push_back(new Tile("Assets/wall.png", 384, 0, false, false));
	firstRow.push_back(new Tile("Assets/wall.png", 480, 0, false, false));
	firstRow.push_back(new Tile("Assets/enemy.png", 576, 0, true, false));
	firstRow.push_back(new Tile("Assets/wall.png", 672, 0, false, false));
	Tiles.push_back(firstRow);

	std::vector<Tile*> secondRow;
	secondRow.push_back(new Tile("Assets/wall.png", 0, 96, false, false));
	secondRow.push_back(new Tile("Assets/ground.png", 96, 96, true, false));
	secondRow.push_back(new Tile("Assets/ground.png", 192, 96, true, false));
	secondRow.push_back(new Tile("Assets/ground.png", 288, 96, true, false));
	secondRow.push_back(new Tile("Assets/ground.png", 384, 96, true, false));
	secondRow.push_back(new Tile("Assets/ground.png", 480, 96, true, false));
	secondRow.push_back(new Tile("Assets/ground.png", 576, 96, true, false));
	secondRow.push_back(new Tile("Assets/ground.png", 672, 96, true, false));
	Tiles.push_back(secondRow);

	std::vector<Tile*> thirdRow;
	thirdRow.push_back(new Tile("Assets/enemy.png", 0, 192, true, false));
	thirdRow.push_back(new Tile("Assets/ground.png", 96, 192, true, false));
	thirdRow.push_back(new Tile("Assets/ground.png", 192, 192, true, false));
	thirdRow.push_back(new Tile("Assets/wall.png", 288, 192, false, false));
	thirdRow.push_back(new Tile("Assets/ground.png", 384, 192, true, false));
	thirdRow.push_back(new Tile("Assets/ground.png", 480, 192, true, false));
	thirdRow.push_back(new Tile("Assets/wall.png", 576, 192, false, false));
	thirdRow.push_back(new Tile("Assets/wall.png", 672, 192, false, false));
	Tiles.push_back(thirdRow);

	std::vector<Tile*> fourthRow;
	fourthRow.push_back(new Tile("Assets/wall.png", 0, 288, false, false));
	fourthRow.push_back(new Tile("Assets/ground.png", 96, 288, true, false));
	fourthRow.push_back(new Tile("Assets/ground.png", 192, 288, true, false));
	fourthRow.push_back(new Tile("Assets/wall.png", 288, 288, false, false));
	fourthRow.push_back(new Tile("Assets/ground.png", 384, 288, true, false));
	fourthRow.push_back(new Tile("Assets/ground.png", 480, 288, true, false));
	fourthRow.push_back(new Tile("Assets/ground.png", 576, 288, true, false));
	fourthRow.push_back(new Tile("Assets/wall.png", 672, 288, false, false));
	Tiles.push_back(fourthRow);

	std::vector<Tile*> fifthRow;
	fifthRow.push_back(new Tile("Assets/wall.png", 0, 384, false, false));
	fifthRow.push_back(new Tile("Assets/ground.png", 96, 384, true, false));
	fifthRow.push_back(new Tile("Assets/ground.png", 192, 384, true, false));
	fifthRow.push_back(new Tile("Assets/wall.png", 288, 384, false, false));
	fifthRow.push_back(new Tile("Assets/wall.png", 384, 384, false, false));
	fifthRow.push_back(new Tile("Assets/ground.png", 480, 384, true, false));
	fifthRow.push_back(new Tile("Assets/ground.png", 576, 384, true, false));
	fifthRow.push_back(new Tile("Assets/ground.png", 672, 384, true, false));
	Tiles.push_back(fifthRow);

	std::vector<Tile*> sixthRow;
	sixthRow.push_back(new Tile("Assets/ground.png", 0, 480, true, false));
	sixthRow.push_back(new Tile("Assets/ground.png", 96, 480, true, false));
	sixthRow.push_back(new Tile("Assets/ground.png", 192, 480, true, false));
	sixthRow.push_back(new Tile("Assets/ground.png", 288, 480, true, false));
	sixthRow.push_back(new Tile("Assets/wall.png", 384, 480, false, false));
	sixthRow.push_back(new Tile("Assets/ground.png", 480, 480, true, false));
	sixthRow.push_back(new Tile("Assets/ground.png", 576, 480, true, false));
	sixthRow.push_back(new Tile("Assets/wall.png", 672, 480, false, false));
	Tiles.push_back(sixthRow);

	std::vector<Tile*> seventhRow;
	seventhRow.push_back(new Tile("Assets/wall.png", 0, 576, false, false));
	seventhRow.push_back(new Tile("Assets/wall.png", 96, 576, false, false));
	seventhRow.push_back(new Tile("Assets/ground.png", 192, 576, true, false));
	seventhRow.push_back(new Tile("Assets/ground.png", 288, 576, true, false));
	seventhRow.push_back(new Tile("Assets/ground.png", 384, 576, true, false));
	seventhRow.push_back(new Tile("Assets/ground.png", 480, 576, true, false));
	seventhRow.push_back(new Tile("Assets/wall.png", 576, 576, false, false));
	seventhRow.push_back(new Tile("Assets/wall.png", 672, 576, false, false));
	Tiles.push_back(seventhRow);
		
	std::vector<Tile*> eighthRow;
	eighthRow.push_back(new Tile("Assets/wall.png", 0, 672, false, false));
	eighthRow.push_back(new Tile("Assets/wall.png", 96, 672, false, false));
	eighthRow.push_back(new Tile("Assets/enemy.png", 192, 672, true, false));
	eighthRow.push_back(new Tile("Assets/wall.png", 288, 672, false, false));
	eighthRow.push_back(new Tile("Assets/wall.png", 384, 672, false, false));
	eighthRow.push_back(new Tile("Assets/ground.png", 480, 672, true, false));
	eighthRow.push_back(new Tile("Assets/ground.png", 576, 672, true, false));
	eighthRow.push_back(new Tile("Assets/player.png", 672, 672, true, false));
	Tiles.push_back(eighthRow);

}

void Game::SetupInitialState() 
{
	_exitPos = sf::Vector2i(1, 0);
	_playerPos = sf::Vector2i(GridLength - 1, GridLength - 1);
	SetupEnemyPositions();
	SetupTiles();
}

void Game::RedrawSprites() 
{
	Tiles[_playerPos.y][_playerPos.x]->SetupTileSprite("Assets/player.png");
	for (int i = 0; i < _enemyPositions.size(); i++) 
	{
		sf::Vector2i currentEnemyPos = _enemyPositions[i];
		Tiles[currentEnemyPos.y][currentEnemyPos.x]->SetupTileSprite("Assets/enemy.png");
	}
}

void Game::MoveLeft() 
{
	if (_playerPos.x == 0) return; 
	if (!Tiles[_playerPos.y][_playerPos.x - 1]->IsPassable) return; 
	Tiles[_playerPos.y][_playerPos.x]->SetupTileSprite("Assets/ground.png");
	_playerPos.x -= 1;
	CheckCollisionsAndMoveEnemies();
}

void Game::MoveUp() 
{
	if (_playerPos.y == 0) return; 
	if (!Tiles[_playerPos.y - 1][_playerPos.x]->IsPassable) return; 
	Tiles[_playerPos.y][_playerPos.x]->SetupTileSprite("Assets/ground.png");
	_playerPos.y -= 1;
	CheckCollisionsAndMoveEnemies();
}

void Game::MoveRight() 
{
	if (_playerPos.x == GridLength - 1) return; 
	if (!Tiles[_playerPos.y][_playerPos.x + 1]->IsPassable) return; 
	Tiles[_playerPos.y][_playerPos.x]->SetupTileSprite("Assets/ground.png");
	_playerPos.x += 1;
	CheckCollisionsAndMoveEnemies();
}

void Game::MoveDown() 
{
	if (_playerPos.y == GridLength - 1) return; 
	if (!Tiles[_playerPos.y + 1][_playerPos.x]->IsPassable) return; 
	Tiles[_playerPos.y][_playerPos.x]->SetupTileSprite("Assets/ground.png");
	_playerPos.y += 1;
	CheckCollisionsAndMoveEnemies();
}

bool Game::CheckIfPositionIsFree(sf::Vector2i pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.x > 7 || pos.y > 7)
	{
		return false;
	}
	if (!Tiles[pos.y][pos.x]->IsPassable) 
	{
		return false;
	}
	if (Tiles[pos.y][pos.x]->IsExit) 
	{
		return false;
	}
	return true;
}

std::vector<sf::Vector2i> Game::GetFreeCoordinates(sf::Vector2i currentPos)
{
	std::vector<sf::Vector2i> freePositions;
	std::vector<sf::Vector2i> allPositions;
	allPositions.push_back(sf::Vector2i(currentPos.x - 1, currentPos.y));
	allPositions.push_back(sf::Vector2i(currentPos.x - 1, currentPos.y - 1));
	allPositions.push_back(sf::Vector2i(currentPos.x, currentPos.y - 1));
	allPositions.push_back(sf::Vector2i(currentPos.x + 1, currentPos.y - 1));
	allPositions.push_back(sf::Vector2i(currentPos.x + 1, currentPos.y));
	allPositions.push_back(sf::Vector2i(currentPos.x + 1, currentPos.y + 1));
	allPositions.push_back(sf::Vector2i(currentPos.x, currentPos.y + 1));
	allPositions.push_back(sf::Vector2i(currentPos.x - 1, currentPos.y + 1));
	for (int i = 0; i < 8; i++) {
		if (CheckIfPositionIsFree(allPositions[i])) {
			freePositions.push_back(allPositions[i]);
		}
	}
	return freePositions;
}

void Game::MoveEnemies()
{
	for (int i = 0; i < _enemyPositions.size(); i++) 
	{
		sf::Vector2i currentEnemyPos = _enemyPositions[i];
		std::vector<sf::Vector2i> freePositions = GetFreeCoordinates(currentEnemyPos);
		int randomIndex = rand() % (freePositions.size() - 1);
		sf::Vector2i newPos = freePositions[randomIndex];
		Tiles[currentEnemyPos.y][currentEnemyPos.x]->SetupTileSprite("Assets/ground.png");
		_enemyPositions[i] = newPos;
	}
}

bool Game::CheckIfReachedExit() 
{
	return _playerPos.x == _exitPos.x && _playerPos.y == _exitPos.y;
}

bool Game::CheckIfTouchedEnemy() 
{
	for (int i = 0; i < _enemyPositions.size(); i++) 
	{
		sf::Vector2i currentEnemyPos = _enemyPositions[i];
		if (_playerPos.x == currentEnemyPos.x && _playerPos.y == currentEnemyPos.y) 
		{
			return true;
		}
	}
	return false;
}

void Game::CheckCollisionsAndMoveEnemies()
{
	if (CheckIfReachedExit())
	{
		SetupInitialState();
		return;
	}
	MoveEnemies();
	if (CheckIfTouchedEnemy())
	{
		SetupInitialState();
		return;
	}
	RedrawSprites();
}