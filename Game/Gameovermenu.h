#pragma once
#include <SFML/Graphics.hpp>

class GameOver {
public:
    GameOver();
    void render(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text gameOverText;
    sf::Text playAgainText;
    sf::Text yesText;
    sf::Text noText;

    sf::Color gameOverColor = sf::Color(174, 41, 189);
    sf::Color playAgainColor = sf::Color(218, 64, 129);
    sf::Color yesnoColorFalse = sf::Color(50, 153, 197);
    sf::Color yesnoColorTrue = sf::Color(104, 175, 205);

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    bool isMouseOverYes;
    bool isMouseOverNo;
};

