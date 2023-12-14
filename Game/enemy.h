#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.h"

class EnemySmall {
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
    EnemySmall(float x, float y, bool isBoss = false);

    // Destructeur
    ~EnemySmall();

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
    Projectile* shootProjectile(float playerPosX, float playerPosY);

    // Fonction pour infliger des dégâts à l'ennemi
    void takeDamage(float damage);

    // Fonction pour activer le bouclier
    void activateShield();

    // Fonction pour augmenter la vitesse
    void increaseSpeed();

    // Fonction pour gérer les phases du boss
    void bossPhaseUpdate();
};