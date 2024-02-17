#include <stdlib.h>
#include "raylib.h"

#ifndef SOUNDS_H
#define SOUNDS_H

typedef struct {
    Sound pause;
    Sound wall_hit;
    Sound paddle_hit;
    Sound brick_hit_1;
    Sound brick_hit_2;
    Sound hurt;
    Sound victory;
    Sound high_score;
    Sound select;
} Sounds;

extern Sounds globalSounds;

void LoadGameSounds();
void UnloadGameSounds();

#endif
