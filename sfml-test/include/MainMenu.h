#ifndef MAINMENU_H
#define MAINMENU_H

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class MainMenu
{
private:

    //sf::Text m_gameTitle;
    sf::Text m_playButton;
    sf::Text m_HelpButton;
    sf::Text m_exitButton;
    sf::RenderWindow *m_window ;
    sf::Font font ;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;

    bool m_isHelpButtonSelected;
    bool m_isHelpButtonPressed;

    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

public:
    MainMenu();
    ~MainMenu();
    //getters
    bool getPBS();
    bool getPBP();
    bool getHBP();
    bool getHBS();
    bool getEBS();
    bool getEBP();
    //setters
    void setPBS(bool);
    void setPBP(bool);
    void setHBP(bool);
    void setHBS(bool);
    void setEBS(bool);
    void setEBP(bool);


    void keyPress(sf::RenderWindow &);
    void Init(sf::RenderWindow &) ;
    void ProcessInput(sf::RenderWindow &) ;
    void Update(sf::RenderWindow &) ;
    void Draw(sf::RenderWindow &) ;
};
#endif // MAINMENU_H
