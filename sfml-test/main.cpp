#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.h"
//#define WIDTH 1500 //1500
//#define HEIGHT 800 //800
#include "Level.h"
#include "Game.h"
int main()
{   cout << "hello world";
    Game sokoban;
    sokoban.gameLoop();
    //MainMenu M;
    //M.MenuLoop();
    return 0;
}
