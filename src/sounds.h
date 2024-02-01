#include <stdlib.h>
#include "raylib.h"

#ifndef SOUNDS_H
#define SOUNDS_H

typedef struct {
    Sound pause;
    Sound wall_hit;
    Sound paddle_hit;
    Sound brick_hit;
} Sounds;

extern Sounds globalSounds;

void LoadGameSounds();
void UnloadGameSounds();

#endif
