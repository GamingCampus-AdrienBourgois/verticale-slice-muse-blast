#include "Enemy.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>
#include <cmath>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

#include "hitbox.h"

void Enemy::initAnimation()
{


}

// Initialise les variables
void Enemy::initVariables() 
{
    this->speed = 2.f;
    this->hp = 100.f;
    this->hasShield = false;
    this->followDistance = 750.f;
}

void Enemy::initTexture()
{
    if (!this->texture.loadFromFile("Assets/Sprite/Idle.png")) { // IMAGE A CHANGER QUAND ON AURA TROUVE
        std::cerr << "Error::Enemy::initSprite::Texture not loaded" << std::endl;
    }
}

// Initialise le sprite de l'ennemi
void Enemy::initSprite() 
{
    this->sprite.setTexture(this->texture);
    this->currentFrame = sf::IntRect(30, 50, 78, 76);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(2.5f, 2.5f);
}


Enemy::Enemy()
{

}

// Constructeur
Enemy::Enemy(float x, float y, bool isBoss) : isBoss(isBoss) 
{
    this->initTexture();
    this->initVariables();
    this->initSprite();
    this->sprite.setPosition(x, y);
}

// Destructeur
Enemy::~Enemy() 
{
}

const bool& Enemy::getAnimationSwitch()
{
    bool anim_switch = this->animationswitch;

    if (this->animationswitch)
        this->animationswitch = false;

    return anim_switch;
}

// Renvoie les limites globales du sprite
const sf::FloatRect Enemy::getbound() const
{
    return this->sprite.getGlobalBounds();
}

// Renvoie la position actuelle de l'ennemi
const sf::Vector2f& Enemy::getPosition() const 
{
    return this->sprite.getPosition();
}

const bool& Enemy::dead()
{
    if (this->isdead == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Renvoie si l'ennemi est un boss
const bool& Enemy::isBossEnemy() const 
{
    return this->isBoss;
}

// Fonction pour activer le bouclier
void Enemy::activateShield() 
{
    this->hasShield = true;
}


// Fonction pour tirer un projectile
//bullet* Enemy::shootProjectile(float playerPosX, float playerPosY) {
    // Logique de tir de projectile ici
    //return nullptr; // Remplacez par le projectile r�el cr��
//}

void Enemy::takeDamage(float damage) 
{
    if (this->hasShield) {
        // logique du shield
    }
    else {
        this->hp -= damage;

        // si il est a 50% de ses pv il gagne un shield
        if (this->hp / 100.0f <= 0.5) {
            this->activateShield();
        }

        // si il est a 25% il fait plus de degats
        if (this->hp / 100.0f <= 0.25) {
            damage *= 1.5f; // augmenter les degats
        }

        if (this->hp <= 0) {
            this->isdead = true;
        }
    }
}

void Enemy::movement(const sf::Vector2f& playerPosition)
{
    this->animationState = ENEMY_IDLE;
    if (rand() % 100 < 1) // Adjust the percentage as needed
    {
        // Generate a random horizontal direction
        int randomDirection = rand() % 3 - 1; // -1, 0, or 1
        this->direction.x = static_cast<float>(randomDirection);
    }

    followplayer(playerPosition);

    // Move the enemy horizontally
    float horizontalMovement = this->speed * this->direction.x;
    this->sprite.move(horizontalMovement, 0.f);

    if (horizontalMovement > 0) {
        // Moving to the right
        this->animationState = ENEMY_MOVING_RIGHT;
    }
    else if (horizontalMovement < 0) {
        // Moving to the left
        this->animationState = ENEMY_MOVING_LEFT;
    }
    else {
        // Not moving horizontally
        this->animationState = ENEMY_IDLE;
    }
}

void Enemy::updateAnimation()
{
    if (this->animationState == ENEMY_IDLE)
    {
        if (this->animationtimer.getElapsedTime().asSeconds() >= 0.15f || this->getAnimationSwitch())
        {
            this->currentFrame.top = 50.f;
            this->currentFrame.left += 128.f;
            if (this->currentFrame.left >= 640.f)
                this->currentFrame.left = 30;


            this->animationtimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }

    }
    else if (this->animationState == ENEMY_MOVING_RIGHT)
    {
        if (this->animationtimer.getElapsedTime().asSeconds() >= 0.15f || this->getAnimationSwitch())
        {
            this->currentFrame.top = 50.f;
            this->currentFrame.left += 128.f;
            if (this->currentFrame.left >= 640.f)
                this->currentFrame.left = 30;


            this->animationtimer.restart();
            this->sprite.setTextureRect(this->currentFrame);

        }
        this->sprite.setScale(2.5f, 2.5f);
        this->sprite.setOrigin(0.f, 0.f);
    }

    else if (this->animationState == ENEMY_MOVING_LEFT)
    {
        if (this->animationtimer.getElapsedTime().asSeconds() >= 0.15f || this->getAnimationSwitch())
        {
            this->currentFrame.top = 50.f;
            this->currentFrame.left += 128.f;
            if (this->currentFrame.left >= 640.f)
                this->currentFrame.left = 30;


            this->animationtimer.restart();
            this->sprite.setTextureRect(this->currentFrame);

        }
        this->sprite.setScale(-2.5f, 2.5f);
        this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 4.f, 0.f);
    }
}


void Enemy::followplayer(const sf::Vector2f& playerPosition)
{
    // Calculate the distance between the enemy and the player
    float distanceToPlayer = std::abs(playerPosition.x - this->sprite.getPosition().x);

    // If the player is too close, follow the player
    if (distanceToPlayer < followDistance)
    {
        // Determine the direction to move towards the player
        if (playerPosition.x > this->sprite.getPosition().x)
        {
            this->direction.x = 5.f; // Move towards the player on the right
        }
        else if (playerPosition.x < this->sprite.getPosition().x)
        {
            this->direction.x = -5.f; // Move towards the player on the left
        }
    }
}

void Enemy::update(const sf::Vector2f& playerPosition)
{
    // Logique commune pour tous les ennemis ici
    this->updateAnimation();
    this->movement(playerPosition);
}

// Rendu de l'ennemi
void Enemy::render(sf::RenderTarget& target) 
{
    target.draw(this->sprite);

}