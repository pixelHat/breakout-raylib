#include "state_machine.h"

#ifndef STATE_GAME_OVER_H
#define STATE_GAME_OVER_H

void RenderStateGameOver(Game game, GameOverState* state);
void UpdateStateGameOver(Game game, GameOverState* state, GlobalState* globalState);

#endif
