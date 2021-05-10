#ifndef LVLMENU_H
#define LVLMENU_H
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>


class LvlMenu
{
public:
    LvlMenu();
    void setLvlS(int,bool);
    void setLvlP(int,bool);
    bool getLvlS(int);
    bool getLvlP(int);
    void Remplir(sf::RenderWindow &);
    void ChangeLevelColor(sf::RenderWindow &);
    void DrawIT(sf::RenderWindow &);
    virtual ~LvlMenu();



private:
    sf::Text niveau[10];
    sf::RenderWindow *win ;
    sf::Font font ;

    bool levelSelected[10];
    bool levelPressed[10];


};

#endif // LVLMENU_H
