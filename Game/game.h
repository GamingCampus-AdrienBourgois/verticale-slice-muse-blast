#pragma once
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

#include<map>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>


#include "Engine.h"
#include "SceneModule.h"
#include "Scenes/DefaultScene.h"
#include "Menu.h"
#include "player.h"
#include "enemy.h"
#include "Level.h"
#include "bullet.h"


class Game {
private:


    sf::RenderWindow window;
    sf::Event ev;
	sf::Texture tilesheet;
    sf::Time hitdelay;
    sf::Clock timer;
	sf::Clock shootdelay;

    //Level

    //bullet
    float cooldown = 0.25f;
    std::vector<Bullet*> bullets;
    std::map<std::string, sf::Texture*> texture;
    sf::Vector2f mousePosWindow;
    sf::Clock shootTimer;


    //include

    Player* player;
    Enemy* enemy;
    class Level* level;

    //player GUI

    void initGUI();
	sf::RectangleShape healthbar;
    sf::RectangleShape healthbarback;

	//camera

	sf::View Maincamera;

    //main game


    void initTextureBullet();
    void initTime();
    void initWindow();
    void initLevel();
    void initPlayer();
    void initEnemy();
    Menu mainMenu;

public:

    Game();
	virtual ~Game();

	void updatePlayer();
    void updateCamera();
    void updateEnemy();
    void updateCollision();
	void updateGUI();
	void updateInput();
    void updateBullet();
	void update();
    void renderLevel();
    void RenderPlayer();
    void RenderEnemy();
    void renderGUI();
	void render();
    const sf::RenderWindow& getWindow() const;

};