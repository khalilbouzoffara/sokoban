#include "gameTile.h"
#include <iostream>
#include <string>
gameTile::gameTile(std::string textureName, float x, float y, bool passable, bool exit)
{
    if (!setUpSprite(textureName))
    {
        return;
    }
    pos = sf::Vector2f(x,y);
    sprite.setPosition(pos);
    isPassable = passable;
    isExit = exit;

}

bool gameTile::setUpSprite(std::string textureName)
{
    sf::Texture texture;

    if (!texture.loadFromFile(textureName))
    {
        std::cout<<"could not load the current texture";
        return false;
    }
    texture.setSmooth(true);  //the texture appears smoother so that pixels are less noticeable
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,50,50));

    return true;
}


gameTile::~gameTile()
{
    //dtor
}
