#include "raylib.h"

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
} PlayState;

void DrawTitle();
void DrawPlay();

void Update();
void Render();
void enterIntoPlayState();
void exitMenuState();

#endif
