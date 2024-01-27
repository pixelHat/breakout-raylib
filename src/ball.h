#include <stdlib.h>
#include "raylib.h"

#ifndef BALLS_H
#define BALLS_H

typedef struct {
  Vector2 position;
  int skin;
  int width;
  int height;
  int dx;
  int dy;
} Ball;

Ball Ball_init(int skin);
void Ball_update(Ball* ball);
void Ball_draw(Ball* ball, Rectangle* squads);
bool Ball_collide(Ball ball, Rectangle target);

#endif
