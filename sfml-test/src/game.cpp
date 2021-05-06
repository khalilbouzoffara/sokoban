#include "Game.h"
#include "Level.h"
#include "cell.h"
#include "MainMenu.h"
#include "variables.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#define HEIGHT 600
#define WIDTH 850
Game::Game()
{
    //Initialiser Level and personnage
    Level l;
    l.loadCarte();
    Personnage _(lvl);
    p=_;
    p.setindestination(false);
    //cout<<"bouhou"<<endl;
    p.debug();
    lvl=l;

    //open window
    window = new RenderWindow(VideoMode(WIDTH, HEIGHT), "Sokoban");
    gameInitaliser();
    levelInitialiser();


}

Game::Game(Level lvl1)
{

    lvl=lvl1;
    Personnage g(lvl);
    p = g;
}

void setLevel(Level l)
{
// lvl=l;
};

void Game::testing(int n)
{
//    for (int i = 0; i < lvl.getcarte().size(); i++) {
//    cout << lvl.getcarte()[i][0] << " ";
    cout << "we entered testingv1"<<endl;
//    }
//    p.debug();
    //lvl.loadcarte();
    bool b;
    b=p.getindestination();
    Personnage g(lvl);
    p=g;
    p.setindestination(b);
    cout << "we entered testingv2"<<endl;
    p.debug();
    //lvl.affichagecarte();
    vector<vector<int>> testmap;
    //testmap is the matrix you can use as an example while working,
    // it the the representation of level Example1.txt in a vector<vector<char>>
    testmap=lvl.getcarte();
    //Personnage p(lvl);
    // p.debug();
    //***********************
    //p.move(testmap);
    //*****************************
    cout << "we entered testingv3"<<endl;
    switch(n)
    {
    case 8:
        p.up(testmap);
        break;

    case 5:
        p.down(testmap);
        break;

    case 4:
        p.left(testmap);
        break;

    case 6:
        p.right(testmap);
        break;
    }
    //**************************************

    cout << endl;

    lvl.setcarte(testmap);

    //lvl.affichageCarte();   // This seriously invoked a bug


    p.debug();


}

int Game::NombreDe_b()
{
    int ct=0 ;
    for (int i = 0; i < lvl.getcarte().size(); i++)
    {
        for (int j = 0; j <  lvl.getcarte()[1].size(); j++)
        {
            if (lvl.getcarte()[i][j] == 3 )
                ct++ ;

        }
    }
    return ct ;


}

void Game::mainloop(int n)
{
    char s;
    s='.';
    p.setindestination(false);
    lvl.affichageCarte();
    int b ;
    b=NombreDe_b() ;
    cout<< b ;
    while (b>0 )
    {
        testing(n);
        b=NombreDe_b();
    }
}

void Game::mainloopOnce(int n)
{
    char s;
    s='.';
//p.setindestination(false);     //************
//lvl.affichageCarte();
    int b ;
    b=NombreDe_b() ;
    cout<< b ;

    if (b>0)
    {
        testing(n);
        b=NombreDe_b();
    }
}

void Game::gameInitaliser()
{
    //Game background
    Color background(47, 75, 110);
    gameBG.setFillColor(background);
    gameBG.setPosition(0, 0);
    gameBG.setSize(Vector2f(WIDTH, HEIGHT));
    //Initialise Personnage Gamecmd and Level vars.
//        cout << "Hello world!" << endl;
//        lvl.loadcarte();
//        Gamecmd G(lvl);
//        G.setLevel(lvl);
    //G.mainloopOnce();
    //G();
}

void Game::levelInitialiser()
{
    //G.mainloopOnce();
    //Level lvl(6,10);
    //lvl.loadCarte();

    int initialX = 10, initialY = 100;

    for (int i = 0; i <6; i++)
    {
        initialX = 100;
        for (int j = 0; j <10; j++)
        {
            switch(lvl.getcarte()[i][j])
            {
            case 0:
                mapA[i][j].setType(0);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 1:
                mapA[i][j].setType(1);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 2:
                mapA[i][j].setType(2);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 3:
                mapA[i][j].setType(3);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 4:
                mapA[i][j].setType(4);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            case 5:
                mapA[i][j].setType(5);
                mapA[i][j].setPosition(initialX, initialY);
                mapA[i][j].initialiser();
                break;
            }
            initialX += 64;
        }
        initialY += 64;
        initialX = 64;
    }
}

void Game::render()
{
    /*

    */
    switch(status)
    {
    case 0://MM
        MM.Draw(*window);
        break;
    case 1://game
        //render cycle
        window->clear();
        //render objects

        window->draw(gameBG);
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                mapA[i][j].draw(*window);
            }
        }
        //Display
        window->display();
        break;
    }





}


void Game::gameLoop()
{
    while (window->isOpen())
    {
        //Handle Events
        //cout << "Window is opened"<< endl;
        sf::Event event;
        while (window->pollEvent(event))
        {
            //cout<<"event loop entered "<<endl;
            switch (status)
            {
            case 0://MM
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                {
                    if (!MM.getPBS())
                    {
                        MM.setPBS(true);
                        MM.setEBS(false);
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if (!MM.getEBS())
                    {
                        MM.setPBS(false);
                        MM.setEBS(true);
                    }
                    break;
                }
                case sf::Keyboard::Return:
                {
                    MM.setPBP(false);
                    MM.setEBS(false);

                    if (MM.getPBS())
                    {
                        MM.setPBP(true);
                    }
                    else
                    {
                        MM.setEBP(true);
                    }

                    break;
                }

                }//end 2nd while

                if(MM.getPBP())
                {
                    status=1;
                }
                else if(MM.getEBP())
                {
                    window->close();
                }
                break;

            case 1:
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        mainloopOnce(8);
                        cout<<" up" << endl;
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        mainloopOnce(5);
                        cout<<" Down" << endl;
                    }

                    if (event.key.code == sf::Keyboard::Right)
                    {
                        mainloopOnce(6);
                        cout<<" Right" << endl;
                        //testing(6);
                    }
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        mainloopOnce(4);

                        cout<<"Left" << endl;
                    }
                    if (event.key.code == sf::Keyboard::R)
                    {
                        cout<<"R" << endl;

                        Level l;
                        l.loadCarte();
                        Personnage _(lvl);
                        p=_;
                        p.setindestination(false);
                        //cout<<"bouhou"<<endl;
                        p.debug();
                        lvl=l;

                    }
                }
                break;
            }



            if (event.type == sf::Event::Closed)
            {
                window->close();
            }






        }
        //update scene
        levelInitialiser();
        render();

    }
}

Game::~Game()
{
    delete window;
}
