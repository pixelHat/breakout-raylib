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
#include "state_enter_highscore.h"
#include "state_paddle_select.h"

Game game = { STATE_MENU };

MenuState menuState = { 0 };
PlayState playState = { .playing = true };
GameOverState gameOverState = {};
GlobalState  globalState = {};
EnterHighScoreState enterHighScoreState = {};
PaddleSelectState paddleSelectState = { 0 };

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
        case STATE_ENTERHIGHSCORES:
            RenderStateEnterHighScore(game, &enterHighScoreState);
            break;
        case STATE_PADDLESELECT:
            RenderStatePaddleSelect(game, &paddleSelectState);
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
            UpdateStateGameOver(game, &gameOverState, &globalState);
            break;
        case STATE_ENTERHIGHSCORES:
            UpdateStateEnterHighScore(game, &enterHighScoreState, &globalState);
            break;
        case STATE_PADDLESELECT:
            UpdateStatePaddleSelect(game, &paddleSelectState);
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
    if (playState.lives == 0) {
        setUpPlayState(health, score, level);
    } else {
        playState.ball = BallInit(0);
    }
    game.currentState = STATE_SERVE;
}

void enterIntoVictoryState(int health, int score, int level) {
    setUpPlayState(health, score, level);
    game.currentState = STATE_VICTORY;
}

void enterIntoHighScoresState() {
    game.currentState = STATE_HIGHSCORES;
}

void enterIntoEnterHighScoreState(Score* scores, int score, int new_high_score_index) {
    enterHighScoreState.selected = 0;
    enterHighScoreState.score = score;
    enterHighScoreState.new_hiscore_index = new_high_score_index;
    enterHighScoreState.name = (char*) malloc(sizeof(char) * 4);
    enterHighScoreState.name[0] = 'A';
    enterHighScoreState.name[1] = 'A';
    enterHighScoreState.name[2] = 'A';
    enterHighScoreState.name[3] = '\0';
    game.currentState = STATE_ENTERHIGHSCORES;
}

void enterIntoPaddleSelectState() {
    paddleSelectState.current_paddle = 0;
    paddleSelectState.arrows_quads = generateQuadsArrows();
    paddleSelectState.paddles_quads = generateQuadsPaddles();
    game.currentState = STATE_PADDLESELECT;
}

void StateMachineSetScore() {
    Score* scores = UtilsLoadScore();
    globalState.scores = scores;
}

void SetSelectedPaddle(int selected_paddle) {
    playState.selected_paddle = selected_paddle;
}

// private

void setUpPlayState(int health, int score, int level) {
    playState.quads = generateQuadsPaddles();
    playState.paddle = Paddle_init(1, playState.selected_paddle);
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
