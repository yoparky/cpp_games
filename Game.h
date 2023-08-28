#pragma once

#include <iostream>
#include <vector>
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
    // Variables
    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    // Private functions
    void initVariables();
    void initWindow();
    void initEnemies();

    // Mouse Positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    
    // Game logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

public:
    // Constructors and Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;

    // Functions
    void spawnEnemy();
    void updateEnemies();
    void renderEnemies();
    void pollEvents();
    void updateMousePositions();
    void update();
    void render();
};