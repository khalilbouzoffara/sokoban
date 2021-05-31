#include "MainMenu.h"


#include <bits/stdc++.h>
#include <SFML/Window/Event.hpp>
#define HEIGHT 600
#define WIDTH 850

MainMenu::MainMenu() :
    m_isPlayButtonSelected(true),
    m_isPlayButtonPressed(false),
    m_isExitButtonSelected(false),
    m_isExitButtonPressed(false),
    m_isHelpButtonPressed(false),
    m_isHelpButtonSelected(false),
    m_isAboutButtonPressed(false),
    m_isAboutButtonSelected(false)
{



}

MainMenu::~MainMenu()
{

}
bool MainMenu::getABP()
{
    return m_isAboutButtonPressed;
}
bool MainMenu::getABS()
{
    return m_isAboutButtonSelected;
}
bool MainMenu::getPBP()
{
    return m_isPlayButtonPressed;
}
bool MainMenu::getPBS()
{
    return m_isPlayButtonSelected;
}
bool MainMenu::getEBP()
{
    return m_isExitButtonPressed;
}
bool MainMenu::getEBS()
{
    return m_isExitButtonSelected;
}
bool MainMenu::getHBP()
{
    return m_isHelpButtonPressed;
}
bool MainMenu::getHBS()
{
    return m_isHelpButtonSelected;
}
void MainMenu::setPBP(bool t)
{
    m_isPlayButtonPressed=t;
}
void MainMenu::setPBS(bool t)
{
    m_isPlayButtonSelected=t;
}
void MainMenu::setEBP(bool t)
{
    m_isExitButtonPressed=t;
}
void MainMenu::setEBS(bool t)
{
    m_isExitButtonSelected=t;
}
void MainMenu::setHBP(bool t)
{
    m_isHelpButtonPressed=t;
}
void MainMenu::setHBS(bool t)
{
    m_isHelpButtonSelected=t;
}
void MainMenu::setABP(bool t)
{
    m_isAboutButtonPressed=t;
}
void MainMenu::setABS(bool t)
{
    m_isAboutButtonSelected=t;
}
void MainMenu::Init(sf::RenderWindow &m_window)
{
    if (!font.loadFromFile("textures/Bokka Solid Regular.otf"))
    {
        std::cout<<"error" ;
    }
    //Title
    m_gameTitle.setFont(font);
    m_gameTitle.setString("SOKOBAN");
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
                          m_gameTitle.getLocalBounds().height / 2);
    m_gameTitle.setPosition(m_window.getSize().x / 2,
                            m_window.getSize().y / 2 - 230.f);
    m_gameTitle.setCharacterSize(80);


    // Play Button
    m_playButton.setFont(font);
    m_playButton.setString("Play");
    m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                           m_playButton.getLocalBounds().height / 2);
    m_playButton.setPosition(m_window.getSize().x / 2,
                             m_window.getSize().y / 2 - 100.f);
    m_playButton.setCharacterSize(44);

    //Help Button
    m_HelpButton.setFont(font);
    m_HelpButton.setString("Help");
    m_HelpButton.setOrigin(m_HelpButton.getLocalBounds().width / 2,
                           m_HelpButton.getLocalBounds().height / 2);
    m_HelpButton.setPosition(m_window.getSize().x / 2,
                             m_window.getSize().y / 2 + 0.f);
    m_HelpButton.setCharacterSize(44);


    //About Button
    m_AboutButton.setFont(font);
    m_AboutButton.setString("About");
    m_AboutButton.setOrigin(m_AboutButton.getLocalBounds().width / 2,
                           m_AboutButton.getLocalBounds().height / 2);
    m_AboutButton.setPosition(m_window.getSize().x / 2,
                             m_window.getSize().y / 2 + 80.f);
    m_AboutButton.setCharacterSize(40);

    // Exit Button
    m_exitButton.setFont(font);
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                           m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(m_window.getSize().x / 2,
                              m_window.getSize().y / 2 + 170.f);
    m_exitButton.setCharacterSize(44);
}


void MainMenu::keyPress(sf::RenderWindow &m_window)
{
    if(m_isPlayButtonPressed)
    {
        std::cout<<"play";
    }
    else if(m_isExitButtonPressed)
    {
        m_window.close();
    }
}


void MainMenu::Update(sf::RenderWindow &m_window)/*sf::Time deltaTime*/
{
    if(m_isPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Black);
        m_HelpButton.setFillColor(sf::Color::White);
        m_exitButton.setFillColor(sf::Color::White);
        m_AboutButton.setFillColor(sf::Color::White);
    }
    else if (m_isExitButtonSelected)
    {   m_HelpButton.setFillColor(sf::Color::White);
        m_exitButton.setFillColor(sf::Color::Black);
        m_playButton.setFillColor(sf::Color::White);
        m_AboutButton.setFillColor(sf::Color::White);
    }
    else if (m_isHelpButtonSelected){
        m_exitButton.setFillColor(sf::Color::White);
        m_playButton.setFillColor(sf::Color::White);
        m_HelpButton.setFillColor(sf::Color::Black);
        m_AboutButton.setFillColor(sf::Color::White);

    }
     else if (m_isAboutButtonSelected){

        m_exitButton.setFillColor(sf::Color::White);
        m_playButton.setFillColor(sf::Color::White);
        m_HelpButton.setFillColor(sf::Color::White);
        m_AboutButton.setFillColor(sf::Color::Black);


     }

    keyPress(m_window);
}

void MainMenu::Draw(sf::RenderWindow &m_window)

{
    Init(m_window);
    Update(m_window);
    sf::Vector2u TextureSize;  //Added to store texture size.
    sf::Vector2u WindowSize;   //Added to store window size.
    sf::Texture t;
    t.loadFromFile("textures/wood3.png");
    sf::Sprite s(t);
    TextureSize = t.getSize(); //Get size of texture.
    WindowSize = m_window.getSize();             //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    s.setTexture(t);
    s.setScale(ScaleX, ScaleY);      //Set scale
    m_window.clear(sf::Color::White);

    m_window.draw(s);

    m_window.draw(m_gameTitle);

     m_window.draw(m_HelpButton);

    m_window.draw(m_playButton);

    m_window.draw(m_HelpButton);

    m_window.draw(m_exitButton);

    m_window.draw(m_AboutButton);

    m_window.display();

}


