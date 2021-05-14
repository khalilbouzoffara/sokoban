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

    //text1
    text1.setFont(font);
    text1.setString("Vous pouvez deplacer un baggage");
    text1.setOrigin(text1.getLocalBounds().width / 2,text1.getLocalBounds().height / 2);
    text1.setPosition(win.getSize().x / 2, win.getSize().y / 2 - 220.f);
    text1.setCharacterSize(44);

    //text2
    text2.setFont(font);
    text2.setString("Vous pouvez pousser qu'un seule baggage");
    text2.setOrigin(text2.getLocalBounds().width / 2,text2.getLocalBounds().height / 2);
    text2.setPosition(win.getSize().x / 2, win.getSize().y / 2 +00.f);
    text2.setCharacterSize(44);

    //text3
    text3.setFont(font);
    text3.setString("Vous ne pouvez pas tirer vos baggage");
    text3.setOrigin(text3.getLocalBounds().width / 2,text3.getLocalBounds().height / 2);
    text3.setPosition(win.getSize().x / 2, win.getSize().y / 2 +220.f);
    text3.setCharacterSize(44);
}

void Help::drawHelp(sf::RenderWindow &win)
{
   // initHelp(win);
    sf::Vector2u TextureSize;  //Added to store texture size.
    sf::Vector2u WindowSize;   //Added to store window size.

    sf::Texture BG;
    sf::Texture rule1;
    sf::Texture rule2;
    sf::Texture rule3;


    //BG.loadFromFile("textures/bgg.jpg");
    rule1.loadFromFile("textures/rules/rule01.gif");
    rule2.loadFromFile("textures/rules/rule02.gif");
    rule3.loadFromFile("textures/rules/rule03.gif");
    BG.loadFromFile("textures/rules/i01_Help.jpg");

    sf::Sprite spriteBG(BG);
    sf::Sprite spriteRule1(rule1);
    sf::Sprite spriteRule2(rule2);
    sf::Sprite spriteRule3(rule3);


    TextureSize = BG.getSize(); //Get size of BG texture.
    WindowSize = win.getSize();    //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    spriteBG.setTexture(BG);
    spriteRule1.setTexture(rule1);
    spriteRule2.setTexture(rule2);
    spriteRule3.setTexture(rule3);

    spriteBG.setScale(ScaleX, ScaleY);      //Set scale
    spriteRule1.setScale(ScaleX/5, ScaleY/5);
    spriteRule1.setPosition(win.getSize().x / 2 -160.f, win.getSize().y / 2 - 170.f);
    spriteRule2.setScale(ScaleX/5, ScaleY/5);
    spriteRule2.setPosition(win.getSize().x / 2 -160.f, win.getSize().y / 2 + 50.f);
    spriteRule3.setScale(ScaleX/5, ScaleY/5);
    spriteRule3.setPosition(win.getSize().x / 2 -160.f, win.getSize().y / 2 + 250.f);


    win.clear(sf::Color::White);
    win.draw(spriteBG);
//    win.draw(spriteRule1);
//    win.draw(spriteRule2);
//    win.draw(spriteRule3);
//    win.draw(text1);
//    win.draw(text2);
//    win.draw(text3);
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
