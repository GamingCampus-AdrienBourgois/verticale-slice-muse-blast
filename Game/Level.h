#pragma once
#include "hitbox.h"
#include "game.h"
#include <random>
class Level
{
private:

    Hitbox* hitbox;
 

    // Modification du a l'environnement

    //ELECTRO Le joueur cours plus vite, le boss inflige plus de degats
    float level_player_speed;
    float level_ennemy_damage;
    //POP Projectiles des ennemies plus lents
    float level_player_jump;
    //LOFI Projectiles de ennemies plus lents
    float level_ennemie_projectiles_speed;
    //BLUES Le boss fait moins de degats mais lance de temps en temps une attaque qui one-shot
    float level_ennemie_projectiles_oneshot;



    float level_player_speed_initial;
    float level_ennemy_damage_initial;
    float level_player_jump_initial;
    float level_ennemie_projectiles_speed_initial;
    float level_ennemie_projectiles_oneshot_initial;


    sf::Sprite background_sprite;
    sf::Texture background_texture;
    sf::Texture Playersprite;
    sf::Texture hp_texture;
    sf::Texture musique_texture;
    sf::Music music;
    sf::Sprite ground;
    sf::Texture groundtexture;

    void initTexture();
    void initSprite();
    void initMusic();
    void initgroundhitbox();
    


public:
    Level();
    virtual ~Level();

    //accesor 
    const sf::FloatRect getHitbox() const;
    const sf::Texture& getPlayerSprite() const;
    sf::Sprite hp_sprite;
    sf::Sprite musique_sprite;
    void initmodificationlevel();
    void level_effect();
    void render(sf::RenderTarget& target);
};


class YourClass {
public:
    YourClass() {
        // Utilisation d'une variable statique pour garantir la même valeur pour toutes les instances
        if (!initialized) {
            generateRandomNumber();
            initialized = true;
        }
    }

    int getRandomNumber() const {
        return randomnumber;
    }

private:
    static bool initialized;  // Variable statique pour vérifier si la valeur a été initialisée
    static int randomnumber;  // Variable statique pour stocker la valeur aléatoire

    void generateRandomNumber() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 4);
        randomnumber = dis(gen);
    }
};