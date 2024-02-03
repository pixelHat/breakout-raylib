#include <stdio.h>
#include "raylib.h"
#include "constants.h"
#include "fonts.h"
#include "utils.h"
#include "state_machine.h"
#include "state_menu.h"
#include "state_play.h"
#include "state_game_over.h"

Game game = { STATE_MENU };

MenuState menuState = { 0 };
PlayState playState = {};
GameOverState gameOverState = {};

void Render() {
  switch (game.currentState) {
    case STATE_MENU:
      RenderStateMenu(game, &menuState);
      break;
    case STATE_PLAY:
      RenderStatePlay(game, &playState);
      break;
    case STATE_GAME_OVER:
      RenderStateGameOver(game, &gameOverState);
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
    case STATE_GAME_OVER:
      UpdateStateGameOver(game, &gameOverState);
      break;
  }
}

void enterIntoMenuStateState() {
  menuState.selected = 0;
  game.currentState = STATE_MENU;
}

void enterIntoPlayState(int health, int score) {
  if (playState.quads == NULL) {
    playState.quads = generateQuadsPaddles();
    playState.paddle = Paddle_init(1, 0);
    playState.isPaused = false;
  }
  playState.ball = Ball_init(0);
  playState.ball_quads = generateQuadsBalls();
  playState.bricks_quads = generateQuadsBricks();
  playState.bricks = create_map(0);
  playState.score = score;
  playState.lives = 3;
  playState.hearts_quads = generateQuadsHearts();
  game.currentState = STATE_PLAY;
}


void enterIntoGameOverState(int score) {
  gameOverState.score = score;
  game.currentState = STATE_GAME_OVER;
}
