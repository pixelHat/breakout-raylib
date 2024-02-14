#include <math.h>
#include <stdio.h>
#include "state_play.h"
#include "textures.h"
#include "paddle.h"
#include "paddle.h"
#include "constants.h"
#include "fonts.h"
#include "state_play.h"

void RenderStateServe(Game game, PlayState* state) {
    Paddle_draw(&state->paddle, state->quads);
    Ball_draw(&state->ball, state->ball_quads);
    draw_score(state->score);
    draw_health(state->lives, state->hearts_quads);

    for (int i = 0; i < state->bricks.size; i++) {
        Brick_draw(&state->bricks.bricks[i], state->bricks_quads);
    }
}

void UpdateStateServe(Game game, PlayState* state) {
    Paddle_update(&state->paddle);
    state->ball.position.x = state->paddle.position.x + state->paddle.width / 2.0 - state->ball.width / 2.0;

    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        enterIntoPlayState();
    }
}
