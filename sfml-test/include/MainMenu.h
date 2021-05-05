#ifndef MAINMENU_H
#define MAINMENU_H

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class MainMenu {
private:

    //sf::Text m_gameTitle;
    sf::Text m_playButton;
    sf::Text m_exitButton;
    sf::RenderWindow *m_window ;
    sf::Font font ;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;

    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

public:
     MainMenu();
    ~MainMenu();

    void Init() ;
    void ProcessInput() ;
    void Update() ;
    void Draw() ;
    void MenuLoop();
};
#endif // MAINMENU_H
