#include <iostream>
#include "phonebook.h"
#include <SFML/Graphics.hpp>
#include "ImplemenationMenu.h"

int main() {
//    sf::RenderWindow window(sf::VideoMode(600, 600), "PhoneBook");
//    ImplementationMenu menu(window.getSize().x,window.getSize().y);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        menu.draw(window);
//        window.display();
//    }

    cout << "Starting..." << endl;
    phonebook _phonebook;
    _phonebook.start();
    return 0;
}
