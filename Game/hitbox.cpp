#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

#include "Hitbox.h"

Hitbox::Hitbox(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height) : sprite(sprite), offsetX(offset_x), offsetY(offset_y)
{
	this->hitboxbound.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);
	this->hitboxbound.setSize(sf::Vector2f(width, height));
	this->hitboxbound.setFillColor(sf::Color::Transparent);
	this->hitboxbound.setOutlineThickness(1.f);
	this->hitboxbound.setOutlineColor(sf::Color::Green);
}

bool Hitbox::checkcollision(const sf::FloatRect& frect)
{
	return this->hitboxbound.getGlobalBounds().intersects(frect);
} 

void Hitbox::update()
{
	this->hitboxbound.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);
}

void Hitbox::render(sf::RenderTarget& target)
{
	target.draw(this->hitboxbound);
}