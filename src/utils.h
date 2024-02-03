#include <stdlib.h>
#include "raylib.h"

#ifndef UTILS_H
#define UTILS_H
Rectangle* generateQuads(Texture texture, int tile_width, int tile_height);
Rectangle* generateQuadsHearts();
Rectangle* generateQuadsBricks();
Rectangle* generateQuadsPaddles();
Rectangle* generateQuadsBalls();
int randomInt(int min, int max);

#endif
