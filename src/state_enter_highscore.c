#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include "state_enter_highscore.h"
#include "utils.h"
#include "fonts.h"
#include "constants.h"
#include "sounds.h"

void EnterHighscoreDrawChar(char* ch, Color color, int offset) {
    const Vector2 position = {
        GAMESCREENWIDTH / 2.0 - offset,
        GAMESCREENHEIGHT / 2.0
    };
    const char ch2 = ch[0];
    DrawTextEx(globalFonts.DEFAULT_FONT, &ch2, position, 32, 1, color);
}

void EnterHighscoreSaveScores(const Score* scores) {
    FILE* file = fopen("breakout.lst", "w+");
    if(file == NULL) {
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
        fprintf(file, "%s\n%d\n", scores[i].name, scores[i].score);
    }

    fclose(file);
}

void RenderStateEnterHighScore(Game game, EnterHighScoreState* state) {
    Color selected_color = {103, 255, 255, 255};
    char score_str[50];
    char score_text[50];
    strcpy(score_text, "Your score: ");
    sprintf(score_str, "%d", state->score);
    strcat(score_text, score_str);
    UtilsDrawCenteredText(score_text, 16, 30);
    EnterHighscoreDrawChar(&state->name[0], state->selected == 0 ? selected_color : WHITE, 28);
    EnterHighscoreDrawChar(&state->name[1], state->selected == 1 ? selected_color : WHITE, 6);
    EnterHighscoreDrawChar(&state->name[2], state->selected == 2 ? selected_color : WHITE, -20);
    UtilsDrawCenteredText("Press Enter to confirm!", 8, GAMESCREENHEIGHT - 18);
}

void UpdateStateEnterHighScore(Game game, EnterHighScoreState* state, GlobalState* globalState) {
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {

        Score next = globalState->scores[state->new_hiscore_index];
        Score prev;
        globalState->scores[state->new_hiscore_index] = (Score) { .name = state->name, .score = state->score};
        for (int i = state->new_hiscore_index + 1; i < 10; i++) {
            prev = globalState->scores[i];
            globalState->scores[i] = next;
            next = prev;
        }

        EnterHighscoreSaveScores(globalState->scores);

        enterIntoHighScoresState();
    }

    if (IsKeyPressed(KEY_RIGHT)) {
        state->selected = (state->selected + 1) % 3;
        PlaySound(globalSounds.select);
    }
    if (IsKeyPressed(KEY_LEFT)) {
        int value = (state->selected - 1);
        state->selected = value >= 0 ? value : 2;
        PlaySound(globalSounds.select);
    }
    if (IsKeyPressed(KEY_UP)) {
        char next_letter = (char) (state->name[state->selected] - 1);
        if (next_letter < 'A') next_letter = 'Z';
        state->name[state->selected] = next_letter;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        char next_letter = (char) ((state->name[state->selected] + 1) % ('Z' + 1));
        state->name[state->selected] = next_letter == 0 ? 'A' : next_letter;
    }
}
