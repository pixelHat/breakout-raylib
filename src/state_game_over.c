#include "stdio.h"
#include "string.h"
#include "state_game_over.h"
#include "raylib.h"
#include "fonts.h"
#include "constants.h"
#include "sounds.h"

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

    char score_str[50];
    sprintf(score_str, "%d", state->score);
    char text_score[12+50];
    sprintf(text_score, "Your score: %s", score_str);
    draw_centered_text(text_score, 16, GAMESCREENHEIGHT / 2.0);

    draw_centered_text("Press Enter!", 16, GAMESCREENHEIGHT - GAMESCREENHEIGHT / 4.0);
}

void UpdateStateGameOver(Game game, GameOverState* state, GlobalState* globalState) {
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        bool high_score = false;
        int highscore_index = 11;
        for(int i = 9; i >= 0; i--) {
            int score = globalState->scores[i].score;
            if(state->score > score) {
                high_score = true;
                highscore_index = i;
            }
        }

        if (high_score) {
            PlaySound(globalSounds.high_score);
            enterIntoEnterHighScoreState(globalState->scores, state->score, highscore_index);
        } else {
            enterIntoMenuState();
        }
    }
}
