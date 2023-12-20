// Bullet.h

#pragma once
#include <SFML/Graphics.hpp>
#include"hitbox.h"
class Bullet
{
private:
    sf::Sprite sprite;
    sf::Texture texturesheet;
    sf::Vector2f direction;
    float movementSpeed;

    void initTexture();
    void initsprite();
public:
    Bullet(sf::Vector2f position, sf::Vector2f dir, float speed);
    virtual ~Bullet();

    const sf::FloatRect getGlobalBounds() const;

    void updateHitbox();
    void update();
    void render(sf::RenderTarget& target);
};