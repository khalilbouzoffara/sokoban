#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace sf;
class Game
{
    public:
        Game();
        void gameInitaliser();
        void levelInitialiser();
        void gameLoop();
        virtual ~Game();

    private:
        RenderWindow *window;
};

#endif // GAME_H
