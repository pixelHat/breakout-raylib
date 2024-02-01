#include <stdlib.h>
#include <stdio.h>
#include "bricks.h"
#include "textures.h"
#include "utils.h"

void Brick_draw(Brick* brick, Rectangle* squads) {
  if (brick->in_play) {
    DrawTextureRec(globalTextures.paddle, squads[(brick->color) * 4], brick->position, WHITE);
  }
}

void Brick_hit(Brick* brick) {
  // TODO: musci
  brick->in_play = false;
}

Bricks create_map(int level) {
  int number_of_rows = randomInt(1, 5);
  int number_of_cols = randomInt(7, 13);
  Bricks bricks = (Bricks) {
    .bricks = (Brick*) malloc(sizeof(Brick) * number_of_rows * number_of_cols),
    .size = 0
  };

  for (int y = 0; y < number_of_rows; y++) {
    for (int x = 0; x < number_of_cols; x++) {
      bricks.bricks[bricks.size++] = (Brick) {
        .position = (Vector2) {
          x * 32 + 8 + (13 - number_of_cols) * 16,
          (y + 1) * 16
        },
        .width = 32,
        .height = 16,
        .tier = 0,
        .color = 0,
        .in_play = true
      };
    }
  }
  return bricks;
}
