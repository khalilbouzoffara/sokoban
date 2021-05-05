#ifndef GAMECMD_H
#define GAMECMD_H
#include <level.h>
#include <Personnage.h>
#include <Objet.h>
#include <bits/stdc++.h>
#include <game.h>

using namespace std;


class Gamecmd
{    //private:
    public:
        Level lvl;
        Personnage p;
        friend class game;
     public:
        Gamecmd();
        Gamecmd(Level);
        void setLevel(Level);
        virtual ~Gamecmd();
        void testing(int);
        int NombreDe_b();
        void mainloop(int n);
};

#endif // Gamecmd_H
