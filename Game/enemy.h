#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "hitbox.h"

enum ENEMY_ANIMATION_STATES
{
    ENEMY_IDLE = 0,
    ENEMY_MOVING_LEFT = 1,
    ENEMY_MOVING_RIGHT = 2,
    ENEMY_GETDAMAGED = 3,
    ENEMY_DEAD = 4
};

class Enemy {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;
    sf::Vector2f direction;
    float hp;
    bool hasShield;
    bool isBoss;
    unsigned hitsReceived;
    bool isdead;
    float followDistance;

    //animation
    sf::Clock animationtimer;
    short animationState;
    sf::IntRect currentFrame;
    bool animationswitch;

    void initAnimation();

    //hitbox

    Hitbox* hitbox;


    void initVariables();
	void initTexture();
    void initSprite();


public:
    // Constructeur
    Enemy();
    Enemy(float x, float y, bool isBoss = false);

    // Destructeur
    ~Enemy();

    // Fonctions membres
    const bool& getAnimationSwitch();
    const sf::FloatRect getbound() const;
    const sf::Vector2f& getPosition() const;
    const bool& dead();
    const bool& isBossEnemy() const;

    // Fonction pour tirer un projectile
    //bullet* shootProjectile(float playerPosX, float playerPosY);

    // Fonction pour infliger des dégâts à l'ennemi
    void takeDamage(float damage);

    // Fonction pour activer le bouclier
    void activateShield();


    //update
    void followplayer(const sf::Vector2f& playerPosition);
    void update(const sf::Vector2f& playerPosition);
    void movement(const sf::Vector2f& playerPosition);
	void updateAnimation();
    //render

    void render(sf::RenderTarget& target);
};

