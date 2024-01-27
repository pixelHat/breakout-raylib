#include "ball.h"
#include "textures.h"
#include "constants.h"
#include "utils.h"
#include "sounds.h"

Ball Ball_init(int skin) {
    return (Ball) {
        .position = { GAMESCREENWIDTH / 2.0 - 4, GAMESCREENHEIGHT - 42 },
        .skin = skin,
        .height = 8,
        .width = 8,
        .dx = randomInt(-200, 200),
        .dy = randomInt(-50, -60),
    };
}

void Ball_draw(Ball* ball, Rectangle* squads) {
    DrawTextureRec(globalTextures.paddle, squads[ball->skin], ball->position, WHITE);
}

void Ball_update(Ball* ball) {
    ball->position.x += ball->dx * GetFrameTime();
    ball->position.y += ball->dy * GetFrameTime();

    if (ball->position.x <= 0) {
        ball->position.x = 0;
        ball->dx = -ball->dx;
        PlaySound(globalSounds.wall_hit);
    }

    if (ball->position.x >= GAMESCREENWIDTH - ball->width) {
        ball->position.x = GAMESCREENWIDTH - ball->width;
        ball->dx = -ball->dx;
        PlaySound(globalSounds.wall_hit);
    }

    if (ball->position.y <= 0) {
        ball->position.y = 0;
        ball->dy = -ball->dy;
        PlaySound(globalSounds.wall_hit);
    }
}

bool Ball_collide(Ball ball, Rectangle target) {
    const Rectangle ball_rectangle = (Rectangle) {
        .x = ball.position.x,
        .y = ball.position.y,
        .width = ball.width,
        .height = ball.height
    };
    return CheckCollisionRecs(ball_rectangle, target);
}
