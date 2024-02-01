#include "raylib.h"

#ifndef BRICKS_H
#define BRICKS_H

typedef struct {
  int tier;
  int color;
  Vector2 position;
  int width;
  int height;
  bool in_play;
} Brick;

typedef struct {
  Brick* bricks;
  int size;
} Bricks;

void Brick_draw(Brick* brick, Rectangle* squads);
void Brick_hit(Brick* brick);
Bricks create_map(int level);

#endif
