#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>

class Hitbox
{
private:
    sf::Sprite& sprite;
    sf::RectangleShape hitbox;
    float offsetX;
    float offsetY;

public:
    Hitbox(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
    virtual ~Hitbox();

    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f& getPosition() const;

    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);

    void update();
    void render(sf::RenderTarget& target);
};

#endif // !HITBOX_H