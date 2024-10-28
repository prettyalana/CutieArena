#include <SFML/Graphics.hpp>
#include "player.h"
#include <iostream>
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
            // Handle the player quitting
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            // Handle WASD while playing
            if (state == State::PLAYING)
            {
                // Handle the pressing and releasing of WASD keys
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
                {
                    player.moveUp();
                }
                else
                {
                    player.stopUp();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
                {
                    player.moveDown();
                }
                else
                {
                    player.stopDown();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
                {
                    player.moveLeft();
                }
                else
                {
                    player.stopLeft();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
                {
                    player.moveRight();
                }
                else
                {
                    player.stopRight();
                }
            } // End WASD while playing
            // Handle the LEVELING up state
            if (state == State::LEVELING_UP)
            {
                // Update the player LEVELING UP
                if (event.key.code == Keyboard::Num1)
                {
                    state = State::PLAYING;
                }
                if (event.key.code == Keyboard::Num2)
                {
                    state = State::PLAYING;
                }
                if (event.key.code == Keyboard::Num3)
                {
                    state = State::PLAYING;
                }
                if (event.key.code == Keyboard::Num4)
                {
                    state = State::PLAYING;
                }
                if (event.key.code == Keyboard::Num5)
                {
                    state = State::PLAYING;
                }
                if (event.key.code == Keyboard::Num6)
                {
                    state = State::PLAYING;
                }
                if (state == State::PLAYING)
                {
                    // Prepare the level
                    arena.width = 500;
                    arena.height = 500;
                    arena.left = 0;
                    arena.top = 0;

                    // We will modify this line of code later
                    int tileSize = 50;

                    // Spawn the player in the middle of the arena
                    player.spawn(arena, resolution, tileSize);

                    // Reset clock so there isn't a frame jump
                    clock.restart();
                }
            } // End LEVELING UP
            // UPDATE THE FRAME 
            if (state == State::PLAYING)
            {
                // Update the delta time
                Time dt = clock.restart();

                // Update the total game time
                gameTimeTotal += dt;

                // Make a fraction of 1 from the delta time 
                float dtAsSeconds = dt.asSeconds();

                // Where is the mouse pointer 
                mouseScreenPosition = Mouse::getPosition();

                // COnvert mouse position to world based coordinates of mainView
                mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

                // Update the player
                player.update(dtAsSeconds, Mouse::getPosition());

                // Make a note of the players new position
                Vector2f playerPosition(player.getCenter());

                // Make the view center around the player
                mainView.setCenter(player.getCenter());
            } // End updating scene
            // Draw the scene
            if (state == State::PLAYING)
            {
                window.clear();

                // Set the mainView to be displayed in the window and draw everything related to it
                window.setView(mainView);

                // Draw the player 
                window.draw(player.getSprite());
                std::cout << "Drawing sprite at: (" << player.getCenter().x << ", " << player.getCenter().y << ")" << std::endl;
            }
            if (state == State::LEVELING_UP)
            {

            }
            if (state == State::PAUSED)
            {

            }
            if (state == State::GAME_OVER)
            {

            }
            window.display();
        } // End game loop
    }

    return 0;
}