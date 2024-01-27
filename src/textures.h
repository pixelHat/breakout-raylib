#include "raylib.h"
#include <stdlib.h>

#ifndef TEXTURES_H
#define TEXTURES_H


typedef struct {
    Texture paddle;
} GlobalTextures;

extern GlobalTextures globalTextures;

void LoadGameTextures();
void UnloadGameTextures();

#endif
