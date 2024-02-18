#include <stdlib.h>
#include "raylib.h"

#ifndef UTILS_H
#define UTILS_H

typedef struct {
    char* name;
    int score;
} Score;

Rectangle* generateQuads(Texture texture, int tile_width, int tile_height);
Rectangle* generateQuadsHearts();
Rectangle* generateQuadsBricks();
Rectangle* generateQuadsPaddles();
Rectangle* generateQuadsBalls();
Rectangle* generateQuadsArrows();
int randomInt(int min, int max);

void UtilsDrawScore(int score);
void UtilsDrawHealth(int health, Rectangle* quads);
void UtilsDrawCenteredText(const char* text, int size, int y);

Score* UtilsLoadScore();

#endif
