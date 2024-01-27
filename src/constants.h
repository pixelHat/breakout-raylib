#include "raylib.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))
#define CLAMP(value, min, max) ((value) < (min) ? (min) : ((value) > (max) ? (max) : (value)))

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720
#define GAMESCREENWIDTH 432
#define GAMESCREENHEIGHT 243
#define FONTSMALL 8
#define FONTMEDIUM 16
#define FONTLARGE 32

#endif
