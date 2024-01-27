#include <stdio.h>
#include "paddle.h"
#include "constants.h"
#include "textures.h"

#define PADDLE_SPEED 200

Paddle Paddle_init(int size, int skin) {
    return (Paddle) {
        .position = (Vector2) { GAMESCREENWIDTH / 2.0 - 32, GAMESCREENHEIGHT - 32 },
        size = size,
        skin = skin,
        .width = 64,
        .height = 16,
    };
}

void Paddle_draw(Paddle* paddle, Rectangle* squads) {
    DrawTextureRec(globalTextures.paddle, squads[paddle->size + 4 * paddle->skin], paddle->position, WHITE);
}

void Paddle_update(Paddle* paddle) {
    if (IsKeyDown(KEY_RIGHT)) {
        paddle->position.x = MIN(paddle->position.x + PADDLE_SPEED * GetFrameTime(), GAMESCREENWIDTH - paddle->width);
    }
    if (IsKeyDown(KEY_LEFT)) {
        paddle->position.x = MAX(paddle->position.x - PADDLE_SPEED * GetFrameTime(), 0);
    }
}
