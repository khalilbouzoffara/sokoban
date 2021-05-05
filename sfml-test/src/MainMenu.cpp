#include "MainMenu.h"


#include <bits/stdc++.h>
#include <SFML/Window/Event.hpp>
#define HEIGHT 600
#define WIDTH 850

MainMenu::MainMenu() :
    m_isPlayButtonSelected(true),
    m_isPlayButtonPressed(false),
    m_isExitButtonSelected(false),
    m_isExitButtonPressed(false)
{





}

MainMenu::~MainMenu()
{

}

bool MainMenu::getPBP()
{
    return m_isPlayButtonSelected;
}
bool MainMenu::getPBS()
{
    return m_isPlayButtonPressed;
}
bool MainMenu::getEBP()
{
    return m_isExitButtonSelected;
}
bool MainMenu::getEBS()
{
    return m_isExitButtonSelected;
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
void MainMenu::Init(sf::RenderWindow &m_window)
{
    if (!font.loadFromFile("textures/Pacifico-Regular .ttf"))
    {
        std::cout<<"error" ;
    }
    /* Title
    m_gameTitle.setFont(font);
    m_gameTitle.setString("Sokoban Game");
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
                          m_gameTitle.getLocalBounds().height / 2);
    m_gameTitle.setPosition(m_window->getSize().x / 2,
                            m_window->getSize().y / 2 - 150.f);*/

    // Play Button
    m_playButton.setFont(font);
    m_playButton.setString("Play");
    m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                           m_playButton.getLocalBounds().height / 2);
    m_playButton.setPosition(m_window.getSize().x / 2,
                             m_window.getSize().y / 2 - 50.f);
    m_playButton.setCharacterSize(44);

    // Exit Button
    m_exitButton.setFont(font);
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                           m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(m_window.getSize().x / 2,
                             m_window.getSize().y / 2 + 30.f);
    m_exitButton.setCharacterSize(44);
}

void MainMenu::ProcessInput(sf::RenderWindow &m_window)
{

    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
            {
                if (!m_isPlayButtonSelected)
                {
                    m_isPlayButtonSelected = true;
                    m_isExitButtonSelected = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (!m_isExitButtonSelected)
                {
                    m_isPlayButtonSelected = false;
                    m_isExitButtonSelected = true;
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                m_isPlayButtonPressed = false;
                m_isExitButtonPressed = false;

                if (m_isPlayButtonSelected)
                {
                    m_isPlayButtonPressed = true;
                }
                else
                {
                    m_isExitButtonPressed = true;
                }

                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
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
        m_exitButton.setFillColor(sf::Color::White);
    }
    else
    {
        m_exitButton.setFillColor(sf::Color::Black);
        m_playButton.setFillColor(sf::Color::White);
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
    t.loadFromFile("textures/bgg.jpg");
    sf::Sprite s(t);
    TextureSize = t.getSize(); //Get size of texture.
    WindowSize = m_window.getSize();             //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    s.setTexture(t);
    s.setScale(ScaleX, ScaleY);      //Set scale
    m_window.clear(sf::Color::White);
    m_window.draw(s);
    //m_window->draw(m_gameTitle);
    m_window.draw(m_playButton);
    m_window.draw(m_exitButton);
    m_window.display();
}


void MainMenu::MenuLoop(sf::RenderWindow &m_window)
{
    while (m_window.isOpen())
    {
        Init(m_window);
        //ProcessInput(m_window);
        Update(m_window);
        Draw(m_window);
    }
}
