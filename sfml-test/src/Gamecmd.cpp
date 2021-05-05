#include "Gamecmd.h"
#include <bits/stdc++.h>
using namespace std;
Gamecmd::Gamecmd()
{
    Level l;
    l.loadCarte();
    Personnage _(lvl);
    p=_;
    lvl=l;

}
Gamecmd::Gamecmd(Level lvl1)
{

    lvl=lvl1;
    Personnage g(lvl);
    p = g;
}
void setLevel(Level l){

};

void Gamecmd::testing(int n) {
//    for (int i = 0; i < lvl.getcarte().size(); i++) {
//    cout << lvl.getcarte()[i][0] << " ";
//    cout << "hello";
//    }
//    p.debug();
    //lvl.loadcarte();
    bool b;
    b=p.getindestination();
    Personnage g(lvl);
    p=g;
    p.setindestination(b);

    //lvl.affichagecarte();
    vector<vector<int>> testmap;
    //testmap is the matrix you can use as an example while working,
    // it the the representation of level Example1.txt in a vector<vector<char>>
    testmap=lvl.getcarte();
    //Personnage p(lvl);
   // p.debug();
    //***********************
    p.move(testmap);
    //*****************************
    switch(n)
		{
		case 8:
			up(mapeu);
			break;

		case 5:
			down(mapeu);
			break;

		case 4:
			left(mapeu);
			break;

		case 6:
			right(mapeu);
			break;
		}
    //**************************************

    cout << endl;

    lvl.setcarte(testmap);
    lvl.affichagecarte();

    p.debug();

}

int Gamecmd::NombreDe_b(){
    int ct=0 ;
    for (int i = 0; i < lvl.getcarte().size(); i++) {
        for (int j = 0; j <  lvl.getcarte()[1].size(); j++){
            if (lvl.getcarte()[i][j] == 'b')
               ct++ ;

            }
            }
            return ct ;


}

void Gamecmd::mainloop(int n){
char s;
s='.';
p.setindestination(false);
lvl.affichagecarte();
int b ;
b=NombreDe_b() ;
cout<< b ;
while (b>0 ) {
    testing(n);
    b=NombreDe_b();
    }
}

void Gamecmd::mainloopOnce(){
char s;
s='.';
p.setindestination(false);
lvl.affichagecarte();
int b ;
b=NombreDe_b() ;
cout<< b ;
if (b>0) {
    testing();
    b=NombreDe_b();
    }
}


Gamecmd::~Gamecmd()
{

}
