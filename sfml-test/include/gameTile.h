#ifndef GAMETILE_H
#define GAMETILE_H

#include <SFML/Graphics.hpp>

class gameTile
{
    public:
        gameTile(std::string , float , float , bool , bool );
        bool setUpSprite(std::string );
        bool isPassable;
        bool isExit;
        sf::Vector2f pos;
        sf::Texture texture;
        sf::Sprite sprite;
        virtual ~gameTile();
};

#endif // GAMETILE_H
