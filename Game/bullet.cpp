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

Bullet::Bullet(sf::Vector2f position, sf::Vector2f dir, float speed)
    : direction(dir), movementSpeed(speed)
{
    this->shape.setPosition(position);
    this->shape.setRadius(5.f);
    this->shape.setFillColor(sf::Color::Black);
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getGlobalBounds() const
{
    return this->shape.getGlobalBounds();
}

void Bullet::update()
{
    this->shape.move(this->direction * this->movementSpeed);
}

void Bullet::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}

