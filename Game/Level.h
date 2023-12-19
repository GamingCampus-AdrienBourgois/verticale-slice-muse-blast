#pragma once
#include "hitbox.h"
class Level
{
private:
    
    Hitbox* hitbox;

    int randomnumber;

    // Modification du a l'environnement

    //electro Le joueur cours plus vite, le boss inflige plus de degats
    float level_player_speed;
    float level_ennemy_damage;

    float level_player_speed_initial;
    float level_ennemy_damage_initial;

    //

    sf::Sprite sprite1;
    sf::Texture texturesheet;
    sf::Sprite ground;
    sf::Texture groundtexture;
    sf::Music music;

    void initTexture();
    void initSprite();
    void initgroundhitbox();
    void initMusic();
    void initmodificationlevel();



public:
    Level();
    virtual ~Level();

    //accesor 
    const sf::FloatRect getHitbox() const;

    void level_effect();
    void render(sf::RenderTarget& target);
};
