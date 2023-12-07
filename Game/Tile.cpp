#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

#include "Tile.h"

Tile::Tile(sf::Texture* texture_sheet, sf::IntRect texture_rect, bool damaging)
	: damaging(damaging)
{
	
	this->sprite.setTexture(*texture_sheet);
	this->sprite.setTextureRect(texture_rect);

}

const sf::FloatRect Tile::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Tile::update()
{


}

void Tile::render(sf::RenderTarget& target)
{

	target.draw(this->sprite);
}
