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
#include"bullet.h"
#include "game.h"


void Player::initAnimation()
{
	
	this->animationtimer.restart();
	this->animationswitch = true;
}

void Player::initVariables()
{
	//this->hitbox = NULL;
	this->animationState = IDLE;

	//vie
	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	if (!this->texturesheet.loadFromFile("Assets/sprite/SpriteTestRock.png"))
	{
		std::cout << "Error::player::image not load" << "\n";
	}

}

void Player::initSprite()
{
	this->sprite.setTexture(this->texturesheet);
	this->currentFrame = sf::IntRect(0, 0, 44, 68);
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
	this->velocityY = 0.f;
	this->velocityMaxY = 15.f;
	this->jumpHeight = 15.f;

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
	return this->hitbox->getGlobalBounds();
}

const sf::FloatRect Player::getHitbox() const
{
	return this->hitbox->getGlobalBounds();
}

const sf::Vector2f Player::getPlayerCenter() const
{
	return sf::Vector2f(
		this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f,
		this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f
	);
}

float Player::getBottom() const
{
	return this->getHitbox().top + this->getHitbox().height;
}



const sf::Vector2f Player::getHitboxCenter() const
{
	return sf::Vector2f(
		this->hitbox->getGlobalBounds().left + this->hitbox->getGlobalBounds().width / 2.f,
		this->hitbox->getGlobalBounds().top + this->hitbox->getGlobalBounds().height / 2.f
	);
}

const sf::Vector2f Player::normalize(const sf::Vector2f& vector) const
{
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	if (length != 0.f)
	{
		return sf::Vector2f(vector.x / length, vector.y / length);
	}
	else
	{
		return vector;
	}
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}


//modifier


void Player::setJump(const int jump)
{
	this->numberofjump = jump;
}

void Player::setHp(const int hp)
{
	this->hp = hp;

}

void Player::loseHp(const int value)
{
	this->hpMax -= value;
	if(this->hp < 0)
		this->hp = 0;

}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);

}

void Player::setMousePosWindow(const sf::Vector2f& mousePosWindow)
{
	this->mousePosWindow = mousePosWindow;
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;

}

void Player::resetVelocityX()
{
	this->velocity.x = 0.f;
}

void Player::initHitbox()
{
	float offset_x = 30.0f;
	float offset_y = 0.f;
	float width = 69.0f;
	float height = 167.0f;

	this->hitbox = new Hitbox(this->sprite, offset_x, offset_y, width, height);
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

	//jump

	if (dir_y < 0.f && !this->isJumping)
	{
		this->velocity.y = -this->jumpHeight;
		this->isJumping = true;
		std::cout << "Player jump!" << std::endl;
	}

	// Limit falling speed
	if (this->velocity.y > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY;
	}
}

void Player::updatePhysics()
{
	//gravity
	
	this->velocity.y += this->gravity;

	// Deceleration
	this->velocity *= this->drag;

	//jump physic

	if (this->isJumping)
	{
		this->jumpDuration += 1.0f;
		this->velocity.y += -this->jumpHeight * (1.0f - this->jumpDuration / this->jumpMaxDuration);
		if (this->jumpDuration >= this->jumpMaxDuration)
		{
			this->isJumping = false;
			this->jumpDuration = 0.0f;
		}
	}


	//limite falling speed
	if (this->velocity.y > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY;
	}

	// Limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;

	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && this->numberofjump == 1) //haut
	{
		this->move(0.f, -1.f);
		this->animationState = JUMPING;
		this->numberofjump = 0;
	}
}

void Player::updateHitbox()
{
	this->hitbox->update();

}

void Player::updateAnimation()
{
	if (this->animationState == IDLE)
	{
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.15f || this->getAnimationSwitch())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 44.f;
			if (this->currentFrame.left >= 176.f)
				this->currentFrame.left = 0;


			this->animationtimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

	}
	else if (this->animationState == MOVING_RIGHT)
	{
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.15f || this->getAnimationSwitch())
		{
			this->currentFrame.top = 68.f;
			this->currentFrame.left += 44.f;
			if (this->currentFrame.left >= 176.f)
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
			this->currentFrame.top = 68.f;
			this->currentFrame.left += 44.f;
			if (this->currentFrame.left >= 176.f)
				this->currentFrame.left = 0;


			this->animationtimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
			
		}
		this->sprite.setScale(-2.5f, 2.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
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

	if (this->hitbox)
		this->hitbox->render(target);
}
