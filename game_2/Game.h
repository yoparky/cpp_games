#pragma once

#include <iostream>
// for rand init
#include <ctime>

#include "Player.h"

/*
    Class for game engine wrapper class
*/
class Game
{
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event sfmlEvent;

    Player player;

    // initializers
    void initVariables();
    void initWindow();
public:
    Game();
    ~Game();

    // accessors
    const bool running() const;

    // modifiers

    // functions
    void pollEvents();
    void update();
    void render();
};