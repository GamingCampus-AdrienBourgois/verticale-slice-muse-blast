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

void Game::initTextureBullet()
{
	this->texture["bullet"] = new sf::Texture();
	this->texture["bullet"]->loadFromFile("Assets/sprite/BulletSprite.png");
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

void Game::spawnEnemy()
{
	int numEnemies = 150;
	int spacing = 250;
	int playerOffset = 400;  // Minimum distance from the player

	// Spawn the first enemy with an offset
	this->enemies.push_back(new Enemy(playerOffset, 340, false));

	// Spawn the remaining enemies at regular intervals
	for (int i = 1; i < numEnemies; ++i)
	{
		int xPos = playerOffset + i * spacing;
		this->enemies.push_back(new Enemy(xPos, 340, false));
	}
}


Game::Game()
{
	this->initTextureBullet();
	this->initTime();
	this->initWindow();
	this->initLevel();
	this->spawnEnemy();
	this->initPlayer();
	this->initGUI();
}

Game::~Game()
{
	delete this->player;
	for (auto& i : this->texture)
	{
		delete i.second;
	}
	/*for (auto *i : this->bullet)
	{
		delete i;
	}*/
}

void Game::updatePlayer()
{
	this->player->update();

	// Limit player movement between X0 and X14500
	if (this->player->getPosition().x < 0.f)
	{
		this->player->setPosition(0.f, this->player->getPosition().y);
		this->player->resetVelocityX();
	}
	else if (this->player->getPosition().x > 14500.f)
	{
		this->player->setPosition(14500.f, this->player->getPosition().y);
		this->player->resetVelocityX();
	}
}

void Game::updateCamera()
{
	this->Maincamera.setCenter((this->player->getPosition().x + 300), 300);
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

void Game::updateInput()
{
	if (shootTimer.getElapsedTime().asSeconds() >= cooldown) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			// Get the mouse position in window coordinates
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

			// Convert mouse position to world coordinates
			sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePosition);

			// Calculate the direction vector from player to mouse
			float directionX = worldMousePos.x - this->player->getPosition().x;
			float directionY = worldMousePos.y - this->player->getPosition().y;

			// Normalize the direction vector
			float magnitude = std::sqrt(directionX * directionX + directionY * directionY);
			if (magnitude != 0) {
				directionX /= magnitude;
				directionY /= magnitude;
			}

			// Create a new bullet with the calculated direction as velocity
			this->bullets.push_back(new Bullet(
				this->texture["bullet"],
				this->player->getPlayerCenter().x,
				this->player->getPlayerCenter().y,
				directionX,
				directionY,
				15.f
			));
			this->bullets.back()->setStartPosition(this->player->getPlayerCenter());
			// Restart the shoot timer
			shootTimer.restart();
		}
	}
}

void Game::updateBullet()
{
	unsigned counter = 0;
	float maxTravelDistance = 500.f;

	for (auto* bullet : this->bullets)
	{
		bullet->update();

		// Check if the bullet has traveled the maximum distance
		if (std::abs(bullet->getPosition().x - bullet->getStartPosition().x) >= maxTravelDistance)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::updateEnemy()
{
	unsigned Ecounter = 0;
	for (auto* enemy : this->enemies)
	{
		sf::Vector2f playerPosition = this->player->getPosition();
		enemy->update(playerPosition);

		for (unsigned Bcounter = 0; Bcounter < this->bullets.size(); ++Bcounter)
		{
			if (enemy->getbound().intersects(this->bullets[Bcounter]->getbound()))
			{
				// Collision detected between enemy and bullet
					this->enemies.erase(this->enemies.begin() + Ecounter);
				delete this->bullets.at(Bcounter);
				this->bullets.erase(this->bullets.begin() + Bcounter);

				--Ecounter;
				--Bcounter;
				break; // Exit the bullet loop since the bullet has been removed
			}
		}
		++Ecounter;

		if (enemy->getbound().intersects(this->player->getHitbox()))
		{
			if (this->timer.getElapsedTime() >= this->hitdelay)
			{
				std::cout << "Player collided with enemy!" << std::endl;

				this->player->loseHp(-10);

				// Reset the hit delay timer
				this->timer.restart();
			}
		}
	}
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

	this->updateInput();

	this->updateBullet();

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
	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}
	this->renderGUI();
	
    this->window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insérer une instruction return ici
	return this->window;
}

