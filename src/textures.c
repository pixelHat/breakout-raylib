#include "textures.h"

GlobalTextures globalTextures;

void LoadGameTextures() {
    globalTextures.paddle = LoadTexture("graphics/breakout.png");
    globalTextures.hearts = LoadTexture("graphics/hearts.png");
}

void UnloadGameTextures() {
    UnloadTexture(globalTextures.paddle);
    UnloadTexture(globalTextures.hearts);
}
