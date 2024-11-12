#pragma once
#include <SFML/Graphics.hpp>
#include "Chom.h"
using namespace sf;
int createBackground(VertexArray &rVA, IntRect arena);
Chom *createHorde(int numChoms, IntRect arena);