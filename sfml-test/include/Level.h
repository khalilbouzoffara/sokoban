#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <vector>


class Level
{
    public:
        Level(int,int);
        void loadCarte();
        std::vector<std::vector<int>> getCarte();
        void affichageCarte();
        virtual ~Level();

    private:
        std::vector<std::vector<int>> carte;
        int row;
        int col;
        int mapSize;
        bool initalized;
};

#endif // LEVEL_H
