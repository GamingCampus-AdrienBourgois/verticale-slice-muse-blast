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
#include "Gameovermenu.h"


class Game {
private:


    sf::RenderWindow window;
    sf::Event ev;
	sf::Texture tilesheet;
    sf::Time hitdelay;
    sf::Clock timer;
	sf::Clock shootdelay;

    //Level
    unsigned int killCount;
    sf::Font font;
    sf::Text killCountText;


    //bullet
    float cooldown = 1.f;
    std::vector<Bullet*> bullets;
    std::map<std::string, sf::Texture*> texture;
    sf::Vector2f mousePosWindow;
    sf::Clock shootTimer;

    //enemy
	std::vector<Enemy*> enemies;

    //include

    class Player* player;
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
    void spawnEnemy();
    Menu mainMenu;

public:

    Game();
	virtual ~Game();

	void updatePlayer();
    void updateCamera();

    void updateCollision();
	void updateGUI();
	void updateInput();
    void updateBullet();
    void updateEnemy();
	void update();
    void renderLevel();
    void RenderPlayer();
    void renderGUI();
	void render();
    const sf::RenderWindow& getWindow() const;

};