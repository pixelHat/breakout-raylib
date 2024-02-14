#include "state_machine.h"

#ifndef STATE_PLAY_H
#define STATE_PLAY_H

void RenderStatePlay(Game game, PlayState* state);
void UpdateStatePlay(Game game, PlayState* state);
void draw_score(int score);
void draw_health(int health, Rectangle* hearts_quads);

#endif
