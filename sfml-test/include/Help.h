#ifndef HELP_H
#define HELP_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

class Help
{
public:
    Help();
    void initHelp(sf::RenderWindow &);
    void drawHelp(sf::RenderWindow &,int);
    virtual ~Help();


private:
    sf::Font font ;
};

#endif // HELP_H
