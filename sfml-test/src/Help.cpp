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

void Help::drawHelp(sf::RenderWindow &win)
{
   // initHelp(win);
    sf::Vector2u TextureSize;  //Added to store texture size.
    sf::Vector2u WindowSize; //Added to store window size.
    sf::Text BUTTONRETOUR ;
    if (!font.loadFromFile("textures/Bokka Solid Regular.otf"))
                {
                    std::cout<<"error" ;
                }


    //TASWIRIT BOX
    sf::Texture t ;

   /*Exit twali 7amra w tetkhdm mbaid  matitbadel BG
    t.loadFromFile("textures/exit.png");
    sf::Sprite s;
    s.setTexture(t);
    s.setPosition(-30,-30);*/



    sf::Texture BG;
    BG.loadFromFile("textures/rules/i01_Help.jpg");
    sf::Sprite spriteBG(BG);


    //BUTOON RETOUR
    BUTTONRETOUR.setFont(font);
    BUTTONRETOUR.setString("Retour");
    BUTTONRETOUR.setOrigin(BUTTONRETOUR.getLocalBounds().width / 2,
                               BUTTONRETOUR.getLocalBounds().height / 2);
    BUTTONRETOUR.setPosition(win.getSize().x/2 ,
                                 win.getSize().y-40 );
    BUTTONRETOUR.setCharacterSize(30);
    BUTTONRETOUR.setColor(sf::Color::Green);



    TextureSize = BG.getSize(); //Get size of BG texture.
    WindowSize = win.getSize();    //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    spriteBG.setTexture(BG);


    spriteBG.setScale(ScaleX, ScaleY);      //Set scale


    win.clear(sf::Color::White);


    win.draw(spriteBG);
    //win.draw(s);
    win.draw(BUTTONRETOUR);


    win.display();


}

void Help::loop(sf::RenderWindow &win)
{
while (win.isOpen())
{
    drawHelp(win);
}
}


Help::~Help()
{
    //dtor
}
