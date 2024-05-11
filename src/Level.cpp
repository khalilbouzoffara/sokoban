#include "Level.h"
#include <bits/stdc++.h>
using namespace std;

Level::Level()
{

}
Level::Level(int jrow,int jcol)
{   row=jrow;
    col=jcol;

}

Level::~Level()
{

}

void Level::setrow(int n){
    row=n;
}

int Level::getrow(){
    return(row);
}

void Level::setcol(int n){
    col=n;
}

int Level::getcol(){
    return(col);
}
void Level::setcarte(vector<vector<char>> _){
    carte = _;

}
vector<vector<char>> Level::getcarte(){
    return(carte);
}

void Level::createcarte()
{       char c;
    for (int i = 0; i < row; i++) {
        // Vector to store column elements
        vector<char> v1;

        for (int j = 0; j < col; j++) {
            cout <<"case(" << i << "," << j << ")" << endl;
            cin >> c ;
            v1.push_back(c);
        }

        // Pushing back above 1D vector
        // to create the 2D vector
        carte.push_back(v1);
    }
}

void Level::loadcarte(){
    //opening text file
    ifstream inFile;
    inFile.open(".\\Levels\\Level Example1.txt");
    //Verif file was opened
    if (!inFile) {
    cerr << "Unable to open the text file";
    exit(1);   // call system to stop
        }
    //transform the text file into a matrix and save it in carte
    string tempstr;                   // declare a temporary string
    char tempint;                           // declare a temporary character called temporary int :D
    //char delimiter=' ';                        // declare a temporary delimiter
    while (getline(inFile, tempstr)) {   // read line by line from a file into a string
        istringstream iss(tempstr);   // initialize the stringstream with that string

        vector<char> tempv;            // declare a temporary vector for the row
    while (iss >> tempint) {           // extract the numbers from a stringstream
        tempv.push_back(tempint);      // push it onto our temporary vector
        //iss >> delimiter;              // read the delimiter(in the text file i made it without delimiters)
    }
    carte.push_back(tempv);                // push the vector onto vector of vectors
}

    inFile.close();
}

void Level::affichagecarte() {
     for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << carte[i][j] << " ";
        cout << endl;
    }
}

void Level::initialiserniveau(){
    loadcarte();
}
