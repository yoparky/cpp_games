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
    this->mouseHeld = false;
    this->health = 10;
    this->endGame = false;
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

void Game::initFonts()
{
    if(this->font.loadFromFile("./fonts/Roboto-Bold.ttf")){
        std::cout << "Error: GAME::initFonts - Load font error" << "\n";
    }
}
void Game:: initText()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(12);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");
}
// Constructors and destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initText();
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
const bool Game::getEndGame() const
{
    return this->endGame;
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
    // Moving and updating enemies
    for (int i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false;

        this->enemies[i].move(0.f, 5.f);

        if (this->enemies[i].getPosition().y > this->window->getSize().y) 
        {
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1;
            --i;
        }
    }

    // check if clicked
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (this->mouseHeld == false)
        {
            this->mouseHeld = true;
            bool deleted = false;
            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
            {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
                {
                    // Delete the enemy
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);

                    // Gain points
                    this->points += 1;
                }
            }
        }
    } else {
        this->mouseHeld = false;
    }
}
void Game::renderEnemies(sf::RenderTarget& target)
{
    for(auto &e : this->enemies)
    {
        target.draw(e);
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
    if (!this->endGame) 
    {
        this->updateMousePositions();
        this->updateText();
        this->updateEnemies();
    }
    if(this-> health <= 0)
        this->endGame = true;

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
    this->renderEnemies(*this->window);
    this->renderText(*this->window);

    this->window->display();
}

void Game::renderText(sf::RenderTarget& target)
{
    target.draw(this->uiText);
}
void Game::updateText()
{
    std::stringstream ss;
    ss << "Points: " << this->points;
    ss << "\n" << "Health: " << this->health;
    this->uiText.setString(ss.str());
}