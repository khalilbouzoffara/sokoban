#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "MainMenu.h"
#define HEIGHT 850
#define WIDTH 1000
#include "Level.h"
#include "Game.h"
#include "Help.h"
#include "LvlMenu.h"
int main()
{
    Game sokoban;
    sokoban.gameLoop();
    //sf::RenderWindow *window;
    //window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Sokoban");

    //Help H;
    //H.loop(*window);
    //MainMenu M;
    //M.MenuLoop(*window);

    return 0;
}
