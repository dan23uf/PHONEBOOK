#include <iostream>
#include "phonebook.h"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "PhoneBook");
    sf::Text implementationOptions;
    implementationOptions.setString("Choose implementation to use: ");
    implementationOptions.setCharacterSize(24);
    implementationOptions.setFillColor(sf::Color::Blue);
    implementationOptions.setStyle(sf::Text::Bold);
    implementationOptions.setPosition(10.f,50.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(implementationOptions);
        window.display();
    }

    cout << "Starting..." << endl;
    phonebook _phonebook;
    _phonebook.start();
    return 0;
}
