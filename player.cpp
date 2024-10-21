#include "player.h"

Player::Player()
    : m_Speed(START_SPEED),
      m_Health(START_HEALTH),
      m_MaxHealth(START_HEALTH),
      m_Texture(),
      m_Sprite()
{
    // Associate a texture with the sprite 
    // !!Watch this space!!
    m_Texture.loadFromFile("/Users/alana/alana-fullstackdev/CutieArena/graphics/Bearsprites copy.png");
    m_Sprite.setTexture(m_Texture);

    // Set the origin of the sprite to the center for smooth rotation
    m_Sprite.setOrigin(25, 25);

}

// spawn function
    void Player::spawn(IntRect arena, Vector2f resolution, int tileSize)
    {
        // Place the player in the middle of the arena 
        m_Position.x = arena.width / 2;
        m_Position.y = arena.height / 2;

        // Copy the details of the arena to the player's m_Arena
        m_Arena.left = arena.left;
        m_Arena.width = arena.width;
        m_Arena.top = arena.top;
        m_Arena.height = arena.height;

        // Remember how big the tiles are in this arena 
        m_TileSize = tileSize;

        // Store the resolution for future use
        m_Resolution.x = resolution.x;
        m_Resolution.y = resolution.y;

    }

    void Player::resetPlayerStats()
    {
        m_Speed = START_SPEED;
        m_Health = START_HEALTH;
        m_MaxHealth = START_HEALTH;
    }

    