#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
    // Window creation, supplied w h pix (size), Title, Style (default is resizable window functions)
    // Bitwise operator to have multiple flags active
    sf::RenderWindow window(sf::VideoMode(640, 480), "My first sfml game", sf::Style::Titlebar | sf::Style::Close);
    // event - window is the listener here
    sf::Event ev;

    // Game loop
    while(window.isOpen())
    {      
        // Going by frames:
        // EVENT POLLING - while window gets an event, save it into ev to use in switch case
        while(window.pollEvent(ev))
        {
            // switch by the type of event that is polled
            switch (ev.type)
            {
                // close event triggered when the close button is pressed
            case sf::Event::Closed:
                window.close();
                break;
                // keyboard listener
            case sf::Event::KeyPressed:
                // escape to close
                if(ev.key.code == sf::Keyboard::Escape)
                    window.close();            
            }
        }
        // UPDATE

        // RENDER
        window.clear(); // clear old frame

        // draw game for new frame's state
        


        window.display(); // tell app window is done drawing
    }

    // End of Application
    return 0;
}