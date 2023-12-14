#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>
#include <string>
#include <random>


#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

#include "Level.h"



void Level::initTexture()
{
	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dis(1, 4);

	int i = dis(gen);

	if (!this->texturesheet.loadFromFile("../Assets/stage" + std::to_string(i) + ".png"))
	{
		std::cout << "Loading Backgroung" << "\n";
	}

}

void Level::initSprite()
{
	this->sprite1.setTexture(this->texturesheet);
	this->sprite1.setScale(2.5f, 2.5f);
	this->sprite1.setPosition(-1500.f, -100.f);
}

void Level::initMusic()
{
	if (!this->music.openFromFile("../Assets/song/musicElectro.ogg")) {
		std::cout << "Loading Music" << "\n";
	}



	music.setLoop(true);
	music.setVolume(5.0f);
	music.play();
}


Level::Level()
{

	this->initTexture();
	this->initSprite();
	this->initMusic();
}

Level::~Level()
{
}

void Level::render(sf::RenderTarget& target)
{
	target.draw(this->sprite1);

}