#include "Personnage.h"
#include "Objet.h"
#include <bits/stdc++.h>
using namespace std;
Personnage::Personnage() : Objet(){
}
Personnage::Personnage(Level lvl) : Objet() {

    for (int i = 0; i < lvl.getcarte().size(); i++) {
        for (int j = 0; j <  lvl.getcarte()[1].size(); j++){
            if (lvl.getcarte()[i][j] == 'J') {
                x = i;
                y = j;
            }
        }
    }
}
//Constructeur aves héritage(a vérifeir si objet need 2 arguments w personnage 4 wale)
Personnage::Personnage(int x1 , int y1) : Objet() {
    x=x1;
    y=y1;
}


void Personnage::debug(){
cout << "(" << x << "," << y << ")" << endl;
}

void Personnage::setindestination(bool f){
    indestination=f;
}
bool Personnage::getindestination(){
    return(indestination);
}

void Personnage::up(vector<vector<char>> &mapeu){

    if (mapeu[x-1][y] == '.' ){
        //cout << mapeu[x][y] << endl;
        //mapeu[0][0] = 'K';
        mapeu[x-1][y] = 'J';
        // mapeu[x][y] = '.';
        //cout << getindestination() << endl;
        if (getindestination()){
            mapeu[x][y] = 'd';
            setindestination(false);
        }
        else
            mapeu[x][y] = '.';
        x--;
    }
    else if ( (mapeu[x-1][y] == 'b') && (mapeu[x-2][y] == '.') ) {
        mapeu[x-1][y] = 'J';
        mapeu[x-2][y] = 'b';
        //mapeu[x][y] = '.';
        if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        x--;
    }
    else if (mapeu[x-1][y] == 'd' ){

                mapeu[x-1][y] = 'J';
                //mapeu[x][y] = '.';
                if (getindestination()){
                    mapeu[x][y] = 'd';setindestination(false);
                }
                else{
                    mapeu[x][y] = '.';//cout<< "shouldntcomehere" << endl;
                }
                x--;
                //Save
                setindestination(true);
                //cout << "indestinationvalue " << getindestination() << endl;
    }
     else if ( (mapeu[x-1][y] == 'B') && (mapeu[x-2][y] == '.') ) {
        mapeu[x-1][y] = 'J';
        mapeu[x-2][y] = 'b';
        //mapeu[x][y] = '.';
        if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        x--;
        //Save
        setindestination(true);
    }
    else if ( (mapeu[x-1][y] == 'b') && (mapeu[x-2][y] == 'd') ) {
        mapeu[x-1][y] = 'J';
        mapeu[x-2][y] = 'B';
        //mapeu[x][y] = '.';

          if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
                else             mapeu[x][y] = '.';
        x--;
    }
     else if ( (mapeu[x-1][y] == 'B') && (mapeu[x-2][y] == 'd') ) {
        mapeu[x-1][y] = 'J';
        mapeu[x-2][y] = 'B';
        //mapeu[x][y] = '.';

                if (getindestination()) {mapeu[x][y] = 'd';}
                else             mapeu[x][y] = '.';
        x--;
        //save
         setindestination(true);
    }

}

void Personnage::down(vector<vector<char>> &mapeu)
{
    if (mapeu[x+1][y] == '.' )
    {
        //mapeu[x][y] = '.';
          if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        mapeu[x+1][y] = 'J';
        x++;
    }
    else if ( (mapeu[x+1][y] == 'b') && (mapeu[x+2][y] == '.') )
    {
        mapeu[x+2][y] = 'b';
        mapeu[x+1][y] = 'J';
          if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        //mapeu[x][y] = '.';
        x++;
    }
    else if (mapeu[x+1][y] == 'd' )
    {
        mapeu[x][y] = '.';
        mapeu[x+1][y] = 'J';
        x++;
        //save
         setindestination(true);
    }
    else if ( (mapeu[x+1][y] == 'b') && (mapeu[x+2][y] == 'd') )
    {
        mapeu[x+2][y] = 'B';
        mapeu[x+1][y] = 'J';
        //mapeu[x][y] = '.';
          if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        x++;
    }
    else if ( (mapeu[x+1][y] == 'B') && (mapeu[x+2][y] == '.') )
    {
        mapeu[x+2][y] = 'b';
        mapeu[x+1][y] = 'J';
        //mapeu[x][y] = '.';
          if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        x++;
        //save
         setindestination(true);
    }
    else if ( (mapeu[x+1][y] == 'B') && (mapeu[x+2][y] == 'd') )
    {
        mapeu[x+2][y] = 'B';
        mapeu[x+1][y] = 'J';
        //mapeu[x][y] = '.';
          if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        x++;
        //save
        setindestination(true);
    }
}

void Personnage::right(vector<vector<char>> &mapeu){


            if (mapeu[x][y+1] == '.' ){
                mapeu[x][y+1] = 'J';
                //mapeu[x][y] = '.';
                if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
                y++;
    }

    else if ( (mapeu[x][y+1] == 'b') && (mapeu[x][y+2] == '.') ) {
        mapeu[x][y+2] = 'b';
        mapeu[x][y+1] = 'J';
        //mapeu[x][y] = '.';
        if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        y++;
    }
    else if ( (mapeu[x][y+1] == 'b') && (mapeu[x][y+2] == 'd') ) {
        mapeu[x][y+2] = 'B';
        mapeu[x][y+1] = 'J';
        //mapeu[x][y] = '.';
        if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        y++;
    }
    else if ( (mapeu[x][y+1] == 'B') && (mapeu[x][y+2] == '.') ) {
        mapeu[x][y+2] = 'b';
        mapeu[x][y+1] = 'J';
        //mapeu[x][y] = '.';
        if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        y++;
        //save
        setindestination(true);
    }
    else if ( (mapeu[x][y+1] == 'B') && (mapeu[x][y+2] == 'd') ) {
        mapeu[x][y+2] = 'B';
        mapeu[x][y+1] = 'J';
        //mapeu[x][y] = '.';
        if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        y++;
        //save
        setindestination(true);
    }

     else if (mapeu[x][y+1] == 'd' ){
                mapeu[x][y+1] = 'J';
                //mapeu[x][y] = '.';
                if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
                y++;

        //save
        setindestination(true);
    }
}


void Personnage::left(vector<vector<char>> &mapeu){


            if (mapeu[x][y-1] == '.' ){
                //mapeu[x][y] = '.';
                 if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
                mapeu[x][y-1] = 'J';
                y--;
    }

    else if ( (mapeu[x][y-1] == 'b') && (mapeu[x][y-2] == '.') ) {
        mapeu[x][y-2] = 'b';
        mapeu[x][y-1] = 'J';
        //mapeu[x][y] = '.';
         if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        y--;
    }
    else if ( (mapeu[x][y-1] == 'b') && (mapeu[x][y-2] == 'd') ) {
        mapeu[x][y-2] = 'B';
        mapeu[x][y-1] = 'J';
        //mapeu[x][y] = '.';
         if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        y--;
    }
    else if ( (mapeu[x][y-1] == 'B') && (mapeu[x][y-2] == '.') ) {
        mapeu[x][y-2] = 'b';
        mapeu[x][y-1] = 'J';
        //mapeu[x][y] = '.';
         if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        y--;
        //save
         setindestination(true);
    }
    else if ( (mapeu[x][y-1] == 'B') && (mapeu[x][y-2] == 'd') ) {
        mapeu[x][y-2] = 'B';
        mapeu[x][y-1] = 'J';
        //mapeu[x][y] = '.';
         if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
        y--;
        //save
         setindestination(true);
    }
    else if (mapeu[x][y-1] == 'd' ){
                //mapeu[x][y] = '.';
                 if (getindestination()) {mapeu[x][y] = 'd';setindestination(false);}
        else             mapeu[x][y] = '.';
                mapeu[x][y-1] = 'J';
                y--;
                //save
                setindestination(true);
    }
}



char Personnage::move(vector<vector<char>>& mapeu){


    //cout << getindestination();
	char c ;
	cout<<"Your move: ";
	cin >> c ;
	cout << endl;
	switch(c)
		{
		case 'z':
			up(mapeu);
			break;

		case 's':
			down(mapeu);
			break;

		case 'q':
			left(mapeu);
			break;

		case 'd':
			right(mapeu);
			break;
//        case 'd':
//			right(mapeu);
//			break;
		}

    return(c);
}
