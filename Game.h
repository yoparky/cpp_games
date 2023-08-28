#pragma once

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
    // Variables
    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    // Private functions
    void initVariables();
    void initWindow();

public:
    // Constructors and Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();
};