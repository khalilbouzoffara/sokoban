#ifndef PERSONNAGE_H
#define PERSONNAGE_H
 #include "Objet.h"
 #include <bits/stdc++.h>
 #include <level.h>
 using namespace std;

// Perso Hérite d'objet
class Personnage
{
   private :

        int x;
        int y;
        bool indestination ;
   public:
       Personnage();
       Personnage(Level);
   //Position initial de player dépend mil level
       void initialiser_position(int,int);
   //Debug
       void debug();
    //Mouvma
       void setindestination(bool);
       bool getindestination();
       void up(vector<vector<int>>&);
       void down(vector<vector<int>>&);
       void left(vector<vector<int>>&);
       void right(vector<vector<int>>&);
       char move(vector<vector<int>>&);

};
#endif
