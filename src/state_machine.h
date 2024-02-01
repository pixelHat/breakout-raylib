#include "raylib.h"
#include "paddle.h"
#include "ball.h"
#include "bricks.h"

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

typedef enum {
    STATE_MENU,
    STATE_PLAY,
    STATE_GAME_OVER
} GameState;

typedef struct {
    GameState currentState;

} Game;

typedef struct {
  int selected;
} MenuState;

typedef struct {
    Rectangle* quads;
    Paddle paddle;
    bool isPaused;
    Ball ball;
    Rectangle* ball_quads;
    Rectangle* bricks_quads;
    Bricks bricks;
} PlayState;

void DrawTitle();
void DrawPlay();

void Update();
void Render();
void enterIntoPlayState();
void exitMenuState();

#endif
