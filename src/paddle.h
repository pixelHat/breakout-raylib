#include <stdlib.h>
#include "raylib.h"

#ifndef PADDLE_H
#define PADDLE_H

typedef struct {
  Vector2 position;
  int size;
  int skin;
  int width;
  int height;
} Paddle;

Paddle Paddle_init(int size, int skin);
void Paddle_update(Paddle* paddle);
void Paddle_draw(Paddle* paddle, Rectangle* squad);

#endif
