#pragma once

// for rand init
#include <ctime>
// precompile headers
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
    Class for game engine wrapper class
*/
class Game
{
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;

    // initializers
    void initVariables();
    void initWindow();
public:
    Game();
    ~Game();

    // accessors

    // modifiers

    // functions
    void update();
    void render();
};