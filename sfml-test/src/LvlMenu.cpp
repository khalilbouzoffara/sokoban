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
        niveau[i].setPosition(win.getSize().x / 5 + j +30.f, win.getSize().y / 3*p -15.f);
        niveau[i].setCharacterSize(44);
        j+=120;


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
         niveau[k].setFillColor(sf::Color::Black);
         for (int i=0;i<10;i++)
         {
             if (i!=k ) { niveau[i].setFillColor(sf::Color::White);}
         }
    k=-1;
}



void LvlMenu::DrawIT(sf::RenderWindow &win)
{
    ChangeLevelColor(win);
    sf::Vector2u TextureSize;  //Added to store texture size.
    sf::Vector2u WindowSize;   //Added to store window size.
    sf::Texture t;
    t.loadFromFile("textures/menu222.png");
    sf::Sprite s(t);

    sf::Text txt;
    sf::Text esp;


    sf::Font font ;
    if (!font.loadFromFile("textures/Bokka Solid Regular.otf"))
    {
        std::cout<<"error" ;
    }
    txt.setFont(font);
    txt.setString("LEVELS");
    txt.setOrigin(txt.getLocalBounds().width / 2,
                          txt.getLocalBounds().height / 2);
    txt.setPosition(win.getSize().x / 2-67,
                            win.getSize().y / 2 - 250.f);
    txt.setCharacterSize(70);

    esp.setFont(font);
    esp.setString("Esc");
    esp.setOrigin(esp.getLocalBounds().width / 2,esp.getLocalBounds().height / 2);
    esp.setPosition(win.getSize().x / 2 +00.f,win.getSize().y / 2 + 205.f);
    esp.setCharacterSize(35);


    TextureSize = t.getSize(); //Get size of texture.
    WindowSize = win.getSize();             //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    s.setTexture(t);
    s.setScale(ScaleX, ScaleY);      //Set scale
    win.clear(sf::Color::White);
    win.draw(s);
    win.draw(txt);
    win.draw(esp);

    for ( int i=0 ; i<10 ; i++)
    {

        win.draw(niveau[i]);

    }
    win.display();




}
