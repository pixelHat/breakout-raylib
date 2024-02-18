#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "textures.h"
#include "fonts.h"
#include "constants.h"

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
    Rectangle* quads = (Rectangle*) malloc(sizeof(Rectangle) * 16);
    for(int i = 0; i < 4; i++) {
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

Rectangle* generateQuadsArrows() {
    return generateQuads(globalTextures.arrows, 24, 24);
}

int randomInt(int min, int max) {
  return min + rand() % (max - min + 1);
}

void UtilsDrawScore(int score) {
    char score_str[5];
    sprintf(score_str, "%d", score);
    Vector2 measure_score_text = MeasureTextEx(globalFonts.DEFAULT_FONT, "SCORE", 8, 1);
    DrawTextEx(globalFonts.DEFAULT_FONT, "SCORE", (Vector2) { GAMESCREENWIDTH - 60, 5 }, 8, 1, WHITE);
    DrawTextEx(globalFonts.DEFAULT_FONT, score_str, (Vector2) { GAMESCREENWIDTH - 50 + measure_score_text.x, 5 }, 8, 1, WHITE);
}

void UtilsDrawHealth(int health, Rectangle* squads) {
    int health_x = GAMESCREENWIDTH - 100;

    for(int i = 0; i < health; i++) {
        DrawTextureRec(globalTextures.hearts, squads[0], (Vector2) { health_x, 4 }, WHITE);
        health_x += 11;
    }

    for (int i = 0; i < 3 - health; i++) {
        DrawTextureRec(globalTextures.hearts, squads[1], (Vector2) { health_x, 4 }, WHITE);
        health_x += 11;
    }
}

Score* UtilsLoadScore() {
    FILE* file = fopen("breakout.lst", "a+");
    if(file == NULL) {
        exit(1);
    }

    bool name = true;
    char* currentName = NULL;
    int counter = 0;

    Score* scores = (Score*) malloc(sizeof(Score) * 10);

    for(int i = 0; i < 10; i++) {
        scores[i].name = "---";
        scores[i].score = 0;
    }

    char line[100];
    while(fgets(line, 100, file) != NULL) {
        if(name) {
            currentName = strtok(line, "\n");
            scores[counter].name = (char*) malloc(sizeof(char) * (strlen(currentName) + 1));
            strcpy(scores[counter].name, currentName);
        } else {
            scores[counter].score = atoi(strtok(line, "\n"));
            counter++;
        }
        name = !name;
    }

    fclose(file);
    return scores;
}

void UtilsDrawCenteredText(const char* text, int size, int y) {
    const Vector2 measture = MeasureTextEx(globalFonts.DEFAULT_FONT, text, size, 1);
    const Vector2 position = {
        .x = GAMESCREENWIDTH / 2.0 - measture.x / 2.0,
        .y = y
    };
    DrawTextEx(globalFonts.DEFAULT_FONT, text, position, size, 1, WHITE);
}
