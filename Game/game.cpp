// Game.cpp
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include "Game.h"

void Game::initWindow()
{
    this->window.create(sf::VideoMode(800, 600), "MUSIC BLAST", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}
void Game::initTilesheet()
{
	if (!this->tilesheet.loadFromFile("texture/sol.png"))
	{
		std::cout << "Error::tilesheet::image not load" << "\n";
	}





}
void Game::initPlayer()
{
	this->player = new Player();

}
void Game::initTilemap()
{
	this->tilemap = new Tilemap(20, 20, &this->tilesheet, 50);
	this->tilemap->addTile(0, 0);




}
Game::Game()
{
	this->initWindow();
	this->initTilesheet();
	this->initPlayer();
	this->initTilemap();
}

Game::~Game()
{
	delete this->player;
	delete this->tilemap;

}



void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateCollision()
{
	//collision bas fenetre

	if (this->player->getPosition().y, +this->player->getGlobalBounds().height >= this->window.getSize().y);
	{
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getGlobalBounds().left,
			this->window.getSize().y - this->player->getGlobalBounds().height
  		);
	}

}

void Game::updateTilemap()
{
	this->tilemap->update();
}

void Game::update()
{
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
	}

	this->updatePlayer();

	this->updateCollision();

	this->updateTilemap();
}

void Game::RenderPlayer()
{
	this->player->render(this->window);
}

void Game::renderTilemap()
{
	this->tilemap->render(this->window);
}

void Game::render()
{
	this->window.clear();

	//render object
	mainMenu.Show(window);
	this->renderTilemap();
	this->RenderPlayer();

    this->window.display();

}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insérer une instruction return ici
	return this->window;
}

