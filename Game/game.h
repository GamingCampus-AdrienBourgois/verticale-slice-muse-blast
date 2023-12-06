// Game.h
#pragma once
#include "Engine.h"
#include "SceneModule.h"
#include "Scenes/DefaultScene.h"
#include "Menu.h"

class Game {
public:
    Game();
    void Run();

private:
    sf::RenderWindow window;
    SceneModule* sceneModule;
    Menu mainMenu;
};