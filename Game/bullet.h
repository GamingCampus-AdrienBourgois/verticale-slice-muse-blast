// Bullet.h

#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::CircleShape shape;
    sf::Vector2f direction;
    float movementSpeed;

public:
    Bullet(sf::Vector2f position, sf::Vector2f dir, float speed);
    virtual ~Bullet();

    void update();
    void render(sf::RenderTarget& target);
    const sf::FloatRect getGlobalBounds() const;
};