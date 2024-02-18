#include "textures.h"

GlobalTextures globalTextures;

void LoadGameTextures() {
    globalTextures.paddle = LoadTexture("graphics/breakout.png");
    globalTextures.blocks = LoadTexture("graphics/blocks.png");
    globalTextures.hearts = LoadTexture("graphics/hearts.png");
    globalTextures.arrows = LoadTexture("graphics/arrows.png");
}

void UnloadGameTextures() {
    UnloadTexture(globalTextures.paddle);
    UnloadTexture(globalTextures.hearts);
    UnloadTexture(globalTextures.arrows);
    UnloadTexture(globalTextures.blocks);
}
