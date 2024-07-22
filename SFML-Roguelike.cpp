// SFML-Roguelike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(768, 768), "SFML-Roguelike");
    Game game = Game();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) 
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    game.MoveLeft();
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
                {
                    game.MoveUp();
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
                {
                    game.MoveRight();
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
                {
                    game.MoveDown();
                }
            }                
        }

        window.clear();
        for (int i = 0; i < game.GridLength; i++) 
        {
            for (int j = 0; j < game.GridLength; j++) 
            {
                window.draw(game.Tiles[i][j]->TileSprite);
            }
        }
        window.display();
    }
    return 0;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
