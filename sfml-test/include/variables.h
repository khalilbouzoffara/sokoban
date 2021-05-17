#ifndef VARIABLES_H
#define VARIABLES_H
#include "MainMenu.h"
#include "Game.h"
#include "Level.h"
#include "cell.h"
#include "Help.h"
#include "LvlMenu.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
 using namespace std;
 using namespace sf;

// notre carte
cell mapA[6][10];

sf::Texture gameBG;


MainMenu MM;
LvlMenu LM;
Help H;
int status=0;
int memoir=5;
int lvlNumber=1;
#endif // VARIABLES_H
