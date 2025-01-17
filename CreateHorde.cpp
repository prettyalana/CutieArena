#include "UnBearableArena.h"
#include "Chom.h"
Chom *createHorde(int numChoms, IntRect arena)
{
    Chom *choms = new Chom[numChoms];
    int maxY = arena.height - 20;
    int minY = arena.top + 20;
    int maxX = arena.width - 20;
    int minX = arena.left + 20;
    for (int i = 0; i < numChoms; i++)
    {
        // Which side should the chom spawn
        srand((int)time(0) * i);
        int side = (rand() % 4);
        float x, y;
        switch (side)
        {
        case 0:
            // left
            x = minX;
            y = (rand() % maxY) + minY;
            break;
        case 1:
            // right
            x = maxX;
            y = (rand() % maxY) + minY;
            break;
        case 2:
            // top
            x = (rand() % maxX) + minX;
            y = minY;
            break;
        case 3:
            // bottom
            x = (rand() % maxX) + minX;
            y = maxY;
            break;
        }

        // bouncy, charger or cute 
        srand((int)time(0) * i * 2);
        int type = (rand() % 3);

        // spawn the new chom into the array
        choms[i].spawn(x, y, type, i);

    }

    return choms;
}