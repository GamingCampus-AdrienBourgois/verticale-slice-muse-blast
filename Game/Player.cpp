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
#include "Hitbox.h"

//bite

void Player::initAnimation()
{
	
	this->animationtimer.restart();
	this->animationswitch = true;
}

void Player::initVariables()
{
	//this->hitbox = NULL;
	this->animationState = IDLE;
}

void Player::initTexture()
{
	if (!this->texturesheet.loadFromFile("../Assets/joueur.png"))
	{
		std::cout << "Error::player::image not load" << "\n";
	}

}

void Player::initSprite()
{
	this->sprite.setTexture(this->texturesheet);
	this->currentFrame = sf::IntRect(0, 0, 69, 44);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.5f, 2.5f);
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

void Player::initHitbox()
{
	this->createhitbox(this->sprite, 0.f, 0.f, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

}

Player::Player()
{
	
	this->initVariables();
	this->initAnimation();
	this->initTexture();
	this->initSprite();
	this->initphysics();
	this->initHitbox();
}

Player::~Player()
{
}

const bool& Player::getAnimationSwitch()
{
	bool anim_switch = this->animationswitch;

	if (this->animationswitch)
		this->animationswitch = false;
	
	return anim_switch;
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

void Player::createhitbox(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height)
{
	this->hitbox = new Hitbox(sprite, offset_x, offset_y, width, height);
}

void Player::resetAnimationTimer()
{
	this->animationtimer.restart();
	this->animationswitch = true;
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

void Player::jump(const float dir_x, const float dir_y)
{

}

void Player::updatePhysics()
{
	//gavity
	//this->velocity.y += 1.0 *this->gravity;

	//deceleration
	this->velocity *= this->drag;


	//limite deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;

	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
}

void Player::updateHitbox()
{
	this->hitbox->update();
}

void Player::updateMovement()
{
	this->animationState = IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //droite
	{
		this->move(1.f, 0.f);
		this->animationState = MOVING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) //gauche
	{
		this->move(-1.f, 0.f);
		this->animationState = MOVING_LEFT;
	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) //haut
	{


		this->animationState = JUMPING;



		
	}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //bas
	//{
	//	this->move(0.f, 1.f);
	//}

}

void Player::updateAnimation()
{
	if (this->animationState == IDLE)
	{
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.15f || this->getAnimationSwitch())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 69.f;
			if (this->currentFrame.left >= 414.f)
				this->currentFrame.left = 0;


			this->animationtimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

	}
	else if (this->animationState == MOVING_RIGHT)
	{
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.15f || this->getAnimationSwitch())
		{
			this->currentFrame.top = 44.f;
			this->currentFrame.left += 69.f;
			if (this->currentFrame.left >= 414.f)
				this->currentFrame.left = 0;


			this->animationtimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
			
		}
			this->sprite.setScale(2.5f, 2.5f);
			this->sprite.setOrigin(0.f, 0.f);
	}

	else if (this->animationState == MOVING_LEFT)
	{
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.15f || this->getAnimationSwitch())
		{
			this->currentFrame.top = 44.f;
			this->currentFrame.left += 69.f;
			if (this->currentFrame.left >= 414.f)
				this->currentFrame.left = 0;


			this->animationtimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
			
		}
		this->sprite.setScale(-2.5f, 2.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	}
}


void Player::update()
{
	this->updateAnimation();
	this->updateMovement();
	this->updatePhysics();
	this->updateHitbox();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
