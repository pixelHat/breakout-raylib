#include <stdio.h>
#include <string.h>
#include "state_victory.h"
#include "ball.h"
#include "bricks.h"
#include "paddle.h"
#include "utils.h"
#include "fonts.h"
#include "constants.h"

void draw_centered_text_2(const char* text, int size, int y) {
  const Vector2 measture = MeasureTextEx(globalFonts.DEFAULT_FONT, text, size, 1);
  const Vector2 position = {
    .x = GAMESCREENWIDTH / 2.0 - measture.x / 2.0,
    .y = y
  };
  DrawTextEx(globalFonts.DEFAULT_FONT, text, position, size, 1, WHITE);

}

void RenderStateVictory(Game game, PlayState* state) {
    Paddle_draw(&state->paddle, state->quads);
    BallDraw(&state->ball, state->ball_quads);
    UtilsDrawScore(state->score);
    UtilsDrawHealth(state->lives, state->hearts_quads);

    for (int i = 0; i < state->bricks.size; i++) {
        Brick_draw(&state->bricks.bricks[i], state->bricks_quads);
    }

    char score_str[5];
    sprintf(score_str, "%d", state->score);
    char text_score[50];
    strcpy(text_score, "Score: ");
    strcat(text_score, score_str);
    strcat(text_score, " complete!");
    draw_centered_text_2(text_score, 32, GAMESCREENHEIGHT / 4.0);
    draw_centered_text_2("Press Enter to serve!", 16, GAMESCREENHEIGHT / 2.0);
}

void UpdateStateVictory(Game game, PlayState* state) {
    Paddle_update(&state->paddle);
    state->ball.position.x = state->paddle.position.x + state->paddle.width / 2.0 - state->ball.width / 2.0;

    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        enterIntoServeState(state->lives, state->score, state->level);
    }
}
