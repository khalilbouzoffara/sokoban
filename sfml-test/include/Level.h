#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <vector>


class Level
{
    public:
        Level();
        Level(int,int);
        void loadCarte();
        std::vector<std::vector<int>> getcarte();
        void affichageCarte();
        virtual ~Level();
        void setcarte(std::vector<std::vector<int>>);
    private:
        std::vector<std::vector<int>> carte;
        int row;
        int col;
        int mapSize;
        bool initalized;
};

#endif // LEVEL_H
