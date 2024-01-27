#include "raylib.h"
#include "fonts.h"
#include "constants.h"
#include "state_machine.h"
#include "textures.h"

#ifndef STATE_MENU_H
#define STATE_MENU_H

typedef struct {
    int selected;
} StateStatus;

void RenderStatePlay(Game game, PlayState* state) {
    DrawTextureRec(globalTextures.paddle, state->quads[0], (Vector2) { 0, 0 }, WHITE);
}

void UpdateStatePlay(Game game, PlayState* state) {
    if (IsKeyPressed(KEY_DOWN)) {
        // state->selected = (state->selected + 1) % 2;
    }
}
#endif
