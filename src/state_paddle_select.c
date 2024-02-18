#include "state_paddle_select.h"
#include "utils.h"
#include "state_machine.h"
#include "constants.h"
#include "textures.h"
#include "sounds.h"

void RenderStatePaddleSelect(Game gameState, PaddleSelectState* paddleSelectState) {
    UtilsDrawCenteredText("Select your paddle with left and right!", 16, GAMESCREENHEIGHT / 4.0);
    UtilsDrawCenteredText("(Press Enter to continue!)", 16, GAMESCREENHEIGHT / 3.0);

    const Color disabled = { 40, 40, 40, 128 };

    DrawTextureRec(
        globalTextures.arrows,
        paddleSelectState->arrows_quads[0],
        (Vector2) { GAMESCREENWIDTH / 4.0 - 24, GAMESCREENHEIGHT - GAMESCREENHEIGHT / 3.0 },
        paddleSelectState->current_paddle == 0 ? disabled : WHITE
    );

    DrawTextureRec(
        globalTextures.arrows,
        paddleSelectState->arrows_quads[1],
        (Vector2) { GAMESCREENWIDTH - GAMESCREENWIDTH / 4.0, GAMESCREENHEIGHT - GAMESCREENHEIGHT / 3.0 },
        paddleSelectState->current_paddle == 3 ? disabled : WHITE
    );

    DrawTextureRec(
        globalTextures.paddle,
        paddleSelectState->paddles_quads[2 + 4 * paddleSelectState->current_paddle],
        (Vector2) { GAMESCREENWIDTH / 2.0 - 46, GAMESCREENHEIGHT - GAMESCREENHEIGHT / 3.0 + 4 },
        WHITE
    );
}

void UpdateStatePaddleSelect(Game gameState, PaddleSelectState* paddleSelectState) {
    if (IsKeyPressed(KEY_LEFT)) {
        if (paddleSelectState->current_paddle == 0) {
            PlaySound(globalSounds.no_select);
        } else {
            PlaySound(globalSounds.select);
            paddleSelectState->current_paddle--;
        }
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        if (paddleSelectState->current_paddle == 3) {
            PlaySound(globalSounds.no_select);
        } else {
            PlaySound(globalSounds.select);
            paddleSelectState->current_paddle++;
        }
    }

    if (IsKeyPressed(KEY_ENTER)) {
        SetSelectedPaddle(paddleSelectState->current_paddle);
        enterIntoServeState(3, 0, 1);
    }
}
