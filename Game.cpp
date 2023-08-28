#include "Game.h"

// Private functions
void Game::initVariables()
{
    this->window = nullptr;
    // Game logic init
    this->points = 0;
    // timer could depend on framerate
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
}
void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    // this->videoMode.getDesktopMode;
    this->window = new sf::RenderWindow(this->videoMode, "My first sfml game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}
void Game::initEnemies()
{
    // Position originates from top left corner
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    // this->enemy.setOutlineColor(sf::Color::Green);
    // this->enemy.setOutlineThickness(1.f);


}
// Constructors and destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game()
{
    delete this->window;
}

// Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}

// Public functions
void Game::spawnEnemy()
{
    /*
        @return void

        spawns enemies and sets their colors and positions.
        - Set a random position
        - Set a random color
        - Adds enemy to vector
    */
    this->enemy.setPosition(
        // random x pos, y starts at 0 (top of screen)
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
    );

    this->enemy.setFillColor(sf::Color::Green);

    // Add enemy to enemies vector
    this->enemies.push_back(this->enemy);

    // Remove enemies at end of screen
    
}
void Game::updateEnemies()
{
    /*
        @return void

        Updates enemy spawn timer and spawns enemies when the total
        amount of enemies is smaller than designated maximum.
        Moves the enemies downwards.
        Removes the enemies at the edge of the screen // TODO
    */

    // update timer for enemy spawning
    if(this->enemies.size() < this->maxEnemies) {
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax)
        // spawn enemy and reset timer
        {
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }
    // Move the enemies
    for(size_t i = 0; i < this->enemies.size(); i++)
    {
        this->enemies[i].move(0.f, 5.f);

        // delete if clicked upon
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
                this->enemies.erase(this->enemies.begin() + i);
                i -= 1;
                // Gain points for killing rect enemies
                this->points += 10.f;
            }
        // delete if gone below screen
        } else if (this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            this->enemies.erase(this->enemies.begin() + i);
        }
        // an important thing to note is that best practice would have removal called once to be safe.
        // a bool can be added to check if the current instance of the loop has already removed an item
    }
}
void Game::renderEnemies()
{
    for(auto &e : this->enemies)
    {
        this->window->draw(e);
    }
}
void Game::pollEvents()
{
    // Event polling
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::updateMousePositions()
{
    /*
    @return void

    Updates mouse position relative to the window (Vector2i)
    */
   this->mousePosWindow = sf::Mouse::getPosition(*this->window);
   this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::update()
{
    this->pollEvents();

    this->updateMousePositions();

    this->updateEnemies();

}

void Game::render()
{   
    /*
        @return void

        Renders the game objects
        - clear old frame
        - render objects
        - display new frame in window
    */

    // Clear RGBAlpha
    this->window->clear();

    // Draw game objects
    this->renderEnemies();

    this->window->display();
}