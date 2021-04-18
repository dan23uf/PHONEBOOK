//
// Created by claud on 4/17/2021.
//
#include "ImplemenationMenu.h"

ImplementationMenu::ImplementationMenu(float width, float height) {
    if (!font.loadFromFile("../arial.ttf"))
    {
        //handle error
    }

    text[0].setFont(font);
    text[0].setCharacterSize(24);
    text[0].setColor(sf::Color::Blue);
    text[0].setString("Vector");
    text[0].setPosition(sf::Vector2f(width/(MAX_NUMBER_OF_ITEMS+1)*1,height/2));

    text[1].setFont(font);
    text[1].setCharacterSize(24);
    text[1].setColor(sf::Color::White);
    text[1].setString("BST");
    text[1].setPosition(sf::Vector2f(width/(MAX_NUMBER_OF_ITEMS+1)*2,height/2));

    text[2].setFont(font);
    text[2].setCharacterSize(24);
    text[2].setColor(sf::Color::White);
    text[2].setString("HEAP");
    text[2].setPosition(sf::Vector2f(width/(MAX_NUMBER_OF_ITEMS+1)*3,height/2));

    selectedItemIndex = 0;
}

ImplementationMenu::~ImplementationMenu() {

}

void ImplementationMenu::draw(sf::RenderWindow &window) {
    for(int i = 0; i< MAX_NUMBER_OF_ITEMS; i++){
        window.draw(text[i]);
    }
}

void ImplementationMenu::moveUp() {
    if(selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::Blue);
    }
}