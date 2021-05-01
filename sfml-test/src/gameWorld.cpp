#include "gameWorld.h"

gameWorld::gameWorld()
{
    gridLength = 8;
    setUpInitialStates();
}

void gameWorld::setUpInitialStates()
{
    exitPos = sf::Vector2i(1,0);
    playerPos = sf::Vector2i(gridLength - 1,gridLength - 1);
    setUpEnemyPositions();
    setUpTiles();
}

void gameWorld::setUpEnemyPositions()
{
    enemyPositions.clear();
    enemyPositions.push_back(sf::Vector2i(0,2));
    enemyPositions.push_back(sf::Vector2i(6,0));
    enemyPositions.push_back(sf::Vector2i(2,7));

}

void gameWorld::setUpTiles()
{
    tiles.clear();
    std::vector < gameTile *> firstRow;
    firstRow.push_back(new gameTile("textures/wall.png",0,0,false,false));
    firstRow.push_back(new gameTile("textures/finishPoint.png",50,0,true,true));
    firstRow.push_back(new gameTile("textures/wall.png",100,0,false,false));
    firstRow.push_back(new gameTile("textures/wall.png",150,0,false,false));
    firstRow.push_back(new gameTile("textures/wall.png",200,0,false,false));
    firstRow.push_back(new gameTile("textures/wall.png",250,0,false,false));
    firstRow.push_back(new gameTile("textures/player/playerDown.png",300,0,true,true));
    firstRow.push_back(new gameTile("textures/wall.png",350,0,false,false));
    tiles.push_back(firstRow);

    std::vector < gameTile *> secondRow;
    secondRow.push_back(new gameTile("textures/wall.png",0,0,false,false));
    secondRow.push_back(new gameTile("textures/finishPoint.png",50,0,true,true));
    secondRow.push_back(new gameTile("textures/wall.png",100,0,false,false));
    secondRow.push_back(new gameTile("textures/wall.png",150,0,false,false));
    secondRow.push_back(new gameTile("textures/wall.png",200,0,false,false));
    secondRow.push_back(new gameTile("textures/wall.png",250,0,false,false));
    secondRow.push_back(new gameTile("textures/player/playerDown.png",300,0,true,true));
    secondRow.push_back(new gameTile("textures/wall.png",350,0,false,false));
    tiles.push_back(secondRow);

}



gameWorld::~gameWorld()
{
    //dtor
}
