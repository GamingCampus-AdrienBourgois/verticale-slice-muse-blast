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

Bullet::Bullet(sf::Vector2f position, sf::Vector2f dir, float speed)
    : direction(dir), movementSpeed(speed)
{
    this->sprite.setPosition(position);
    this->initTexture();
    this->initsprite();
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getGlobalBounds() const
{
    return this->sprite.getGlobalBounds();
}

void Bullet::update()
{
    this->sprite.move(this->direction * this->movementSpeed);
}

void Bullet::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

