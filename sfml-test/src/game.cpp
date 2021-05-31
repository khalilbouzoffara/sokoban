#include "Game.h"
#include "Level.h"
#include "cell.h"
#include "MainMenu.h"
#include "variables.h"
#include "Help.h"
#include "LvlMenu.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>


#define HEIGHT 600
#define WIDTH 850
Game::Game()
{
    //Initialiser Level and personnage
    Level l;
    l.loadCarte(1);
    Personnage _(lvl);
    p=_;
    p.setindestination(false);
    p.debug();
    lvl=l;

    //open window
    window = new RenderWindow(VideoMode(WIDTH, HEIGHT), "Sokoban");
    window->setFramerateLimit(60);
    levelInitialiser();


}

Game::Game(Level lvl1)
{

    lvl=lvl1;
    Personnage g(lvl);
    p = g;
}


void Game::moveP(int n)
{
    bool b;
    b=p.getindestination();
    Personnage g(lvl);
    p=g;
    p.setindestination(b);
    //  cout << "we entered testingv2"<<endl;
    p.debug();
    //lvl.affichagecarte();
    vector<vector<int>> testmap;
    //testmap is the matrix you can use as an example while working,
    // it the the representation of level Example1.txt in a vector<vector<char>>
    //lvl.loadCarte basically updates the variable carte to our level
    testmap=lvl.getcarte();
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
    lvl.setcarte(testmap);
    p.debug();
}

int Game::NombreDe_b()
{
    int ct=0 ;
    for (int i = 0; i < lvl.getcarte().size(); i++)
    {
        for (int j = 0; j <  lvl.getcarte()[i].size(); j++)
        {
            if (lvl.getcarte()[i][j] == 3 )
                ct++ ;

        }
    }
    return ct ;


}


void Game::gameInitaliser(sf::RenderWindow &win)
{
    //render objects
    sf::Vector2u TextureSize;  //Added to store texture size.
    sf::Vector2u WindowSize;
    sf::Sprite bak(gameBG); //Added to store window size
    gameBG.loadFromFile("textures/back.png");
    TextureSize = gameBG.getSize(); //Get size of texture.
    WindowSize = window->getSize();             //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    bak.setTexture(gameBG);
    bak.setScale(ScaleX, ScaleY); //Set scale
    win.draw(bak);

}

void Game::levelInitialiser()
{
    int initialX = 20, initialY = 50;
    for (int i = 0; i <lvl.getcarte().size(); i++)
    {
        initialX = 100;
        for (int j = 0; j <lvl.getcarte()[i].size(); j++)
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

    switch(status)
    {
    case 0://MM
        MM.Draw(*window);
        break;
    case 1://game
        //render cycle
    {
        window->clear();

        gameInitaliser(*window);

        for (int i = 0; i < lvl.getcarte().size(); i++)
        {
            for (int j = 0; j < lvl.getcarte()[i].size(); j++)
            {
                mapA[i][j].draw(*window);
            }
        }
        //Display
        window->display();
        break;
    }
    case 2://Help 1
        window->clear();
        H.drawHelp(*window,0);
        break;
    case 3://LvlMenu
        LM.DrawIT(*window);
        break;
    case 5:
        window->clear();
        H.drawHelp(*window,1);
        break;

    }


}


void Game::gameLoop()
{
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (status)
            {
            case 0://MM

                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        if (MM.getPBS())
                        {
                            MM.setPBS(false);
                            MM.setHBS(false);
                            MM.setEBS(true);
                            MM.setABS(false);
                        }
                        else if (MM.getHBS())
                        {
                            MM.setPBS(true);
                            MM.setHBS(false);
                            MM.setEBS(false);
                            MM.setABS(false);
                        }
                        else if (MM.getEBS())
                        {
                            MM.setPBS(false);
                            MM.setHBS(false);
                            MM.setEBS(false);
                            MM.setABS(true);
                        }
                        else if (MM.getABS())
                        {

                            MM.setPBS(false);
                            MM.setHBS(true);
                            MM.setEBS(false);
                            MM.setABS(false);

                        }
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        if (MM.getPBS())
                        {
                            MM.setPBS(false);
                            MM.setHBS(true);
                            MM.setEBS(false);
                            MM.setABS(false);

                        }
                        else if (MM.getHBS())
                        {
                            MM.setPBS(false);
                            MM.setHBS(false);
                            MM.setEBS(false);
                            MM.setABS(true);
                        }
                        else if (MM.getEBS())
                        {
                            MM.setPBS(true);
                            MM.setHBS(false);
                            MM.setEBS(false);
                            MM.setABS(false);
                        }
                        else if (MM.getABS())
                        {
                            MM.setPBS(false);
                            MM.setHBS(false);
                            MM.setEBS(true);
                            MM.setABS(false);

                        }
                    }
                    if (event.key.code == sf::Keyboard::Return)
                    {
                        if (MM.getPBS())
                        {
                            status =3;
                        }
                        if(MM.getHBS())
                        {
                            status=5;

                        }
                        if(MM.getEBS())
                        {
                            window->close();
                        }
                        if(MM.getABS())
                        {
                            status=69;

                        }
                        MM.setPBS(true);
                        MM.setHBS(false);
                        MM.setEBS(false);
                        MM.setABS(false);
                    }
                    break;
                }
            case 1://game
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        moveP(8);
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        moveP(5);
                    }

                    if (event.key.code == sf::Keyboard::Right)
                    {
                        moveP(6);
                    }
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        moveP(4);
                    }
                    if(event.key.code == sf::Keyboard::Escape)
                    {
                        status=0;
                    }
                    if (event.key.code == sf::Keyboard::R)
                    {
                        Level l;
                        l.loadCarte(lvlNumber);
                        Personnage _(l);
                        p=_;
                        p.setindestination(false);
                        p.debug();

                        lvl=l;
                        lvl.affichageCarte();
                    }
                    int b;
                    b=NombreDe_b() ;
                    if (b==0)
                    {
                        status=4;
                    }

                }

                break;
            case 3: //LvlMenu
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        int k=0;
                        for (int i=0; i<10; i++)
                        {
                            if(LM.getLvlS(i))
                            {
                                k=i;
                            }
                        }
                        //setting the color right on which level is chosen
                        if (k<9)
                        {
                            LM.setLvlS(k,false);
                            LM.setLvlS(k+1,true);
                        }
                        else
                        {
                            LM.setLvlS(9,false);
                            LM.setLvlS(0,true);
                        }

                        //change Level
                        if (lvlNumber<10)
                        {
                            lvlNumber++;
                        }
                        else lvlNumber=1;
                    }

                    if(event.key.code == sf::Keyboard::Left)
                    {
                        int k=0;
                        for(int i=0; i<10; i++)
                        {
                            if(LM.getLvlS(i))
                            {
                                k=i;
                            }
                        }
                        //setting the color right on which level is chosen
                        if (k>0)
                        {
                            LM.setLvlS(k,false);
                            LM.setLvlS(k-1,true);
                        }
                        else
                        {
                            LM.setLvlS(0,false);
                            LM.setLvlS(9,true);
                        }

                        //change Level
                        if (lvlNumber>1)
                        {
                            lvlNumber--;
                        }
                        else lvlNumber=10;
                    }
                    if(event.key.code == sf::Keyboard::Escape)
                    {
                        status=0;
                    }
                    if (event.key.code == sf::Keyboard::Return)
                    {
                        status=1;
                        Level l;
                        l.loadCarte(lvlNumber);
                        Personnage _(l);
                        p=_;
                        p.setindestination(false);
                        p.debug();
                        lvl=l;
                        memoir=5;
                    }

                }
                break;
            case 4://Level end
            {
                sf::Text next;
                sf::Text retourn;

                sf::Font font ;
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        if(!nextPressed)
                        {
                            nextPressed=true;
                            RetourPressed=false;
                        }
                    }
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        if(!RetourPressed)
                        {
                            nextPressed=false;
                            RetourPressed=true;
                        }
                    }
                    if (event.key.code == sf::Keyboard::Return)
                    {
                        if (nextPressed)
                        {
                            if (lvlNumber<10)
                            {
                                lvlNumber++;
                            }
                            else lvlNumber=1;
                            status=1;
                            Level l;
                            l.loadCarte(lvlNumber);
                            Personnage _(l);
                            p=_;
                            p.setindestination(false);
                            p.debug();
                            lvl=l;
                            memoir=5;

                        }
                        /*
                        if (RetourPressed)
                        {
                            if (lvlNumber==1)
                            {
                                lvlNumber=10;

                            }
                            else lvlNumber--;
                            status=1;
                            Level l;
                            l.loadCarte(lvlNumber);
                            Personnage _(l);
                            p=_;
                            p.setindestination(false);
                            p.debug();
                            lvl=l;
                            memoir=5;

                        }
                        */
                        if (RetourPressed)
                        {
                            status=3;

                        }
                    }
                }
                if (!font.loadFromFile("textures/Bokka Solid Regular.otf"))
                {
                    std::cout<<"error" ;
                }
                // next button
                next.setFont(font);
                next.setString("Next");
                next.setOrigin(next.getLocalBounds().width / 2,
                               next.getLocalBounds().height / 2);
                next.setPosition(window->getSize().x -78.f,
                                 window->getSize().y -75.f);
                next.setCharacterSize(33);

                //retour Button
                retourn.setFont(font);
                retourn.setString("Return");
                retourn.setOrigin(retourn.getLocalBounds().width / 2,
                                  retourn.getLocalBounds().height / 2);
                retourn.setPosition(85,
                                    window->getSize().y -75.f);
                retourn.setCharacterSize(27);
                //Change colour
                if(nextPressed)
                {
                    next.setFillColor(sf::Color::Cyan);
                    retourn.setFillColor(sf::Color::White);

                }
                else if (RetourPressed)
                {
                    next.setFillColor(sf::Color::White);
                    retourn.setFillColor(sf::Color::Cyan);
                }

                //Draw
                sf::Texture t;
                sf::Texture taswira1;
                sf::Texture taswira2;
                taswira1.loadFromFile("textures/&é.png");
                taswira2.loadFromFile("textures/zere.png");
                t.loadFromFile("textures/You win.png");


                sf::Sprite s(t);
                sf::Sprite s1(taswira1);
                s1.setTexture(taswira1);
                sf::Sprite s2(taswira2);
                s2.setTexture(taswira2);
                s.setOrigin(s.getLocalBounds().width / 2 -250.f, s.getLocalBounds().height / 2 -100.f);
                s.setPosition(window->getSize().x/2-250, window->getSize().y/2-100);
                s1.setPosition(window->getSize().x/2-110, window->getSize().y/2-135);
                s2.setPosition(-105, window->getSize().y/2-135);

                window->draw(s);
                window->draw(s2);
                window->draw(s1);
                window->draw(s1);
                window->draw(next);
                window->draw(retourn);
                window->display();
                break;
            }
            case 2:
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                        status=5;

                }
                break;

            case 5:
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                        status=0;

                }
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::N)
                        status=2;

                }
                break;
            case 69 ://About
                sf::Vector2u TextureSize;  //Added to store texture size.
                sf::Vector2u WindowSize;   //Added to store window size.
                sf::Texture t;
                t.loadFromFile("textures/about.png");
                sf::Sprite s(t);
                TextureSize = t.getSize(); //Get size of texture.
                WindowSize = window->getSize();             //Get size of window.

                float ScaleX = (float) WindowSize.x / TextureSize.x;
                float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.
                sf::Font font ;
                if (!font.loadFromFile("textures/Bokka Solid Regular.otf"))
                {
                    std::cout<<"error" ;
                }
                //esc button

                sf::Text ESC;
                ESC.setFont(font);
                ESC.setString("Esc");
                ESC.setOrigin(ESC.getLocalBounds().width / 2 +575.f,ESC.getLocalBounds().height / 2 +40.f);
                ESC.setPosition(window->getSize().x -78.f,window->getSize().y -75.f);
                ESC.setCharacterSize(40);
                s.setTexture(t);
                s.setScale(ScaleX, ScaleY);      //Set scale
                window->clear(sf::Color::White);
                window->draw(s);
                window->draw(ESC);
                window->display();
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                        status=0;

                }

            }





        }
        if (event.type == sf::Event::Closed )
        {
            window->close();
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
