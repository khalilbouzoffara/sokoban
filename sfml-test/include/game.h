#ifndef GAME_H
#define GAME_H
#include "Personnage.h"
#include "Level.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
class Game
{
    public:
        Game(); //Constructor
        Game(Level); //and another one
        void levelInitialiser(int);
        void gameInitaliser(sf::RenderWindow &); //Background initialiser
        void levelInitialiser(); //Grahpical map update
        void render();
        void gameLoop();      //Window opened and drawing Graphical carte as well as key pressors
        void moveP(int); //Take one move and change Level and personnage accordingly
        int NombreDe_b(); //Check if game ended
        virtual ~Game();
    private:
        RenderWindow *window;
        Level lvl;
        Personnage p;
        bool nextPressed=true;
        bool RetourPressed=false;
};

#endif // GAME_H
