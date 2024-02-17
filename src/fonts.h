#include "raylib.h"
#include <stdlib.h>

#ifndef FONT_H
#define FONT_H

typedef struct Fonts {
    Font DEFAULT_FONT;
} Fonts;

extern Fonts globalFonts;

void LoadGameFonts();
void UnloadGameFonts();
#endif
