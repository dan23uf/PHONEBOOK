//
// Created by claud on 4/17/2021.
//
#pragma once
#include "SFML/Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 3

class ImplementationMenu
{
public:
    ImplementationMenu(float width, float height);
    ~ImplementationMenu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS];

};

