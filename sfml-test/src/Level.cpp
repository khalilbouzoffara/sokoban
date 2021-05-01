#include "Level.h"
#include <fstream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

Level::Level(int jrow, int jcol)
{
    row=jrow;
    col=jcol;
}

void Level::loadCarte()
{
    //opening text file
    ifstream inFile;
    inFile.open(".\\Levels\\Level Example1.txt");
    //Verif file was opened
    if (!inFile)
    {
        cerr << "Unable to open the text file";
        exit(1);   // call system to stop
    }
    //transform the text file into a matrix and save it in carte
    string tempstr;                   // declare a temporary string
    char tempint;                           // declare a temporary character called temporary int :D
    //char delimiter=' ';                        // declare a temporary delimiter
    while (getline(inFile, tempstr))     // read line by line from a file into a string
    {
        istringstream iss(tempstr);   // initialize the stringstream with that string

        vector<int> tempv;            // declare a temporary vector for the row
        while (iss >> tempint)             // extract the numbers from a stringstream
        {
            switch (tempint)
            {
            case '.':
                tempv.push_back(0);
                break;
            case '#':
                tempv.push_back(1);
                break;
            case 'd':
                tempv.push_back(2);
                break;
            case 'b':
                tempv.push_back(3);
                break;
            case 'J':
                tempv.push_back(4);
                break;
            case 'B':
                tempv.push_back(5);
                break;
            }
                  // push it onto our temporary vector
            //iss >> delimiter;              // read the delimiter(in the text file i made it without delimiters)
        }

        carte.push_back(tempv);                // push the vector onto vector of vectors
    }

    inFile.close();
}

void Level::affichageCarte()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << carte[i][j] << " ";
        cout << endl;
    }
}

std::vector<std::vector<int>> Level::getCarte()
{
    return carte;
}
Level::~Level()
{
    //dtor
}
