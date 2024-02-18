#include <stdio.h>
#include <string.h>
#include "state_victory.h"
#include "ball.h"
#include "bricks.h"
#include "paddle.h"
#include "utils.h"
#include "fonts.h"
#include "constants.h"

void RenderStateVictory(Game game, PlayState* state) {
    Paddle_draw(&state->paddle, state->quads);
    BallDraw(&state->ball, state->ball_quads);
    UtilsDrawScore(state->score);
    UtilsDrawHealth(state->lives, state->hearts_quads);

    for (int i = 0; i < state->bricks.size; i++) {
        Brick_draw(&state->bricks.bricks[i], state->bricks_quads);
    }

    char score_str[50];
    sprintf(score_str, "Score: %d complete!", state->score);
    UtilsDrawCenteredText(score_str, 32, GAMESCREENHEIGHT / 4.0);
    UtilsDrawCenteredText("Press Enter to serve!", 16, GAMESCREENHEIGHT / 2.0);
}

void UpdateStateVictory(Game game, PlayState* state) {
    Paddle_update(&state->paddle);
    state->ball.position.x = state->paddle.position.x + state->paddle.width / 2.0 - state->ball.width / 2.0;

    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        enterIntoServeState(state->lives, state->score, state->level);
    }
}
