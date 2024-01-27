#include <stdio.h>
#include "raylib.h"
#include "state_machine.h"
#include "constants.h"
#include "fonts.h"
#include "state_menu.h"
#include "state_play.h"
#include "utils.h"

Game game = { STATE_MENU };

MenuState menuState = { 0 };
PlayState playState = {};

void Render() {
  switch (game.currentState) {
    case STATE_MENU:
      RenderStateMenu(game, &menuState);
      break;
    case STATE_PLAY:
      RenderStatePlay(game, &playState);
      break;
  }
}

void Update() {
  switch (game.currentState) {
    case STATE_MENU:
      UpdateStateMenu(game, &menuState);
      break;
    case STATE_PLAY:
      UpdateStatePlay(game, &playState);
      break;
  }
}

void exitMenuState() {
  menuState.selected = 0;
}

void enterIntoPlayState() {
  if (playState.quads == NULL) {
    playState.quads = generateQuadsPaddles();
    playState.paddle = Paddle_init(1, 0);
    playState.isPaused = false;
  }
  playState.ball = Ball_init(0);
  playState.ball_quads = generateQuadsBalls();
  game.currentState = STATE_PLAY;
}
