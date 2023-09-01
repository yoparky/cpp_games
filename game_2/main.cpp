#include "Game.h"

int main()
{   
    // init random seed
    srand(static_cast<unsigned>(time(0)));

    // Init game object
    Game game;
    // game loop
    while (game.running())
    {
        game.update();
        game.render();
    }
    // End of Application
    return 0;
}