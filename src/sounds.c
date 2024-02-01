#include "sounds.h"

Sounds globalSounds = { };

void LoadGameSounds() {
    InitAudioDevice();
    globalSounds.pause = LoadSound("sounds/pause.wav");
    globalSounds.wall_hit = LoadSound("sounds/wall_hit.wav");
    globalSounds.paddle_hit = LoadSound("sounds/paddle_hit.wav");
    globalSounds.brick_hit = LoadSound("sounds/brick-hit-2.wav");
}

void UnloadGameSounds() {
    UnloadSound(globalSounds.pause);
    UnloadSound(globalSounds.wall_hit);
    UnloadSound(globalSounds.paddle_hit);
    UnloadSound(globalSounds.brick_hit);
}
