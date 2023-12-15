#pragma once
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<time.h>

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


class Game {
private:


    sf::RenderWindow window;
    sf::Event ev;
	sf::Texture tilesheet;
    sf::Time hitdelay;
    sf::Clock timer;

    //bullet


    //Level


    //include

    Player* player;
    Enemy* enemy;
	Level* level;


    //player GUI

    void initGUI();
	sf::RectangleShape healthbar;
    sf::RectangleShape healthbarback;

	//camera

	sf::View Maincamera;

    //main game

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
	void update();
    void renderLevel();
    void RenderPlayer();
    void RenderEnemy();
    void renderGUI();
	void render();
    const sf::RenderWindow& getWindow() const;

};