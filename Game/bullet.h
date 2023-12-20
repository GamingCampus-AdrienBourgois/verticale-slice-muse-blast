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

    Hitbox* hitbox;
    void initTexture();
    void initsprite();
    void initHitbox();

public:
    Bullet(sf::Vector2f position, sf::Vector2f dir, float speed);
    virtual ~Bullet();

    const sf::FloatRect getHitbox() const;
    const sf::FloatRect getGlobalBounds() const;

    void updateHitbox();
    void update();
    void render(sf::RenderTarget& target);
};