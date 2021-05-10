#ifndef HELP_H
#define HELP_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

class Help
{
public:
    Help();
    void initHelp(sf::RenderWindow &);
    void drawHelp(sf::RenderWindow &);
    void loop(sf::RenderWindow &);
    virtual ~Help();


private:
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    sf::Font font ;
};

#endif // HELP_H
