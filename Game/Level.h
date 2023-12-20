#pragma once
#include "hitbox.h"

class Level
{
private:

    Hitbox* hitbox;
    int randomnumber;

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

    sf::Sprite hp_sprite;
    sf::Sprite musique_sprite;
    void initmodificationlevel();
    void level_effect();
    void render(sf::RenderTarget& target);
};
