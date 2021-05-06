#ifndef MAINMENU_H
#define MAINMENU_H

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class MainMenu {
public:

    //sf::Text m_gameTitle;
    sf::Text m_playButton;
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
    bool getEBS();
    bool getEBP();
    //setters
    void setPBS(bool);
    void setPBP(bool);
    void setEBS(bool);
    void setEBP(bool);


    void keyPress(sf::RenderWindow &);
    void Init(sf::RenderWindow &) ;
    void ProcessInput(sf::RenderWindow &) ;
    void Update(sf::RenderWindow &) ;
    void Draw(sf::RenderWindow &) ;
    void MenuLoop(sf::RenderWindow &);
};
#endif // MAINMENU_H
