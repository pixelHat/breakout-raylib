#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "raymath.h"
#include "state_machine.h"
#include "constants.h"
#include "fonts.h"
#include "textures.h"
#include "sounds.h"
#include "utils.h"

int main(void) {


    time_t t;
    srand((unsigned) time(&t));

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Breakout");
    SetWindowMinSize(320, 240);

    Score* scores = UtilsLoadScore();

    Texture2D background = LoadTexture("graphics/background.png");
    NPatchInfo nPatchInfo = { { 0, 0, background.width, background.height }, 12, 12, 12, 12 };
    Rectangle destRec = { 0, 0, GAMESCREENWIDTH + 1, GAMESCREENHEIGHT + 1 };
    LoadGameFonts();
    LoadGameTextures();
    LoadGameSounds();

    StateMachineSetScore();

    // Render texture initialization, used to hold the rendering result so we can easily resize it
    RenderTexture2D target = LoadRenderTexture(GAMESCREENWIDTH, GAMESCREENHEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);  // Texture scale filter to use
    SetTargetFPS(60);
    SetMasterVolume(0.1);

    while (!WindowShouldClose()) {
        float scale = MIN((float)GetScreenWidth()/GAMESCREENWIDTH, (float)GetScreenHeight()/GAMESCREENHEIGHT);

        BeginTextureMode(target);
            ClearBackground(RAYWHITE);
            DrawTextureNPatch(background, nPatchInfo, destRec, (Vector2){ 0, 0 }, 0, WHITE);
            Render();
            Update();
        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
                           (Rectangle){ (GetScreenWidth() - ((float)GAMESCREENWIDTH*scale))*0.5f, (GetScreenHeight() - ((float)GAMESCREENHEIGHT*scale))*0.5f,
                           (float)GAMESCREENWIDTH*scale, (float)GAMESCREENHEIGHT*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }

    UnloadRenderTexture(target);
    UnloadTexture(background);
    UnloadGameFonts();
    UnloadGameTextures();
    UnloadGameSounds();
    CloseWindow();
    return 0;
}
