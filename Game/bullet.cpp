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

Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->sprite.setTexture(*texture);

	this->sprite.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;

}

Bullet::~Bullet()
{


}

const sf::FloatRect Bullet::getbound() const
{
	return this->sprite.getGlobalBounds();
}

void Bullet::update()
{
	//movement
	this->sprite.move(this->movementSpeed * this->direction);

}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

}
