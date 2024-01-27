#include <stdlib.h>
#include "raylib.h"
#include "fonts.h"

Fonts globalFonts = { NULL };

void LoadGameFonts() {
    Font font = LoadFont("fonts/font.ttf");
    globalFonts.DEFAULT_FONT = font;
}

void UnloadGameFonts() {
    UnloadFont(globalFonts.DEFAULT_FONT);
}
