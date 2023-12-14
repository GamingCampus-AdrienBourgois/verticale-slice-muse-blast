#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture& texture, float dir_X, float dir_Y, float movement_speed)
{
	this->shape.setTexture(texture);
	this->direction.x = dir_X;
	this->direction.y = dir_Y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{


}

void Bullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);

}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
