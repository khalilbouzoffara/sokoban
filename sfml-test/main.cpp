#include <SFML/Graphics.hpp>
#include <iostream>
//#define WIDTH 1500 //1500
//#define HEIGHT 800 //800
#include "Level.h"
#include "Game.h"
int main()
{
    Game sokoban;
    sokoban.gameLoop();

    return 0;
}
