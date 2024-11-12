#include "Chom.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void Chom::spawn(float startX, float startY, int type, int seed)
{
    switch (type)
    {
    case 0:
        // Bouncy
        m_Sprite = Sprite(TextureHolder::GetTexture("/Users/alana/alana-fullstackdev/UnBearableArena/graphics/bouncy_chomb.png"));
        m_Speed = BOUNCY_CHOM_SPEED;
        m_Health = BOUNCY_CHOM_HEALTH;
        break;
    case 1:
        // Charger
        m_Sprite = Sprite(TextureHolder::GetTexture("/Users/alana/alana-fullstackdev/UnBearableArena/graphics/charger_chomb.png"));
        m_Speed = CHARGER_CHOM_SPEED;
        m_Health = CHARGER_CHOM_HEALTH;
        break;
    case 2:
        // Cute
        m_Sprite = Sprite(TextureHolder::GetTexture("/Users/alana/alana-fullstackdev/UnBearableArena/graphics/cute_chomb.png"));
            m_Speed = CUTE_CHOM_SPEED;
        m_Health = CUTE_CHOM_HEALTH;
        break;
    }
    // Modify the speed to make the chom unique 
    // Every chom is unique. Create a speed modifier
    srand((int)time(0) * seed);

    // Somewhere between 80 and 100
    float modifier = (rand() % (MAX_VARRIANCE)) + OFFSET;

    // Express this as a fraction of 1
    modifier /= 100; // Now equals between 0.7 and 1
    m_Speed *= modifier;

    // Initialize its location
    m_Position.x = startX;
    m_Position.y = startY;

    // Set its origin to its center
    m_Sprite.setOrigin(25, 25);

    // Set its position
    m_Sprite.setPosition(m_Position);

}

bool Chom::hit()
{
    m_Health--;
    if (m_Health < 0)
    {
        // dead
        m_Alive = false;
        return true;
    }
    // injured but not dead yet
    return false;
}

// getter functions
bool Chom::isAlive()
{
    return m_Alive;
}

FloatRect Chom::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

Sprite Chom::getSprite()
{
    return m_Sprite;
}

void Chom::update(float elapsedTime, Vector2f playerLocation)
{
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;

    // Update the chom position variables 
    if (playerX > m_Position.x)
    {
        m_Position.x = m_Position.x + m_Speed * elapsedTime;
    }
    if (playerY > m_Position.y)
    {
        m_Position.y = m_Position.y + m_Speed * elapsedTime;
    }

    if (playerX < m_Position.x)
    {
        m_Position.x = m_Position.x - m_Speed * elapsedTime;
    }
    if (playerY < m_Position.y)
    {
        m_Position.y = m_Position.y - m_Speed * elapsedTime;
    }
    // Move the sprite 
    m_Sprite.setPosition(m_Position);
    // Face the sprite in the correct direction
    float angle = (atan2(playerY - m_Position.y, playerX - m_Position.x) * 180) / 3.141;
    m_Sprite.setRotation(angle);
}