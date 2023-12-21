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


// Initialisation de toutes les textures et icones
void Level::initTexture()
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 4);

    this->randomnumber = dis(gen);

    if (!this->background_texture.loadFromFile("Assets/sprite/stage" + std::to_string(this->randomnumber) + ".png"))
    {
        std::cout << "Loading Backgroung" << "\n";
    }

    if (!this->groundtexture.loadFromFile("Assets/sprite/texturesol1.png"))
    {
        std::cout << "Loading ground" << "\n";
    }

    if (!this->musique_texture.loadFromFile("Assets/sprite/musique" + std::to_string(this->randomnumber) + ".png")) 
    {
        std::cout << "Loading Icone" << "\n";
    }
    if (!this->Playersprite.loadFromFile("Assets/sprite/SpritePlayer"+ std::to_string(this->randomnumber) + ".png"))
    {
        std::cout << "Error::player::image not load" << "\n";
    }

    //Icones
    if (!this->hp_texture.loadFromFile("Assets/sprite/hp.png"))
    {
        std::cout << "Loading Backgroung" << "\n";
    }
}


void Level::initSprite()
{
    this->background_sprite.setTexture(this->background_texture);
    this->background_sprite.setScale(2.5f, 2.5f);
    this->background_sprite.setPosition(-700.f, -100.f);

    this->ground.setTexture(this->groundtexture);
    this->ground.setScale(2.5f, 2.5f);
    this->ground.setPosition(-700.f, 550.f);

    this->hp_sprite.setTexture(this->hp_texture);
    this->musique_sprite.setTexture(this->musique_texture);

}

void Level::initMusic()
{
    if (!this->music.openFromFile("Assets/music/music" + std::to_string(this->randomnumber) + ".ogg")) {
        std::cout << "Loading Music" << "\n";
    }

    music.setLoop(true);
    music.setVolume(1.0f);
    /* music.play(); */
}


//Valeur initial avant modif
void Level::initmodificationlevel()
{
    this->level_player_speed_initial = 10.0f;
    this->level_ennemy_damage_initial = 0.0f;
}

void Level::initgroundhitbox()
{
    if (this->hitbox != nullptr) {
        delete this->hitbox;
    }
    this->hitbox = new Hitbox(this->ground, 0.f, 0.f, this->ground.getGlobalBounds().width, this->ground.getGlobalBounds().height);
}


Level::Level()
{

    this->initTexture();
    this->initSprite();
    this->initMusic();
    this->initmodificationlevel();
    this->initgroundhitbox();
}

Level::~Level()
{
}

void Level::render(sf::RenderTarget& target)
{
    target.draw(this->background_sprite);
    target.draw(this->hp_sprite);
    target.draw(this->musique_sprite);
    target.draw(this->ground);
    this->hitbox->render(target);

}

//Modificqtion du au level
void Level::level_effect()
{
    if (this->randomnumber == 1)
    {
        this->level_player_speed = 4;
    }

    if (this->randomnumber == 1)
    {
        this->level_player_speed = 4;
    }

    if (this->randomnumber == 1)
    {
        this->level_player_speed = 4;
    }

    if (this->randomnumber == 1)
    {
        this->level_player_speed = 4;
    }
}

const sf::FloatRect Level::getHitbox() const
{
    return this->hitbox->getGlobalBounds();
}

const sf::Texture& Level::getPlayerSprite() const
{
    return this->Playersprite;
}

