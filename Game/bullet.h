// Bullet.h

#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
private:
    sf::Sprite sprite;
    sf::Vector2f direction;
    float movementSpeed;
    sf::Vector2f startPosition;

public:
    Bullet();
    Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
    virtual ~Bullet();

    //access

    const sf::FloatRect getbound() const;
    const sf::Vector2f getPosition() const;

    void setStartPosition(const sf::Vector2f& position);

    // Method to get the starting position
    sf::Vector2f getStartPosition() const;

    void update();
    void render(sf::RenderTarget& target);
};