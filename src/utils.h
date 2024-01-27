#include <stdlib.h>
#include "raylib.h"

#ifndef UTILS_H
#define UTILS_H

Rectangle* generateQuadsPaddles(void) {
    float x = 0;
    float y = 64;
    int counter = 0;
    Rectangle* quads = (Rectangle*) malloc(sizeof(Rectangle) * 12);
    for(int i = 0; i < 3; i++) {
        quads[counter++] = (Rectangle) { x, y, 32, 16 };
        quads[counter++] = (Rectangle) { x + 32, y, 64, 16 };
        quads[counter++] = (Rectangle) { x + 96, y, 96, 16 };
        quads[counter++] = (Rectangle) { x, y + 16, 128, 16 };
        x = 0;
        y = y + 32;
    }
    return quads;
}

#endif
