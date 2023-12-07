// Menu.h
#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();
    ~Menu();  // Ajoutez la d�claration du destructeur

    void Show(sf::RenderWindow& window);

private:
    sf::RectangleShape playButton;
    sf::RectangleShape optionsButton;
    sf::RectangleShape quitButton;
    sf::Font font;
    sf::Text playText;
    sf::Text optionsText;
    sf::Text quitText;
    sf::Texture backgroundTexture;
    sf::Text titleText;

    void HandleEvents(sf::Event& event, sf::RenderWindow& window);
};