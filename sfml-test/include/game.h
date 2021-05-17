#ifndef GAME_H
#define GAME_H
#include "Personnage.h"
#include "Level.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

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
        void setLevel(Level); //Level Setter
        void mainloopOnce(int n); //does testing and check if game ended
        void testing(int); //Take one move and change Level and personnage accordingly
        int NombreDe_b(); //Check if game ended
        void mainloop(int n);   //does mainloopOnce in a while till game ends;
        virtual ~Game();
    private:
        RenderWindow *window;
        Level lvl;
        Personnage p;
        bool nextPressed=true;
        bool RetourPressed=false;
};

#endif // GAME_H
