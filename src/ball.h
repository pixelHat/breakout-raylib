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

Ball BallInit(int skin);
void BallUpdate(Ball* ball);
void BallDraw(Ball* ball, Rectangle* squads);
bool BallCollide(Ball ball, Rectangle target);

#endif
