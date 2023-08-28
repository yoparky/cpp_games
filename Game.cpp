#include "Game.h"

// Private functions
void Game::initVariables()
{
    this->window = nullptr;
}
void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    // this->videoMode.getDesktopMode;
    this->window = new sf::RenderWindow(this->videoMode, "My first sfml game", sf::Style::Titlebar | sf::Style::Close);
}
// Constructors and destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
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

void Game::update()
{
    this->pollEvents();
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
    this->window->clear(sf::Color(255, 0, 0, 255));

    // Draw game objects
    this->window->display();
}