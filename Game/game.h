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
#include "Tile.h"
#include "Tilemap.h"
#include "enemy.h"
#include "Level.h"


class Game {
private:


    sf::RenderWindow window;
    sf::Event ev;
	sf::Texture tilesheet;

    //bullet


    //Level


    //include

    Player* player;
	Tilemap* tilemap;
    Enemy* enemy;
	Level* level;


    //player GUI

    void initGUI();
	sf::RectangleShape healthbar;
    sf::RectangleShape healthbarback;

	//camera

	sf::View Maincamera;

    //main game


    void initWindow();
    void initLevel();
	void initTilesheet();
    void initPlayer();
    void initEnemy();
	void initTilemap();
    Menu mainMenu;

public:

    Game();
	virtual ~Game();

	void updatePlayer();
    void updateCamera();
    void updateEnemy();
    void updateCollision();
	void updateTilemap();
	void updateGUI();
	void update();
    void renderLevel();
    void RenderPlayer();
    void RenderEnemy();
    void renderTilemap();
    void renderGUI();
	void render();
    const sf::RenderWindow& getWindow() const;

};