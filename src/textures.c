#include "textures.h"

GlobalTextures globalTextures;

void LoadGameTextures() {
    globalTextures.paddle = LoadTexture("graphics/breakout.png");
}

void UnloadGameTextures() {
    UnloadTexture(globalTextures.paddle);
}
