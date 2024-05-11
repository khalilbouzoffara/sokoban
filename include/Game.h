#ifndef GAME_H
#define GAME_H
#include <level.h>
#include <Personnage.h>
#include <Objet.h>
#include <bits/stdc++.h>
using namespace std;


class Game
{    private:
        Level lvl;
        Personnage p;
     public:
        Game(Level);
        virtual ~Game();
        void testing();
        int NombreDe_b();
        void mainloop();
};

#endif // Game_H
