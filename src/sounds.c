#include "sounds.h"

Sounds globalSounds = { };

void LoadGameSounds() {
    InitAudioDevice();
    globalSounds.pause = LoadSound("sounds/pause.wav");
    globalSounds.wall_hit = LoadSound("sounds/wall_hit.wav");
    globalSounds.paddle_hit = LoadSound("sounds/paddle_hit.wav");
    globalSounds.brick_hit_1 = LoadSound("sounds/brick-hit-1.wav");
    globalSounds.brick_hit_2 = LoadSound("sounds/brick-hit-2.wav");
    globalSounds.hurt = LoadSound("sounds/hurt.wav");
    globalSounds.victory = LoadSound("sounds/victory.wav");
    globalSounds.high_score = LoadSound("sounds/high_score.wav");
    globalSounds.select = LoadSound("sounds/select.wav");
}

void UnloadGameSounds() {
    UnloadSound(globalSounds.pause);
    UnloadSound(globalSounds.wall_hit);
    UnloadSound(globalSounds.paddle_hit);
    UnloadSound(globalSounds.brick_hit_1);
    UnloadSound(globalSounds.brick_hit_2);
    UnloadSound(globalSounds.hurt);
    UnloadSound(globalSounds.victory);
    UnloadSound(globalSounds.high_score);
    UnloadSound(globalSounds.select);
}
