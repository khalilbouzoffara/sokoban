#include "Help.h"
#include <bits/stdc++.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#define HEIGHT 600
#define WIDTH 850
Help::Help()
{
    //ctor
}

void Help::initHelp(sf::RenderWindow &win)
{
    if (!font.loadFromFile("textures/Pacifico-Regular .ttf"))
    {
        std::cout<<"error" ;
    }
}

void Help::drawHelp(sf::RenderWindow &win,int n)
{
    switch (n)
    {
    case 0:
    {
        sf::Vector2u TextureSize;  //Added to store texture size.
        sf::Vector2u WindowSize; //Added to store window size.
        sf::Text BUTTONRETOUR ;
        if (!font.loadFromFile("textures/Bokka Solid Regular.otf"))
        {
            std::cout<<"error" ;
        }


        //TASWIRIT BOX
        sf::Texture t ;



        sf::Texture BG;
        BG.loadFromFile("textures/help22.png");
        sf::Sprite spriteBG(BG);


        //BUTOON RETOUR
        BUTTONRETOUR.setFont(font);
        BUTTONRETOUR.setString("Esc");
        BUTTONRETOUR.setOrigin(BUTTONRETOUR.getLocalBounds().width / 2 -15.f,BUTTONRETOUR.getLocalBounds().height / 2 +30.f);
        BUTTONRETOUR.setPosition(win.getSize().x/2,win.getSize().y-40 );
        BUTTONRETOUR.setCharacterSize(30);
        BUTTONRETOUR.setColor(sf::Color::White);



        TextureSize = BG.getSize(); //Get size of BG texture.
        WindowSize = win.getSize();    //Get size of window.

        float ScaleX = (float) WindowSize.x / TextureSize.x;
        float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

        spriteBG.setTexture(BG);


        spriteBG.setScale(ScaleX, ScaleY);      //Set scale


        win.clear(sf::Color::White);


        win.draw(spriteBG);
        win.draw(BUTTONRETOUR);


        win.display();
    }

    break;

    case 1: //rules
        sf::Vector2u TextureSize2;  //Added to store texture size.
        sf::Vector2u WindowSize2; //Added to store window size.
        sf::Text BUTTONRETOUR2 ;
        sf::Text BUTTONRETOUR3 ;
        sf::Text NEXT2 ;
        sf::Text R ;
        sf::Text N ;

        if (!font.loadFromFile("textures/Bokka Solid Regular.otf"))
        {
            std::cout<<"error" ;
        }


        //TASWIRIT BOX
        sf::Texture t ;
        sf::Texture BG2;
        BG2.loadFromFile("textures/wood5.png");
        sf::Sprite spriteBG2(BG2);
        //RETOUR BUTTON
        BUTTONRETOUR2.setFont(font);
        BUTTONRETOUR2.setString("Esc");
        BUTTONRETOUR2.setOrigin(BUTTONRETOUR2.getLocalBounds().width / 2 +70.f,BUTTONRETOUR2.getLocalBounds().height / 2 +60.f);
        BUTTONRETOUR2.setPosition(win.getSize().x/2,win.getSize().y-40 );
        BUTTONRETOUR2.setCharacterSize(30);
        BUTTONRETOUR2.setColor(sf::Color::White);
        //RETOUR BUTTON
        BUTTONRETOUR3.setFont(font);
        BUTTONRETOUR3.setString("Esc");
        BUTTONRETOUR3.setOrigin(R.getLocalBounds().width / 2 +270.f,R.getLocalBounds().height / 2 +150.f);
        BUTTONRETOUR3.setPosition(win.getSize().x/2,win.getSize().y-40 );
        BUTTONRETOUR3.setCharacterSize(40);
        BUTTONRETOUR3.setColor(sf::Color::White);
        //NEXT BUTTON
        NEXT2.setFont(font);
        NEXT2.setString("Next");
        NEXT2.setOrigin(BUTTONRETOUR2.getLocalBounds().width / 2 -70.f,BUTTONRETOUR2.getLocalBounds().height / 2 +60.f);
        NEXT2.setPosition(win.getSize().x/2,win.getSize().y-40 );
        NEXT2.setCharacterSize(30);
        NEXT2.setColor(sf::Color::White);
        //REPLAY BUTTON
        R.setFont(font);
        R.setString("R");
        R.setOrigin(BUTTONRETOUR2.getLocalBounds().width / 2 +220.f,BUTTONRETOUR2.getLocalBounds().height / 2 +230.f);
        R.setPosition(win.getSize().x/2,win.getSize().y-40 );
        R.setCharacterSize(40);
        R.setColor(sf::Color::White);
        //N BUTTON
        N.setFont(font);
        N.setString("N");
        N.setOrigin(R.getLocalBounds().width / 2 -60.f,R.getLocalBounds().height / 2 +230.f);
        N.setPosition(win.getSize().x/2,win.getSize().y-40 );
        N.setCharacterSize(40);
        N.setColor(sf::Color::White);

        TextureSize2 = BG2.getSize(); //Get size of BG texture.
        WindowSize2 = win.getSize();    //Get size of window.

        float ScaleX = (float) WindowSize2.x / TextureSize2.x;
        float ScaleY = (float) WindowSize2.y / TextureSize2.y;     //Calculate scale.

        spriteBG2.setTexture(BG2);


        spriteBG2.setScale(ScaleX, ScaleY);      //Set scale


        win.clear(sf::Color::White);


        win.draw(spriteBG2);
        win.draw(BUTTONRETOUR2);
        win.draw(BUTTONRETOUR3);
        win.draw(NEXT2);
        win.draw(R);
        win.draw(N);


        win.display();


        break;


    }


}



Help::~Help()
{
    //dtor
}
