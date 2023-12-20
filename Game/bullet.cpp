#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

// Bullet.cpp
#include "Bullet.h"
#include "hitbox.h"




void Bullet::initTexture()
{
    if (!this->texturesheet.loadFromFile("Assets/sprite/HP.png"))
    {
        std::cout << "Error::bullet::image not load" << "\n";
    }
}

void Bullet::initsprite()
{
    this->sprite.setTexture(this->texturesheet);
    this->sprite.setScale(0.5f, 0.5f);
}

void Bullet::initHitbox()
{
    float offset_x = 30.0f;
    float offset_y = 28.0f;
    float width = 69.0f;
    float height = 150.0f;

    this->hitbox = new Hitbox(this->sprite, offset_x, offset_y, width, height);
}

Bullet::Bullet(sf::Vector2f position, sf::Vector2f dir, float speed)
    : direction(dir), movementSpeed(speed)
{
    this->sprite.setPosition(position);
    this->initTexture();
    this->initsprite();
    this->initHitbox();
}

Bullet::~Bullet()
{
    if (this->hitbox != nullptr)
    {
        delete this->hitbox;
        this->hitbox = nullptr; // Set to nullptr after deleting
    }
}

const sf::FloatRect Bullet::getGlobalBounds() const
{
    return this->sprite.getGlobalBounds();
}
const sf::FloatRect Bullet::getHitbox() const
{
    return this->hitbox->getGlobalBounds();
}

void Bullet::updateHitbox()
{
    this->hitbox->update();
}

void Bullet::update()
{
    this->sprite.move(this->direction * this->movementSpeed);
    this->updateHitbox();
}

void Bullet::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
        this->hitbox->render(target);
}

