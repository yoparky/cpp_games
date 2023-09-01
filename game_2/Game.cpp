#include "Game.h"

void Game::initVariables()
{
    this->endGame = false;
}
void Game::initWindow()
{
    this->videoMode = sf::VideoMode(800, 600);
    this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
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

// accessors
const bool Game::running() const
{
    return this->window->isOpen();
}
// modifiers

// functions
void Game::pollEvents()
{
    while(this->window->pollEvent(this->sfmlEvent))
    {
        switch (this->sfmlEvent.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
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
    // clear
    this->window->clear();
    // render
    this->player.render(this->window);
    
    // display
    this->window->display();
}
