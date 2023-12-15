#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "hitbox.h"

class Enemy {
private:



    sf::Sprite sprite;
    sf::Texture texture;
    float speed;
    float hp;
    bool hasShield;
    bool isBoss;

    //hitbox

    Hitbox* hitbox;


    void initVariables();
	void initTexture();
    void initSprite();
    void initHitbox();


public:
    // Constructeur
    Enemy(float x, float y, bool isBoss = false);

    // Destructeur
    ~Enemy();

    // Fonctions membres
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f& getPosition() const;
    const sf::FloatRect getHitbox() const;
    const bool& isBossEnemy() const;

    // Fonction pour tirer un projectile
    //bullet* shootProjectile(float playerPosX, float playerPosY);

    // Fonction pour infliger des dégâts à l'ennemi
    void takeDamage(float damage);

    // Fonction pour activer le bouclier
    void activateShield();


    //update
    void updateHitbox();
    void update();
    void updateSpecific();
    //render

    void render(sf::RenderTarget& target);
};

