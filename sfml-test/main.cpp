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

    system("pause 0");
    return 0;
}
