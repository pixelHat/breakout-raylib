#include "raylib.h"
#include "fonts.h"
#include "constants.h"
#include "state_machine.h"

#ifndef STATE_MENU_H
#define STATE_MENU_H

typedef struct {
    int selected;
} StateStatus;

void RenderStateMenu(Game game, MenuState* state) {
    const Color selected_color = {103, 255, 255, 255};
    const Color unselected_color = {255, 255, 255, 255};
    char* text = "BREAKOUT";
    int size = 32;
    Vector2 measture_text = MeasureTextEx(globalFonts.DEFAULT_FONT, text, size, 1);
    Vector2 title_pos = {GAMESCREENWIDTH / 2.0 - measture_text.x / 2.0, 70};
    DrawTextEx(globalFonts.DEFAULT_FONT, text, title_pos, size, 1, LIGHTGRAY);

    text = "START";
    size = 16;
    measture_text = MeasureTextEx(globalFonts.DEFAULT_FONT, text, size, 1);
    title_pos.x = GAMESCREENWIDTH / 2.0 - measture_text.x / 2.0;
    title_pos.y = GAMESCREENHEIGHT / 2 + 70;
    Color color = (state->selected == 0)? selected_color : unselected_color;
    DrawTextEx(globalFonts.DEFAULT_FONT, text, title_pos, size, 1, color);

    text = "HIGH SCORES";
    size = 16;
    measture_text = MeasureTextEx(globalFonts.DEFAULT_FONT ,text, size, 1);
    title_pos.x = GAMESCREENWIDTH / 2.0 - measture_text.x / 2.0;
    title_pos.y = GAMESCREENHEIGHT / 2 + 90;
    color = (state->selected == 1)? selected_color : unselected_color;
    DrawTextEx(globalFonts.DEFAULT_FONT, text, title_pos, size, 1, color);
}

void UpdateStateMenu(Game game, MenuState* state) {
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        enterIntoPlayState(3, 0);
    }
    if (IsKeyPressed(KEY_DOWN)) {
        state->selected = (state->selected + 1) % 2;
    }
    if (IsKeyPressed(KEY_UP)) {
        state->selected = (state->selected - 1) >= 0 ? state->selected - 1 : 1;
    }
}
#endif
