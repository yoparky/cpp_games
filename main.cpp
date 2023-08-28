#include <iostream>
#include "Game.h"

int main()
{
    // Init game engine
    Game game;

    // Game loop
    while(game.running())
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