#include <math.h>
#include <stdio.h>
#include "raylib.h"
#include "state_play.h"
#include "fonts.h"
#include "constants.h"
#include "state_machine.h"
#include "textures.h"
#include "sounds.h"
#include "fonts.h"
#include "constants.h"
#include "ball.h"
#include "bricks.h"
#include "utils.h"

#ifndef STATE_MENU_H
#define STATE_MENU_H

void RenderStatePlay(Game game, PlayState* state) {
    Paddle_draw(&state->paddle, state->quads);
    BallDraw(&state->ball, state->ball_quads);
    UtilsDrawScore(state->score);
    UtilsDrawHealth(state->lives, state->hearts_quads);

    for (int i = 0; i < state->bricks.size; i++) {
        Brick_draw(&state->bricks.bricks[i], state->bricks_quads);
    }

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
    BallUpdate(&state->ball);

    for (int i = 0; i < state->bricks.size; i++) {
        Brick* b = &(state->bricks.bricks[i]);
        Rectangle rec = (Rectangle) {
            .x = b->position.x,
            .y = b->position.y,
            .width = b->width,
            .height = b->height
        };

        if (b->in_play && BallCollide(state->ball, rec)) {
            if (state->ball.position.x + 2 < b->position.x && state->ball.dx > 0) {
                state->ball.dx = -state->ball.dx;
                state->ball.position.x = b->position.x - 8;
            } else if (state->ball.position.x + 6 > b->position.x + b->width && state->ball.dx < 0) {
                state->ball.dx = -state->ball.dx;
                state->ball.position.x = b->position.x + 32;
            } else if (state->ball.position.y < b->position.y) {
                state->ball.dy = -state->ball.dy;
                state->ball.position.y = b->position.y - 8;
            } else {
                state->ball.dy = -state->ball.dy;
                state->ball.position.y = b->position.y + 16;
            }
            state->ball.dy = state->ball.dy * 1.02;
            state->score += (b->tier * 200 + (b->color + 1) * 25);
            Brick_hit(b);
            if (PlayStateCheckVictory(state)) {
                PlaySound(globalSounds.victory);
                enterIntoVictoryState(state->lives, state->score, state->level + 1);
            }
        }

    }

    const Rectangle paddle_rectangle = {
        .x = state->paddle.position.x,
        .y = state->paddle.position.y,
        .width = state->paddle.width,
        .height = state->paddle.height
    };
    if(BallCollide(state->ball, paddle_rectangle)) {
        state->ball.position.y -= 8;
        state->ball.dy = -state->ball.dy;
        if (state->ball.position.x < state->paddle.position.x + state->paddle.width / 2 && state->paddle.dx < 0) {
            state->ball.dx = -50 + -(8 * (state->paddle.position.x + state->paddle.width / 2 - state->ball.position.x));
        } else if (state->ball.position.x > state->paddle.position.x + state->paddle.width / 2 && state->paddle.dx > 0) {
            state->ball.dx = 50 + (8 * fabs(state->paddle.position.x + state->paddle.width / 2 - state->ball.position.x));
        }
        PlaySound(globalSounds.paddle_hit);

    }

    if (state->ball.position.y >= GAMESCREENHEIGHT) {
        state->lives--;
        PlaySound(globalSounds.hurt);
        if (state->lives == 0) {
            enterIntoGameOverState(state->score);
        } else {
            enterIntoServeState(state->lives, state->score, state->level + 1);
        }
    }

}

bool PlayStateCheckVictory(PlayState* state) {
    for (int i = 0; i < state->bricks.size; i++) {
        if (state->bricks.bricks[i].in_play) {
            return false;
        }
    }
    return true;
}
#endif
