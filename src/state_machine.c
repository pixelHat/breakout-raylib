#include <stdio.h>
#include "raylib.h"
#include "constants.h"
#include "fonts.h"
#include "utils.h"
#include "state_machine.h"
#include "state_menu.h"
#include "state_play.h"
#include "state_serve.h"
#include "state_victory.h"
#include "state_game_over.h"
#include "state_highscores.h"

Game game = { STATE_MENU };

MenuState menuState = { 0 };
PlayState playState = {};
GameOverState gameOverState = {};
GlobalState  globalState = {};

void setUpPlayState(int health, int score, int level);

void Render() {
    switch (game.currentState) {
        case STATE_MENU:
            RenderStateMenu(game, &menuState);
            break;
        case STATE_PLAY:
            RenderStatePlay(game, &playState);
            break;
        case STATE_SERVE:
            RenderStateServe(game, &playState);
            break;
        case STATE_VICTORY:
            RenderStateVictory(game, &playState);
            break;
        case STATE_HIGHSCORES:
            RenderStateHighScores(&globalState);
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
        case STATE_SERVE:
            UpdateStateServe(game, &playState);
            break;
        case STATE_VICTORY:
            UpdateStateVictory(game, &playState);
            break;
        case STATE_HIGHSCORES:
            UpdateStateHighScores();
            break;
        case STATE_GAME_OVER:
            UpdateStateGameOver(game, &gameOverState);
            break;
    }
}

void enterIntoMenuState(Score* scores) {
    menuState.selected = 0;
    game.currentState = STATE_MENU;
}

void enterIntoPlayState() {
    game.currentState = STATE_PLAY;
}

void enterIntoGameOverState(int score) {
    gameOverState.score = score;
    game.currentState = STATE_GAME_OVER;
}

void enterIntoServeState(int health, int score, int level) {
    setUpPlayState(health, score, level);
    game.currentState = STATE_SERVE;
}

void enterIntoVictoryState(int health, int score, int level) {
    setUpPlayState(health, score, level);
    game.currentState = STATE_VICTORY;
}

void enterIntoHighScoresState() {
    game.currentState = STATE_HIGHSCORES;
}

void StateMachineSetScore() {
    Score* scores = UtilsLoadScore();
    globalState.scores = scores;
}

// private

void setUpPlayState(int health, int score, int level) {
    playState.quads = generateQuadsPaddles();
    playState.paddle = Paddle_init(1, 0);
    playState.isPaused = false;
    playState.ball = BallInit(0);
    playState.ball_quads = generateQuadsBalls();
    playState.bricks_quads = generateQuadsBricks();
    playState.bricks = create_map(0);
    playState.score = score;
    playState.lives = health;
    playState.hearts_quads = generateQuadsHearts();
    playState.level = level;
}
