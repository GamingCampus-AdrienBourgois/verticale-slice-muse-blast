#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Enemy {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;
    float hp;
    bool hasShield;
    bool isBoss;

    void initVariables();
    void initSprite();

public:
    // Constructeur
    Enemy(float x, float y, bool isBoss = false);

    // Destructeur
    ~Enemy();

    // Fonctions membres
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f& getPosition() const;
    const bool& isBossEnemy() const;

    // Fonctions de mise à jour
    void update();
    void updateSpecific();

    // Fonctions de rendu
    void render(sf::RenderTarget& target);

    // Fonction pour tirer un projectile



    //bullet* shootProjectile(float playerPosX, float playerPosY);


    // Fonction pour infliger des dégâts à l'ennemi
    void takeDamage(float damage);

    // Fonction pour activer le bouclier
    void activateShield();

};

