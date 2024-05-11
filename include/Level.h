#ifndef LEVEL_H
#define LEVEL_H
#include <bits/stdc++.h>
using namespace std;


class Level
{
    private:
        // les dimensions de carte, une matrice (ROW,COL)
        int row;
        int col;
        // le numero du niveau
        int num;
        // la matrice du carte
        vector<vector<char>> carte;
    public:
        //constructors
        Level();
            //you give it the dimensions
        Level(int,int);
        //destructor
        virtual ~Level();
        //Setters and getters
        void setrow(int);
        int getrow();
        void setcol(int);
        int getcol();
        void setcarte(vector<vector<char>>);
        vector<vector<char>> getcarte();
        //creation du matrice carte on the spot(once program ikaml yetexecuta tetfase5, ma7atitelhesh save into txt)
        void createcarte();
        //Loading a matrix from text file: for now it will only load the lvl example1 thus no arguments
        void loadcarte();
        //affichage de carte
        void affichagecarte();
        //pour maintenant vide
        void initialiserniveau();

};

#endif // LEVEL_H
