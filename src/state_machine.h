#include "raylib.h"
#include "paddle.h"
#include "ball.h"
#include "bricks.h"
#include "utils.h"

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

typedef enum {
    STATE_MENU,
    STATE_PLAY,
    STATE_SERVE,
    STATE_GAME_OVER,
    STATE_VICTORY,
    STATE_HIGHSCORES,
    STATE_ENTERHIGHSCORES,
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
    int level;
    bool playing;
} PlayState;

typedef struct {
  int score;
} GameOverState;

typedef struct {
    Score* scores;
} GlobalState;

typedef struct {
    int score;
    int new_hiscore_index;
    int selected;
    char* name;
} EnterHighScoreState;

void DrawTitle();
void DrawPlay();

void Update();
void Render();
void enterIntoMenuState();
void enterIntoPlayState();
void enterIntoServeState(int health, int score, int level);
void enterIntoGameOverState(int score);
void enterIntoVictoryState(int health, int score, int level);
void enterIntoHighScoresState();
void enterIntoEnterHighScoreState(Score* scores, int score, int new_hiscore_index);
void StateMachineSetScore();
#endif
