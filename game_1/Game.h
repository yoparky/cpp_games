#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

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
    void initFonts();
    void initText();

    // Mouse Positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Resources
    sf::Font font;

    // Text
    sf::Text uiText;

    // Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    
    // Game logic
    bool endGame;
    unsigned points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;
    int health;

public:
    // Constructors and Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;
    const bool getEndGame() const;

    // Functions
    void spawnEnemy();
    void updateEnemies();
    void renderEnemies(sf::RenderTarget& target);
    void pollEvents();
    void updateMousePositions();
    void update();
    void render();
    void renderText(sf::RenderTarget& target);
    void updateText();
};