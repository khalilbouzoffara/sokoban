#include "Personnage.h"
#include <bits/stdc++.h>
using namespace std;
Personnage::Personnage() {
}
Personnage::Personnage(Level lvl)  {

    for (int i = 0; i < lvl.getcarte().size(); i++) {
        for (int j = 0; j <  lvl.getcarte()[i].size(); j++){
            if (lvl.getcarte()[i][j] == 4) {
                x = i;
                y = j;
            }
        }
    }
}



void Personnage::debug(){
//cout << "(" << x << "," << y << ")" << endl;
}

void Personnage::setindestination(bool f){
    indestination=f;
}
bool Personnage::getindestination(){
    return(indestination);
}
void Personnage::up(vector<vector<int>>& mapeu)
{

    if (mapeu[x-1][y] == 0 )
    {
        //cout << mapeu[x][y] << endl;
        //mapeu[0][0] = 'K';
        mapeu[x-1][y] = 4;
        // mapeu[x][y] = '.';
        //cout << getindestination() << endl;
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else
            mapeu[x][y] = 0;
        x--;
    }
    else if ( (mapeu[x-1][y] == 3) && (mapeu[x-2][y] == 0) )
    {
        mapeu[x-1][y] = 4;
        mapeu[x-2][y] = 3;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        x--;
    }
    else if (mapeu[x-1][y] == 2 )
    {

        mapeu[x-1][y] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else
        {
            mapeu[x][y] = 0;//cout<< "shouldntcomehere" << endl;
        }
        x--;
        //Save
        setindestination(true);
        //cout << "indestinationvalue " << getindestination() << endl;
    }
    else if ( (mapeu[x-1][y] == 5) && (mapeu[x-2][y] == 0) )
    {
        mapeu[x-1][y] = 4;
        mapeu[x-2][y] = 3;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        x--;
        //Save
        setindestination(true);
    }
    else if ( (mapeu[x-1][y] == 3) && (mapeu[x-2][y] == 2) )
    {
        mapeu[x-1][y] = 4;
        mapeu[x-2][y] = 5;
        //mapeu[x][y] = '.';

        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        x--;
    }
    else if ( (mapeu[x-1][y] == 5) && (mapeu[x-2][y] == 2) )
    {
        mapeu[x-1][y] = 4;
        mapeu[x-2][y] = 5;
        //mapeu[x][y] = '.';

        if (getindestination())
        {
            mapeu[x][y] = 2;
        }
        else             mapeu[x][y] = 0;
        x--;
        //save
        setindestination(true);
    }

}

void Personnage::down(vector<vector<int>>& mapeu)
{
    if (mapeu[x+1][y] == 0 )
    {
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        mapeu[x+1][y] = 4;
        x++;
    }
    else if ( (mapeu[x+1][y] == 3) && (mapeu[x+2][y] == 0) )
    {
        mapeu[x+2][y] = 3;
        mapeu[x+1][y] = 4;
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        //mapeu[x][y] = '.';
        x++;
    }
    else if (mapeu[x+1][y] == 2 )
    {
        mapeu[x][y] = 0;
        mapeu[x+1][y] = 4;
        x++;
        //save
        setindestination(true);
    }
    else if ( (mapeu[x+1][y] == 3) && (mapeu[x+2][y] == 2) )
    {
        mapeu[x+2][y] = 5;
        mapeu[x+1][y] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        x++;
    }
    else if ( (mapeu[x+1][y] == 5) && (mapeu[x+2][y] == 0) )
    {
        mapeu[x+2][y] = 3;
        mapeu[x+1][y] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        x++;
        //save
        setindestination(true);
    }
    else if ( (mapeu[x+1][y] == 5) && (mapeu[x+2][y] == 2) )
    {
        mapeu[x+2][y] = 5;
        mapeu[x+1][y] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        x++;
        //save
        setindestination(true);
    }
}

void Personnage::right(vector<vector<int>>& mapeu)
{


    if (mapeu[x][y+1] == 0 )
    {
        mapeu[x][y+1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y++;
    }

    else if ( (mapeu[x][y+1] == 3) && (mapeu[x][y+2] == 0) )
    {
        mapeu[x][y+2] = 3;
        mapeu[x][y+1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y++;
    }
    else if ( (mapeu[x][y+1] == 3) && (mapeu[x][y+2] == 2) )
    {
        mapeu[x][y+2] = 5;
        mapeu[x][y+1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y++;
    }
    else if ( (mapeu[x][y+1] == 5) && (mapeu[x][y+2] == 0) )
    {
        mapeu[x][y+2] = 3;
        mapeu[x][y+1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y++;
        //save
        setindestination(true);
    }
    else if ( (mapeu[x][y+1] == 5) && (mapeu[x][y+2] == 2) )
    {
        mapeu[x][y+2] = 5;
        mapeu[x][y+1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y++;
        //save
        setindestination(true);
    }

    else if (mapeu[x][y+1] == 2 )
    {
        mapeu[x][y+1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 4;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y++;

        //save
        setindestination(true);
    }
}


void Personnage::left(vector<vector<int>>& mapeu)
{


    if (mapeu[x][y-1] == 0 )
    {
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        mapeu[x][y-1] = 4;
        y--;
    }

    else if ( (mapeu[x][y-1] == 3) && (mapeu[x][y-2] == 0) )
    {
        mapeu[x][y-2] = 3;
        mapeu[x][y-1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y--;
    }
    else if ( (mapeu[x][y-1] == 3) && (mapeu[x][y-2] == 2) )
    {
        mapeu[x][y-2] = 5;
        mapeu[x][y-1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y--;
    }
    else if ( (mapeu[x][y-1] == 5) && (mapeu[x][y-2] == 0) )
    {
        mapeu[x][y-2] = 3;
        mapeu[x][y-1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y--;
        //save
        setindestination(true);
    }
    else if ( (mapeu[x][y-1] == 5) && (mapeu[x][y-2] == 2) )
    {
        mapeu[x][y-2] = 5;
        mapeu[x][y-1] = 4;
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        y--;
        //save
        setindestination(true);
    }
    else if (mapeu[x][y-1] == 2 )
    {
        //mapeu[x][y] = '.';
        if (getindestination())
        {
            mapeu[x][y] = 2;
            setindestination(false);
        }
        else             mapeu[x][y] = 0;
        mapeu[x][y-1] = 4;
        y--;
        //save
        setindestination(true);
    }
}


char Personnage::move(vector<vector<int>>& mapeu){


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
		}

    return(c);
}
