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
#include"bullet.h"

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

void Game::initTime()
{
	this->hitdelay = sf::seconds(1.0f);
}

void Game::initWindow()
{
    this->window.create(sf::VideoMode(1700, 600), "MUSIC BLAST", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
	this->Maincamera = window.getDefaultView();
}
void Game::initLevel()
{
	this->level = new Level();
}
void Game::initPlayer()
{
	this->player = new Player();
}
void Game::initEnemy()
{
	this->enemy = new Enemy(301, 420, false);
}


Game::Game()
{
	this->initTime();
	this->initWindow();
	this->initLevel();
	this->initPlayer();
	this->initEnemy();
	this->initGUI();
}

Game::~Game()
{
	delete this->player;
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateCamera()
{
	this->Maincamera.setCenter((this->player->getPosition().x + 300), 300);
}

void Game::updateEnemy()
{
	this->enemy->update();
}

void Game::updateCollision()
{
	//collision player ground
	if (this->player->getHitbox().intersects(this->level->getHitbox()))
	{
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->level->getHitbox().top - this->player->getHitbox().height
		);
		this->player->setJump(1);
	}


	//collision player et enemy
	if (this->player->getHitbox().intersects(this->enemy->getHitbox()))
	{
		if (this->timer.getElapsedTime() >= this->hitdelay)
		{
			std::cout << "Player collided with enemy!" << std::endl;

			this->player->loseHp(-10);

			// Reset the hit delay timer
			this->timer.restart();
		}
	}

	////collision bullet and enemy

}


void Game::updateGUI()
{
	//update player GUI POSITION
	this->healthbar.setPosition(sf::Vector2f(this->Maincamera.getCenter().x - 790.f, this->Maincamera.getCenter().y - 290.f));
	this->healthbarback.setPosition(sf::Vector2f(this->Maincamera.getCenter().x - 793.f, this->Maincamera.getCenter().y - 293.f));
	this->level->hp_sprite.setPosition(sf::Vector2f(this->Maincamera.getCenter().x - 850.f, this->Maincamera.getCenter().y - 295.f));
	this->level->musique_sprite.setPosition(sf::Vector2f(this->Maincamera.getCenter().x - 480.f, this->Maincamera.getCenter().y - 295.f));



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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->shootTimer.getElapsedTime() >= sf::seconds(1.0f))
		{
			sf::Vector2f mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(this->window));
			sf::Vector2f mousePosWorld = this->window.mapPixelToCoords(sf::Vector2i(mousePosWindow));
			this->player->setMousePosWindow(mousePosWorld);

			if (this->shootTimer.getElapsedTime() >= sf::seconds(1.0f))
			{
				this->player->shoot();

				this->shootTimer.restart();
			}
		}
			
	}

	this->updateCamera();

	this->updatePlayer();

	// Calculate the direction vector from player to mouse
	sf::Vector2f mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(this->window));
	sf::Vector2f playerCenter = this->player->getPlayerCenter();
	sf::Vector2f bulletDir = this->player->normalize(mousePosWindow - playerCenter);

	this->updateEnemy();

	this->updateCollision();

	this->updateGUI();

	this->window.setView(Maincamera);

	this->player->setMousePosWindow(mousePosWindow);
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



void Game::renderGUI()
{
	this->window.draw(this->healthbarback);
	this->window.draw(this->healthbar);
}

void Game::render()
{
	this->window.clear();
	this->renderLevel();
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

