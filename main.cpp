#include <iostream>
#include "Game.h"

int main()
{   
    // seed srand
    std::srand(static_cast<unsigned>(time(nullptr)));
    // Init game engine
    Game game;

    // Game loop
    while(game.running() && !game.getEndGame())
    {
        // Going by frames:
        // EVENT POLLING - while window gets an event, save it into ev to use in switch case
        
        // UPDATE
        game.update();
        // RENDER
        game.render();
    }

    // End of Application
    return 0;
}