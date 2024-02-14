#include "raylib.h"
#include "paddle.h"
#include "ball.h"
#include "bricks.h"

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

typedef enum {
    STATE_MENU,
    STATE_PLAY,
    STATE_SERVE,
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
    int score;
    int lives;
    Rectangle* hearts_quads;
} PlayState;

typedef struct {
  int score;
} GameOverState;

void DrawTitle();
void DrawPlay();

void Update();
void Render();
void enterIntoMenuStateState();
void enterIntoPlayState();
void enterIntoServeState(int health, int score);
void enterIntoGameOverState(int score);
#endif
