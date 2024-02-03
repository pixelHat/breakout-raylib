#include "utils.h"
#include "textures.h"

Rectangle* generateQuads(Texture texture, int tile_width, int tile_height) {
    int sheet_width  = texture.width / tile_width;
    int sheet_height = texture.height / tile_height;
    int sheet_counter = 0;
    Rectangle* spritesheet = (Rectangle*) malloc(sizeof(Rectangle) * sheet_width * sheet_height);
    for (int y = 0; y < sheet_height; y++) {
        for (int x = 0; x < sheet_width; x++) {
            spritesheet[sheet_counter] = (Rectangle) { x * tile_width, y * tile_height, tile_width, tile_height };
            sheet_counter++;
        }
    }
    return spritesheet;
}

Rectangle* generateQuadsHearts() {
    return generateQuads(globalTextures.hearts, 10, 9);
}

Rectangle* generateQuadsBricks() {
    return generateQuads(globalTextures.paddle, 32, 16);
}

Rectangle* generateQuadsPaddles() {
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

Rectangle* generateQuadsBalls() {
    float x = 96;
    float y = 48;
    int counter = 0;
    Rectangle* quads = (Rectangle*) malloc(sizeof(Rectangle) * 5);
    for(int i = 0; i < 3; i++) {
        quads[counter++] = (Rectangle) { x, y, 8, 8 };
        x += 8;
    }

    x = 96;
    y = 56;

    for(int i = 0; i < 2; i++) {
        quads[counter++] = (Rectangle) { x, y, 8, 8 };
        x += 8;
    }
    return quads;
}

int randomInt(int min, int max) {
  return min + rand() % (max - min + 1);
}
