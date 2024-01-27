#include <stdlib.h>
#include "raylib.h"
#include "fonts.h"

Fonts globalFonts = { };

void LoadGameFonts() {
    Font font = LoadFont("fonts/font.ttf");
    globalFonts.DEFAULT_FONT = font;
}

void UnloadGameFonts() {
    UnloadFont(globalFonts.DEFAULT_FONT);
}
