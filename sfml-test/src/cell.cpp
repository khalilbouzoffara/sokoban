#include "cell.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>


cell::cell()
{

    if (!cellTexture.loadFromFile("textures/player/playerDown.png"))
    {
        std::cout << "error pour charger le joueur" << std::endl;
    }
    cellSprite.setTexture(cellTexture, true);

}


void cell::setType(int t)
{
    switch (t)
    {
    case 0:
        typeCell = space;
        break;
    case 1:
        typeCell = wall;
        break;
    case 2:
        typeCell = destination;
        break;
    case 3:
        typeCell = box;
        break;
    case 4:
        typeCell = player;
        break;
    case 5:
        typeCell = box_win;
        break;
    }
}


void cell::initialiser()
{

    switch (typeCell)
    {
    case 0: // space
        if (!cellTexture.loadFromFile("textures/none.png"))
        {
            std::cout << "error pour charger l'espace" << std::endl;
        }

        cellSprite.setTexture(cellTexture, true);
        break;
    case 1: // wall
        if (!cellTexture.loadFromFile("textures/wall.png"))
        {
            std::cout << "error pour charger le mur" << std::endl;
        }
        cellSprite.setTexture(cellTexture, true);

        break;
    case 2: // destination
        if (!cellTexture.loadFromFile("textures/finishPoint.png"))
        {
            std::cout << "error pour charger la destination" << std::endl;
        }
        cellSprite.setTexture(cellTexture, true);

        break;

    case 3: // box


        if (!cellTexture.loadFromFile("textures/box.png"))
        {
            std::cout << "error pour charger le box" << std::endl;
        }
        cellSprite.setTexture(cellTexture, true);

        break;

    case 4: // player

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (!cellTexture.loadFromFile("textures/player/playerLeft.png"))
            {
                std::cout << "error pour charger le joueur" << std::endl;
            }
            cellSprite.setTexture(cellTexture, true);

            memoir=4;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (!cellTexture.loadFromFile("textures/player/playerRight.png"))
            {
                std::cout << "error pour charger le joueur" << std::endl;
            }
            cellSprite.setTexture(cellTexture, true);
            memoir=6;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (!cellTexture.loadFromFile("textures/player/playerDown.png"))
            {
                std::cout << "error pour charger le joueur" << std::endl;
            }
            cellSprite.setTexture(cellTexture, true);
             memoir=5;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (!cellTexture.loadFromFile("textures/player/playerUp.png"))
            {
                std::cout << "error pour charger le joueur" << std::endl;
            }
            cellSprite.setTexture(cellTexture, true);
             memoir=8;
        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            if (!cellTexture.loadFromFile("textures/player/playerDown.png"))
            {
                std::cout << "error pour charger le joueur" << std::endl;
            }
            cellSprite.setTexture(cellTexture, true);
             memoir=5;
        }
          else
        {   if (memoir==5){
            if (!cellTexture.loadFromFile("textures/player/playerDown.png"))
            {
                std::cout << "error pour charger le joueur" << std::endl;
            }
            cellSprite.setTexture(cellTexture, true);
        }
        else if (memoir==8){
            if (!cellTexture.loadFromFile("textures/player/playerUp.png"))
            {
                std::cout << "error pour charger le joueur" << std::endl;
            }
            cellSprite.setTexture(cellTexture, true);
        }else if (memoir==4){
            if (!cellTexture.loadFromFile("textures/player/playerLeft.png"))
            {
                std::cout << "error pour charger le joueur" << std::endl;
            }
            cellSprite.setTexture(cellTexture, true);
        }else if (memoir==6){
            if (!cellTexture.loadFromFile("textures/player/playerRight.png"))
            {
                std::cout << "error pour charger le joueur" << std::endl;
            }
            cellSprite.setTexture(cellTexture, true);
        }
        }

        break;

    case 5: // box_win
        if (!cellTexture.loadFromFile("textures/boxOnGoal.png"))
        {
            std::cout << "error pour charger le box a la destination" << std::endl;
        }
        cellSprite.setTexture(cellTexture, true);

        break;
    }

}
cell::tile cell::getType()
{
    return typeCell;
}


void cell::draw(sf::RenderWindow& window)
{
    window.draw(cellSprite);
}

void cell::setPosition(int x, int y)
{
    cellSprite.setPosition(x,y);
}

sf::Vector2f cell::getPosition()
{
    return cellSprite.getPosition();
}


cell::~cell()
{

}
