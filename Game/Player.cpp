#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

#include "player.h"

void Player::initTexture()
{
	if (!this->texturesheet.loadFromFile("../Assets/ded.jpg"))
	{
		std::cout << "Error::player::image not load" << "\n";
	}

}

void Player::initSprite()
{
	this->sprite.setTexture(this->texturesheet);
	this->currentFrame = sf::IntRect(0, 0, 64, 64);
	this->sprite.setTextureRect(this->currentFrame);
}

void Player::initphysics()
{
	
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.0f;
	this->drag = 0.80f;
	this->gravity = 4.f;
	this->velocityMaxY = 15.f;
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
	this->initphysics();
}

Player::~Player()
{


}

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);

}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;

}

void Player::move(const float dir_x, const float dir_y)
{
	//acceleration
	this->velocity.x += dir_x * this->acceleration;


	//limite velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//gavity
	this->velocity.y += 1.0 *this->gravity;

	//deceleration
	this->velocity *= this->drag;


	//limite deceleration
	if (this->velocity.x < this->velocityMin)
		this->velocity.x = 0.f;

	if (this->velocity.y < this->velocityMin)
		this->velocity.y = 0.f;

	if (std::abs(this->velocity.x) <= 1.f)
		this->velocity.x = 0.f;

	this->sprite.move(this->velocity);
}

void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //droite
	{
		this->move(1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) //gauche
	{
		this->move(-1.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) //haut
	{
		this->move(0.f, -1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //bas
	{
		this->move(0.f, 1.f);
	}
}

void Player::update()
{

	this->updateMovement();
	this->updatePhysics();

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

}
