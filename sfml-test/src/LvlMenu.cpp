#include "LvlMenu.h"
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>


LvlMenu::LvlMenu()
{

    levelSelected[0]=true;
    levelPressed[0]=false;

    for(int i=1; i<10; i++)
    {
        levelPressed[i]=false;
        levelSelected[i]=false;

    }
    //ctor
}

LvlMenu::~LvlMenu()
{
    //dtor
}

void LvlMenu::setLvlS(int i,bool b)
{
    levelSelected[i]=b;
}

void LvlMenu::setLvlP(int i,bool b)
{
    levelPressed[i]=b;
}

bool LvlMenu::getLvlS(int i)
{
    return levelSelected[i];
}

bool LvlMenu::getLvlP(int i)
{
    return levelPressed[i];
}

void LvlMenu::Remplir(sf::RenderWindow &win)
{

    if (!font.loadFromFile("textures/Pacifico-Regular .ttf"))
    {
        std::cout<<"error" ;
    }


    for(int j=0,k=0,p=1,i=0 ; i<10 ; i++)
    {

        std::string s;
        s=""+std::to_string(i+1);

        niveau[i].setFont(font);
        niveau[i].setString(s);
        niveau[i].setOrigin( niveau[i].getLocalBounds().width / 2, niveau[i].getLocalBounds().height / 2);
        niveau[i].setPosition(win.getSize().x / 5 + j +40.f, win.getSize().y / 3*p -15.f);
        niveau[i].setCharacterSize(44);
        j+=140;


        if (i==4)
        {
            p=2;
            j=0;

        }

    }
}

void LvlMenu::ChangeLevelColor(sf::RenderWindow &win)
{
    Remplir(win);
    int k=-1;
    for(int i=0; i<10; i++)
    {
        if (levelSelected[i])
        {
            k=i;
        }

    }
    if(k>0)
    {
        niveau[k-1].setFillColor(sf::Color::White);
        niveau[k].setFillColor(sf::Color::Red);
    }
    else
    {
        niveau[9].setFillColor(sf::Color::White);
        niveau[0].setFillColor(sf::Color::Red);
    }
    k=-1;
}



void LvlMenu::DrawIT(sf::RenderWindow &win)
{
    ChangeLevelColor(win);
    sf::Vector2u TextureSize;  //Added to store texture size.
    sf::Vector2u WindowSize;   //Added to store window size.
    sf::Texture t;
    t.loadFromFile("textures/menu2test.png");
    sf::Sprite s(t);
    TextureSize = t.getSize(); //Get size of texture.
    WindowSize = win.getSize();             //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    s.setTexture(t);
    s.setScale(ScaleX, ScaleY);      //Set scale
    win.clear();
    win.draw(s);
    for ( int i=0 ; i<10 ; i++)
    {

        win.draw(niveau[i]);

    }
    win.display();




}
