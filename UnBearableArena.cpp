#include <SFML/Graphics.hpp>
#include "player.h"

using namespace sf;
int main(){
    // The game will always be in one of the four states 
    enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING};

    // Start with GAME_OVER state
    State state = State::GAME_OVER;

    // Get the screen resolution and create an SFML window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x, resolution.y), "UnBEARable Arena", Style::Fullscreen);

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

    }


    return 0;
}