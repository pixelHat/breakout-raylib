#include <stdio.h>
#include <string.h>
#include "state_machine.h"
#include "state_highscores.h"
#include "sounds.h"
#include "utils.h"
#include "constants.h"
#include "fonts.h"

void UpdateStateHighScores() {
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        PlaySound(globalSounds.wall_hit);
        enterIntoMenuState();
    }
}

void RenderStateHighScores(GlobalState* state) {
    UtilsDrawCenteredText("High Scores", 32, 20);

    for (int i = 0; i < 10; i++) {
        char* name = state->scores[i].name;
        int score = state->scores[i].score;

        char i_str[5];
        sprintf(i_str, "%d", i + 1);
        char line[50];
        strcpy(line, i_str);
        strcat(line, ". ");
        DrawTextEx(
            globalFonts.DEFAULT_FONT,
            line,
            (Vector2) { .x = GAMESCREENWIDTH / 4.0, .y = 60 + (i + 1) * 13 },
            16, 1, WHITE
        );

        DrawTextEx(
            globalFonts.DEFAULT_FONT,
            name,
            (Vector2) {.x = GAMESCREENWIDTH / 4.0 + 38, .y = 60 + (i + 1) * 13},
            16, 1, WHITE
        );


        char score_str[50];
        sprintf(score_str, "%d", score);
        DrawTextEx(
            globalFonts.DEFAULT_FONT,
            score_str,
            (Vector2) {.x = GAMESCREENWIDTH - 150, .y = 60 + (i + 1) * 13},
            16, 1, WHITE
        );
    }
}
