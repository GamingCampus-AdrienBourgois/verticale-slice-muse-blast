#include "Enemy.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

// Initialise les variables
void Enemy::initVariables() {
    this->speed = 2.f;
    this->hp = 100.f;
    this->hasShield = false;
}

// Initialise le sprite de l'ennemi
void Enemy::initSprite() {
    if (!this->texture.loadFromFile("../assets/enemy.png")) { // IMAGE A CHANGER QUAND ON AURA TROUVE
        std::cerr << "Error::Enemy::initSprite::Texture not loaded" << std::endl;
    }

    this->sprite.setTexture(this->texture);
}

// Constructeur
Enemy::Enemy(float x, float y, bool isBoss) : isBoss(isBoss) {
    this->initVariables();
    this->initSprite();
    this->sprite.setPosition(x, y);
}

// Destructeur
Enemy::~Enemy() {}

// Renvoie les limites globales du sprite
const sf::FloatRect Enemy::getGlobalBounds() const {
    return this->sprite.getGlobalBounds();
}

// Renvoie la position actuelle de l'ennemi
const sf::Vector2f& Enemy::getPosition() const {
    return this->sprite.getPosition();
}

// Renvoie si l'ennemi est un boss
const bool& Enemy::isBossEnemy() const {
    return this->isBoss;
}

// Mise à jour de l'ennemi
void Enemy::update() {
    // Logique commune pour tous les ennemis ici
    this->updateSpecific();
}

// Mise à jour spécifique pour les petits ennemis
void Enemy::updateSpecific() {

    this->sprite.move(speed * 1.0f, 0); // Multiplicateur de vitesse

    // Inversion de la direction lorsque l'ennemi atteint un bord
    if (this->sprite.getPosition().x <= 300 || this->sprite.getPosition().x + this->getGlobalBounds().width >= 800) {
        speed = -speed;
    }

    // Si il est a - de 75% hp il va plus vite
    if (this->hp / 100.0f <= 0.75) {
        this->speed *= 1.5f; // Increase the speed by 50%
    }

}


// Rendu de l'ennemi
void Enemy::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}



// Fonction pour tirer un projectile
//bullet* Enemy::shootProjectile(float playerPosX, float playerPosY) {
    // Logique de tir de projectile ici
    //return nullptr; // Remplacez par le projectile réel créé
//}



void Enemy::takeDamage(float damage) {
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
            // logique de la mort de l'ennemi
        }
    }
}

// Fonction pour activer le bouclier
void Enemy::activateShield() {
    this->hasShield = true;
}
