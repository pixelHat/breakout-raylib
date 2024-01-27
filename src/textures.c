#include "textures.h"

GlobalTextures globalTextures;

void LoadGameTextures() {
    globalTextures.paddle = LoadTexture("graphics/blocks.png");
}

void UnloadGameTextures() {
    UnloadTexture(globalTextures.paddle);
}
