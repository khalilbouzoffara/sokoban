#include "Game.h"
#include "Level.h"
#include "cell.h"
#include "variables.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#define HEIGHT 500
#define WIDTH 700

Game::Game()
{
    window = new RenderWindow(VideoMode(WIDTH, HEIGHT), "Sokoban");
    gameInitaliser();
    levelInitialiser();
}

void Game::gameInitaliser()
{
    //Game background
    Color background(47, 75, 110);
    gameBG.setFillColor(background);
    gameBG.setPosition(0, 0);
    gameBG.setSize(Vector2f(WIDTH, HEIGHT));
}

void Game::levelInitialiser()
{
    Level lvl(6,10);
    lvl.loadCarte();
    int initialX = 10, initialY = 100;

    for (int i = 0; i <6; i++)
    {
        initialX = 100;
        for (int j = 0; j <10; j++)
        {
            switch(lvl.getCarte()[i][j])
            {
            case 0:
                mapA[i][j].setType(0);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].setSize(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 1:
                mapA[i][j].setType(1);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].setSize(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 2:
                mapA[i][j].setType(2);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].setSize(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 3:
                mapA[i][j].setType(3);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].setSize(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 4:
                mapA[i][j].setType(4);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].setSize(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 5:
                mapA[i][j].setType(5);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].setSize(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            }
            initialX += 50;
        }
        initialY += 50;
        initialX = 50;
    }
}



void Game::gameLoop()
{

    while (window->isOpen())
    {

        sf::Event event;
        while (window->pollEvent(event))
        {


            if (event.type == sf::Event::Closed)
                window->close();
        }

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                mapA[i][j].draw(*window);
            }
        }

        window->display();
        window->clear();
        window->draw(gameBG);

    }


}



Game::~Game()
{
    delete window;
}
