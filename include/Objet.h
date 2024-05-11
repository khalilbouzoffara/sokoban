#ifndef OBJET_H
#define OBJET_H
#include <bits/stdc++.h>
using namespace std;

enum type_objet{ Mur='#', Perso='J', Box='.', Empty_Box='.', Destination ='d', Box_in_Destination ='B'};
//Class mére comme un Carreau qui contient les objets
class Objet
{
   protected :

    //Les Cordonnées d'objet
       int x ;
       int y ;
    //Type d'objet que le carreau contient
       type_objet ob ;


    public :

    //constructors
        Objet();
    //you give it the dimensions
        Objet(int,int);
    //destructor
        virtual ~Objet();
     //Setters and getters
        void setrow(int);
        int getrow();
        void setcol(int);
        int getcol();
     //Vérifer le type
        bool Is_Box() const;
        bool Is_Perso() const;
        bool Is_Mur() const;
        bool Is_Empty_Box() const;
        bool Is_Destination() const;
     //Retour le type
     type_objet Contenue_Objet();
     //Vider l'objet(iwali empty waktili t7arek box wala perso yetharek (nitsawer najmou na7iw objet empty '.' w nikhmou blech bih))
        void Vider_objet();

};
#endif
