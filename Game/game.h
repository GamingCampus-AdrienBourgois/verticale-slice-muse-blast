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
#include"Tilemap.h"
class Game {
private:
    sf::RenderWindow window;
    sf::Event ev;
	sf::Texture tilesheet;

    Player* player;
	Tilemap* tilemap;
    void initWindow();
	void initTilesheet();
    void initPlayer();
	void initTilemap();
    Menu mainMenu;

public:

    Game();
	virtual ~Game();

	void updatePlayer();
    void updateCollision();
	void updateTilemap();
	void update();
    void RenderPlayer();
    void renderTilemap();
	void render();
    const sf::RenderWindow& getWindow() const;

};