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

void Game::initGUI()
{
	//initplayerGUI
	
	this->healthbar.setSize(sf::Vector2f(300.f, 30.f));
	this->healthbar.setFillColor(sf::Color::Red);
	//this->healthbar.setPosition(sf::Vector2f(this->player->getPosition().x, this->player->getPosition().y));

	this->healthbarback.setSize(sf::Vector2f(310.f, 35.f));
	this->healthbarback.setFillColor(sf::Color(25, 25, 25, 200));
	//this->healthbarback.setPosition(sf::Vector2f(this->player->getPosition().x, this->player->getPosition().y));

}

void Game::initWindow()
{
    this->window.create(sf::VideoMode(800, 600), "MUSIC BLAST", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
	this->Maincamera = window.getDefaultView();
}
void Game::initLevel()
{
	this->level = new Level();
}
void Game::initTilesheet()
{
	if (!this->tilesheet.loadFromFile("../Assets/Tile.jpg"))
	{
		std::cout << "Error::tilesheet::image not load" << "\n";
	}
}
void Game::initPlayer()
{
	this->player = new Player();
}
void Game::initEnemy()
{
	this->enemy = new Enemy(301, 420, false);
}
void Game::initTilemap()
{
	this->tilemap = new Tilemap(20, 20, &this->tilesheet, 50);
	this->tilemap->addTile(3, 0);
}

Game::Game()
{
	this->initWindow();
	this->initLevel();
	this->initTilesheet();
	this->initPlayer();
	this->initEnemy();
	this->initTilemap();
	this->initGUI();

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

void Game::updateCamera()
{
	this->Maincamera.setCenter(this->player->getPosition().x, 300);
}

void Game::updateEnemy()
{

	this->enemy->update();

}

void Game::updateCollision()
{
	//collision bas fenetre

	if (this->player->getPosition().y +this->player->getGlobalBounds().height >= this->window.getSize().y);
	{
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height

  		);
	}

	//collision enemy 

	//if (this->player->getPosition().x, +this->player->getGlobalBounds().width == this->enemy->getPosition().x, +this->enemy->getGlobalBounds().width);
	//{
	//	this->player->resetVelocityX();
	//}

}

void Game::updateTilemap()
{
	this->tilemap->update();
}

void Game::updateGUI()
{
	//update player GUI POSITION
	this->healthbar.setPosition(sf::Vector2f(this->player->getPosition().x - 385.f, this->player->getPosition().y - 450.f));
	this->healthbarback.setPosition(sf::Vector2f(this->player->getPosition().x - 390.f, this->player->getPosition().y -453.f));

	//update player GUI
	this->player->setHp(100);
	float hppercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->healthbar.setSize(sf::Vector2f(300.f * hppercent, this->healthbar.getSize().y));

}

void Game::update()
{
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();

		if (this->ev.type == sf::Event::KeyReleased &&
			(
				this->ev.key.code == sf::Keyboard::Z ||
				this->ev.key.code == sf::Keyboard::Q ||
				this->ev.key.code == sf::Keyboard::S ||
				this->ev.key.code == sf::Keyboard::D
				)
			)
		{
			this->player->resetAnimationTimer();
		}
			
	}

	this->updateCamera();

	this->updatePlayer();

	this->updateEnemy();

	this->updateCollision();

	this->updateTilemap();

	this->updateGUI();

	this->window.setView(Maincamera);
}

void Game::renderLevel()
{
	this->level->render(this->window);
}


void Game::RenderPlayer()
{
	this->player->render(this->window);
}

void Game::RenderEnemy()
{
	this->enemy->render(this->window);
}

void Game::renderTilemap()
{
	this->tilemap->render(this->window);
}


void Game::renderGUI()
{
	this->window.draw(this->healthbarback);
	this->window.draw(this->healthbar);
}

void Game::render()
{
	
	this->window.clear();
	//render bg
	this->renderLevel();

	//render object
	//mainMenu.Show(window);


	//this->renderTilemap();
	this->RenderPlayer();
	this->RenderEnemy();
	this->renderGUI();

    this->window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insérer une instruction return ici
	return this->window;
}

