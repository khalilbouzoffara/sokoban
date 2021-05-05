#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.h"
#define HEIGHT 650
#define WIDTH 800
#include "Level.h"
#include "Game.h"
int main()
{
    Game sokoban;
    sokoban.gameLoop();
    //sf::RenderWindow *window;
    //window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Sokoban");
    //MainMenu M;
    //M.MenuLoop(*window);
    return 0;
}
