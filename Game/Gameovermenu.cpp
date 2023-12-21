#include "Gameovermenu.h"

GameOver::GameOver() {
    if (!font.loadFromFile("Assets/font/game_over.ttf")) {
    }

    if (!backgroundTexture.loadFromFile("Assets/sprite/gameoverbg.png")) {
    }

    backgroundSprite.setTexture(backgroundTexture);

    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(300);
    gameOverText.setFillColor(gameOverColor);
    gameOverText.setStyle(sf::Text::Bold);

    playAgainText.setFont(font);
    playAgainText.setString("Play Again ?");
    playAgainText.setCharacterSize(200);
    playAgainText.setFillColor(playAgainColor);
    playAgainText.setStyle(sf::Text::Bold);

    sf::FloatRect gameOverRect = gameOverText.getLocalBounds();
    gameOverText.setPosition(sf::Vector2f(1700 / 2 - gameOverRect.width / 2, 600 / 5 - gameOverRect.height / 0.4));

    sf::FloatRect playAgainRect = playAgainText.getLocalBounds();
    playAgainText.setPosition(sf::Vector2f(1700 / 2 - playAgainRect.width / 2, 600 / 4 - playAgainRect.height / 1.4));

    isMouseOverYes = false;
    isMouseOverNo = false;

    yesText.setFont(font);
    yesText.setString("YES");
    yesText.setCharacterSize(150);
    yesText.setFillColor(yesnoColorFalse);
    yesText.setStyle(sf::Text::Bold);

    noText.setFont(font);
    noText.setString("NO");
    noText.setCharacterSize(150);
    noText.setFillColor(yesnoColorFalse);
    noText.setStyle(sf::Text::Bold);

    sf::FloatRect yesRect = yesText.getLocalBounds();
    yesText.setPosition(sf::Vector2f(1700 / 2 - yesRect.width / 2 - 100, 600 / 2 - yesRect.height / 2));

    sf::FloatRect noRect = noText.getLocalBounds();
    noText.setPosition(sf::Vector2f(1700 / 2 - noRect.width / 2 + 100, 600 / 2 - noRect.height / 2));
}



void GameOver::render(sf::RenderWindow& window) {

    window.draw(backgroundSprite);
    window.draw(gameOverText);
    window.draw(playAgainText);

    if (yesText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        yesText.setFillColor(yesnoColorTrue);
        yesText.setCharacterSize(160);
        isMouseOverYes = true;
    }
    else {
        yesText.setCharacterSize(150);
        isMouseOverYes = false;
    }


    if (noText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        noText.setFillColor(yesnoColorTrue);
        noText.setCharacterSize(160);
        isMouseOverNo = true;
    }
    else {
        noText.setCharacterSize(150);
        isMouseOverNo = false;
    }

    if (isMouseOverYes) {
        window.draw(yesText);
    }
    else {
        window.draw(yesText);
    }

    if (isMouseOverNo) {
        window.draw(noText);
    }
    else {
        window.draw(noText);
    }
}