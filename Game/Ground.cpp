#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

#include "ground.h"
#include "hitbox.h"

void Ground::initHitbox()
{
	float offset_x = 0.0f;
	float offset_y = 0.0f;
	float width = 3887.0f;
	float height = 32.0f;

	//this->hitbox = new Hitbox(this->sprite, offset_x, offset_y, width, height);
}

void Ground::initTexture()
{
	if (!this->texture.loadFromFile("Assets/sprite/texturesol1.png"))
	{
		std::cout << "Error::player::image not load" << "\n";
	}
}

void Ground::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(10.f, 10.f);
}

Ground::Ground()
{
	this->initSprite();
	this->initTexture();
}

Ground::~Ground()
{

}

const sf::FloatRect Ground::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

//const sf::FloatRect Ground::getHitbox() const
//{
//	//return this->hitbox->getGlobalBounds();;
//
//}

void Ground::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Ground::updateHitbox()
{
	//this->hitbox->update();
}

void Ground::update()
{
	this->updateHitbox();
}

void Ground::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	/*if (this->hitbox)
		this->hitbox->render(target);*/
}
