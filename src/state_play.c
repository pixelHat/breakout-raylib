#include "raylib.h"
#include "fonts.h"
#include "constants.h"
#include "state_machine.h"
#include "textures.h"
#include "sounds.h"
#include "fonts.h"
#include "constants.h"
#include "ball.h"

#ifndef STATE_MENU_H
#define STATE_MENU_H

void RenderStatePlay(Game game, PlayState* state) {
    Paddle_draw(&state->paddle, state->quads);
    Ball_draw(&state->ball, state->ball_quads);
    if (state->isPaused) {
        Vector2 fontSize = MeasureTextEx(globalFonts.DEFAULT_FONT, "PAUSED", FONTLARGE, 1);
        DrawTextEx(
            globalFonts.DEFAULT_FONT,
            "PAUSED",
            (Vector2) {
                .x = GAMESCREENWIDTH / 2.0 - fontSize.x / 2.0,
                .y = GAMESCREENHEIGHT / 2.0 - fontSize.y / 2.0,
            },
            FONTLARGE,
            1,
            WHITE
        );
    }
}

void UpdateStatePlay(Game game, PlayState* state) {
    if (IsKeyPressed(KEY_SPACE)) {
        state->isPaused = !state->isPaused;
        PlaySound(globalSounds.pause);
    }

    Paddle_update(&state->paddle);
    Ball_update(&state->ball);

    const Rectangle paddle_rectangle = {
        .x = state->paddle.position.x,
        .y = state->paddle.position.y,
        .width = state->paddle.width,
        .height = state->paddle.height
    };
    if(Ball_collide(state->ball, paddle_rectangle)) {
        state->ball.dy = -state->ball.dy;
        PlaySound(globalSounds.paddle_hit);
    }
}
#endif
