#include "enemy.h"
#include <iostream>

// Initialise les variables
void Enemy::initVariables() {
    this->speed = 2.f;
    this->hp = 100.f;
    this->hasShield = false;
}

// Initialise le sprite de l'ennemi
void Enemy::initSprite() {
    if (!this->texture.loadFromFile("path/to/enemy_texture.png")) {
        std::cerr << "Error::EnemySmall::initSprite::Texture not loaded" << std::endl;
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

// Mise � jour de l'ennemi
void Enemy::update() {
    // Logique commune pour tous les ennemis ici
    this->updateSpecific();
}

// Mise � jour sp�cifique pour les petits ennemis
void Enemy::updateSpecific() {
    // Logique sp�cifique pour les petits ennemis ici
    // Par exemple, d�placement al�atoire
    // Gestion du tir de projectile, etc.
}

// Rendu de l'ennemi
void Enemy::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

// Fonction pour tirer un projectile
bullet* Enemy::shootProjectile(float playerPosX, float playerPosY) {
    // Logique de tir de projectile ici
    return nullptr; // Remplacez par le projectile r�el cr��
}

// Fonction pour infliger des d�g�ts � l'ennemi
void Enemy::takeDamage(float damage) {
    if (this->hasShield) {
        // Logique pour g�rer le bouclier ici
    }
    else {
        this->hp -= damage;
        if (this->hp <= 0) {
            // Logique pour g�rer la mort de l'ennemi ici
        }
    }
}

// Fonction pour activer le bouclier
void Enemy::activateShield() {
    // Logique pour activer le bouclier ici
}

// Fonction pour augmenter la vitesse
void Enemy::increaseSpeed() {
    this->speed *= 1.5f; // Augmente la vitesse de 50%
}

// Fonction pour g�rer les phases du boss
void Enemy::bossPhaseUpdate() {
    // Logique pour g�rer les phases du boss ici
}