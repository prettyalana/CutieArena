#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Chom
{
    private:
    // How fast is each chom bomb type?
    const float BOUNCY_CHOM_SPEED = 40;
    const float CHARGER_CHOM_SPEED = 80;
    const float CUTE_CHOM_SPEED = 20;

    // How tough is each chom bomb type?
    const float CHARGER_CHOM_HEALTH = 5;
    const float BOUNCY_CHOM_HEALTH = 3;
    const float CUTE_CHOM_HEALTH = 1;

    // Make each chom bomb vary its speed slightly 
    const int MAX_VARRIANCE = 30;
    const int OFFSET = 101 - MAX_VARRIANCE;

    // Where is this chom bomb?
    Vector2f m_Position;

    // A sprite for the chom bomb
    Sprite m_Sprite;

    // How fast can this one run/crawl?
    float m_speed;

    // How much health does it have?
    float m_Health;

    // Is it still alive?
    bool m_Alive;

    // Public prototypes go here
    public:
    // Handle when laser hits a chom
    bool hit();

    // Find out if the chom is alive
    bool isAlive();

    // Spawn a new chom
    void spawn(float startX, float startY, int type, int seed);

    // Return a rectangle that is the position in the world
    FloatRect getPosition();

    // Get a copy of the sprite to draw 
    Sprite getSprite();

    // Update the chom eaxh frame 
    void update(float elapsedTime, Vector2f playerLocation);

};