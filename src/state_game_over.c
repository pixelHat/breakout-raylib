#include "stdio.h"
#include "string.h"
#include "state_game_over.h"
#include "raylib.h"
#include "fonts.h"
#include "constants.h"

void draw_centered_text(const char* text, int size, int y) {
  const Vector2 measture = MeasureTextEx(globalFonts.DEFAULT_FONT, text, size, 1);
  const Vector2 position = {
    .x = GAMESCREENWIDTH / 2.0 - measture.x / 2.0,
    .y = y
  };
  DrawTextEx(globalFonts.DEFAULT_FONT, text, position, size, 1, WHITE);

}

void RenderStateGameOver(Game game, GameOverState* state) {
  draw_centered_text("GAME OVER", 32, GAMESCREENHEIGHT / 3.0);

  char score_str[5];
  sprintf(score_str, "%d", state->score);
  char text_score[18];
  sprintf(text_score, "Your score: %s", score_str);
  draw_centered_text(text_score, 16, GAMESCREENHEIGHT / 2.0);

  draw_centered_text("Press Enter!", 16, GAMESCREENHEIGHT - GAMESCREENHEIGHT / 4.0);
}

void UpdateStateGameOver(Game game, GameOverState* state) {
  if (IsKeyPressed(KEY_ENTER)) {
    enterIntoMenuStateState();
  }
}
