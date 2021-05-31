#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>
extern int memoir;
class cell
{
    private:
        enum tile {space, wall, destination, box, player,  box_win};
        sf::Sprite cellSprite;
        sf::Texture cellTexture;
        tile typeCell;
        bool onDest;
    public:
        cell();
        tile getType();
        void setType(int);
        void setPosition(int,int);
         void initialiser();
        void initialiser(int);
        void draw(sf::RenderWindow&);
        virtual ~cell();
};

#endif // CELL_H
