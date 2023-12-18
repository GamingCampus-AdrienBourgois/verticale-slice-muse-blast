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
#include "Player.h"



void Level::initTexture()
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 4);

    this->randomnumber = dis(gen);

    if (!this->texturesheet.loadFromFile("Assets/sprite/stage" + std::to_string(this->randomnumber) + ".png"))
    {
        std::cout << "Loading Backgroung" << "\n";
    }
    if (!this->groundtexture.loadFromFile("Assets/sprite/texturesol1.png"))
    {
        std::cout << "Loading ground" << "\n";
    }





    if (this->randomnumber == 1)
    {
        std::cout << "Electro" << "\n";
    }

    else if (this->randomnumber == 2)
    {
        std::cout << "Lofi" << "\n";
    }

    else if (this->randomnumber == 3)
    {
        std::cout << "Pop" << "\n";
    }

    else
    {
        std::cout << "Blues" << "\n";
    }

}

void Level::initSprite()
{
    this->sprite1.setTexture(this->texturesheet);
    this->sprite1.setScale(2.5f, 2.5f);
    this->sprite1.setPosition(-1500.f, -100.f);

    this->ground.setTexture(this->groundtexture);
	this->ground.setScale(2.5f, 2.5f);
    this->ground.setPosition(-500.f, 550.f);
}

void Level::initgroundhitbox()
{
    if (this->hitbox != nullptr) {
        delete this->hitbox;
    }
    this->hitbox = new Hitbox(this->ground, 0.f, 0.f, this->ground.getGlobalBounds().width, this->ground.getGlobalBounds().height);
}

void Level::initMusic()
{
    if (!this->music.openFromFile("Assets/music/music" + std::to_string(this->randomnumber) + ".ogg")) {
        std::cout << "Loading Music" << "\n";
    }

    music.setLoop(true);
    music.setVolume(1.0f);
    //music.play(); 
}

void Level::initmodificationlevel()
{
    this->level_player_speed_initial = 10.0f;
    this->level_ennemy_damage_initial = 0.0f;
}


Level::Level()
{
    
    this->initTexture();
    this->initSprite();
    this->initgroundhitbox();
    this->initMusic();
    this->initmodificationlevel();
}

Level::~Level()
{
}

void Level::render(sf::RenderTarget& target)
{
    target.draw(this->sprite1);
    target.draw(this->ground);
    this->hitbox->render(target);

}


void Level::level_effect()
{
    if (this->randomnumber == 1)
    {
        this->level_player_speed = 4;
    }
}