#include <SFML/Graphics.hpp>
#include "player.h"

using namespace sf;
int main()
{
    // The game will always be in one of the four states
    enum class State
    {
        PAUSED,
        LEVELING_UP,
        GAME_OVER,
        PLAYING
    };

    // Start with GAME_OVER state
    State state = State::GAME_OVER;

    // Get the screen resolution and create an SFML window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x, resolution.y), "UnBEARable Arena");

    // Create a SFML View for the main function
    View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

    // Here is our clock for timing everything
    Clock clock;

    // How long has the PLAYING state been active?
    Time gameTimeTotal;

    // Where is the mouse in relation to the coordinates
    Vector2f mouseWorldPosition;

    // Where is the mouse in relation to screen coordinates
    Vector2i mouseScreenPosition;

    // Create an instance of the Player class
    Player player;

    // The boundaries of the arena
    IntRect arena;

    // The main game loop
    while (window.isOpen())
    {
        // Handle input

        // Handle events by polling
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                // Quit the game when the window is closed
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            if (event.type == Event::KeyPressed)
            {
                // Pause a game while playing
                if (event.key.code == Keyboard::Return && state == State::PLAYING)
                {
                    state = State::PAUSED;
                }

                // Restart while paused
                else if (event.key.code == Keyboard::Return && state == State::PAUSED)
                {
                    state = State::PLAYING;
                    // Reset the clock so there isn't a frame jump
                    clock.restart();
                }
                // Start a new game while in GAME_OVER state
                else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
                {
                    state = State::LEVELING_UP;
                }
                if (state == State::PLAYING)
                {
                }
            } // End event polling
        } // End game loop
    }

    return 0;
}