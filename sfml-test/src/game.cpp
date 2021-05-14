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
//    cout << "we entered testingv1"<<endl;
//    }
//    p.debug();
    //lvl.loadcarte();
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
    cout<< lvlNumber<<endl;
    cout<<"The testing function's affichage carte" << endl;
//    lvl.affichageCarte();
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
    cout << endl;
    lvl.setcarte(testmap);
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
    //lvl.affichageCarte();
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
    int b ;
    b=NombreDe_b() ;
    cout<< b <<endl;

    if (b>0)
    {
        testing(n);
        b=NombreDe_b();
    }
    else
    {
        status=4;
    }
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
        //  cout<<"still drawing case 1" <<endl;
        window->draw(gameBG);

        for (int i = 0; i < lvl.getrow(); i++)
        {
            for (int j = 0; j < lvl.getcol(); j++)
            {
                mapA[i][j].draw(*window);
            }
        }
        //Display
        window->display();
        break;
    case 2://Help
        window->clear();
        H.drawHelp(*window);
        break;
    case 3://LvlMenu
        LM.DrawIT(*window);
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
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        cout<<"case 0: upped"<<endl;
                        if (MM.getPBS())
                        {
                            cout<<"case 0: PBS"<<endl;
                            MM.setPBS(false);
                            MM.setHBS(false);
                            MM.setEBS(true);
                        }
                        else if (MM.getHBS())
                        {
                            cout<<"case 0: HBS"<<endl;
                            MM.setPBS(true);
                            MM.setHBS(false);
                            MM.setEBS(false);
                        }
                        else if (MM.getEBS())
                        {
                            cout<<"case 0: EBS"<<endl;
                            MM.setPBS(false);
                            MM.setHBS(true);
                            MM.setEBS(false);
                        }
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        cout<<"case 0: Down"<< endl;
                        if (MM.getPBS())
                        {
                            cout<<"case 0: EBS"<< endl;
                            MM.setPBS(false);
                            MM.setHBS(true);
                            MM.setEBS(false);
                        }
                        else if (MM.getHBS())
                        {
                            cout<<"case 0: HBS"<< endl;
                            MM.setPBS(false);
                            MM.setHBS(false);
                            MM.setEBS(true);
                        }
                        else if (MM.getEBS())
                        {
                            cout<<"case 0: EBS"<< endl;
                            MM.setPBS(true);
                            MM.setHBS(false);
                            MM.setEBS(false);
                        }
                    }
                    if (event.key.code == sf::Keyboard::Return)
                    {
                        cout<<"case 0: return pressed" << endl;

                        if (MM.getPBS())
                        {
                            cout<<"case 0: PBS : Status =1"<<endl;
                            status =3;
                            cout<< "status = " << status;
                            //MM.setPBP(true);
                        }
                        if(MM.getHBS())
                        {
                            status=2;

                        }
                        if(MM.getEBS())
                        {
                            cout<<"case 0: EBS :window will be closed"<<endl;
                            window->close();
                        }
                        MM.setPBS(true);
                        MM.setHBS(false);
                        MM.setEBS(false);
                    }
                    break;
                    cout<<status<<endl;
                }
            case 1://game
                int b;
                b=NombreDe_b() ;
                cout<< b <<endl;
                if (b==0)
                {   cout<<"d5al"<<endl;
                   status=4;
                }
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
                        l.loadCarte(lvlNumber);
                        Personnage _(l);
                        p=_;
                        p.setindestination(false);
                        //cout<<"bouhou"<<endl;
                        p.debug();

                        lvl=l;
                        lvl.affichageCarte();

                    }
                }
                break;
            case 3: //LvlMenu
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        int k=-1;
                        for (int i=0; i<10; i++)
                        {
                            if(LM.getLvlS(i))
                            {
                                cout<<"case 0: PBS"<<i<<endl;
                                //LM.setLvlS(i,false);
                                //LM.setLvlS(i+1,true);
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
                        cout<<"lvl Number: "<< lvlNumber<< endl;
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
            case 4:
//                int b;
//                b=NombreDe_b() ;
//                cout<< b <<endl;
//                if (b==0)
//                {   cout<<"d5al"<<endl;
//                    mainloopOnce(8);
//                    mainloopOnce(4);
//                     mainloopOnce(5);
//                }
                sf::Text next;
                sf::Text retourn;

                sf::Font font ;
                if (event.type == sf::Event::KeyPressed)
                {
                    cout<<"suckiit" ;


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
                        if (RetourPressed)
                        {
                            status=3;

                        }
                    }
                }
                if (!font.loadFromFile("textures/Pacifico-Regular .ttf"))
                {
                    std::cout<<"error" ;
                }
                // next button
                next.setFont(font);
                next.setString("Next");
                next.setOrigin(next.getLocalBounds().width / 2,
                               next.getLocalBounds().height / 2);
                next.setPosition(window->getSize().x -100.f,
                                 window->getSize().y -100.f);
                next.setCharacterSize(44);

                //retour Button
                retourn.setFont(font);
                retourn.setString("Retour");
                retourn.setOrigin(retourn.getLocalBounds().width / 2,
                                  retourn.getLocalBounds().height / 2);
                retourn.setPosition(100,
                                    window->getSize().y -100.f);
                retourn.setCharacterSize(44);
                //Change colour
                if(nextPressed)
                {
                    next.setFillColor(sf::Color::Red);
                    retourn.setFillColor(sf::Color::White);

                }
                else if (RetourPressed)
                {
                    next.setFillColor(sf::Color::White);
                    retourn.setFillColor(sf::Color::Red);
                }

                //Draw

                cout<<"drawing 4"<<endl;
                sf::Texture t;
                t.loadFromFile("textures/win.png");
                sf::Sprite s(t);
                s.setTexture(t);
                s.setOrigin(next.getLocalBounds().width / 2,
                            s.getLocalBounds().height / 2);
                s.setPosition(window->getSize().x/2-275, window->getSize().y/2-60);
                window->draw(s);
                window->draw(next);
                window->draw(retourn);
                window->display();



                //bracket of switch ending
            }
            break;

            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
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
