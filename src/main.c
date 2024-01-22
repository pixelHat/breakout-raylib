#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))


#define SCREENWIDTH 1280
#define SCREENHEIGHT 720
#define GAMESCREENWIDTH 432
#define GAMESCREENHEIGHT 243

void draw_title(const Font* font) {
    const char* text = "BREAKOUT";
    const int size = 20;
    const float text_width = MeasureText(text, size);
    const Vector2 title_pos = {GAMESCREENWIDTH / 2.0 - text_width / 2.0, GAMESCREENHEIGHT / 2.0 - size / 2.0};
    DrawTextEx(*font, text, title_pos, size, 1, LIGHTGRAY);
}

int main(void) {

    const Font font = LoadFont("./fonts/font.tff");

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Breakout");
    SetWindowMinSize(320, 240);

    // Render texture initialization, used to hold the rendering result so we can easily resize it
    RenderTexture2D target = LoadRenderTexture(GAMESCREENWIDTH, GAMESCREENHEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);  // Texture scale filter to use
    Color colors[10] = { 0 };
    for (int i = 0; i < 10; i++) colors[i] = (Color){ GetRandomValue(100, 250), GetRandomValue(50, 150), GetRandomValue(10, 100), 255 };
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float scale = MIN((float)GetScreenWidth()/GAMESCREENWIDTH, (float)GetScreenHeight()/GAMESCREENHEIGHT);

        if (IsKeyPressed(KEY_SPACE))
        {
            // Recalculate random colors for the bars
            for (int i = 0; i < 10; i++) colors[i] = (Color){ GetRandomValue(100, 250), GetRandomValue(50, 150), GetRandomValue(10, 100), 255 };
        }

        // Update virtual mouse (clamped mouse value behind game screen)
        Vector2 mouse = GetMousePosition();
        Vector2 virtualMouse = { 0 };
        virtualMouse.x = (mouse.x - (GetScreenWidth() - (GAMESCREENWIDTH*scale))*0.5f)/scale;
        virtualMouse.y = (mouse.y - (GetScreenHeight() - (GAMESCREENHEIGHT*scale))*0.5f)/scale;
        virtualMouse = Vector2Clamp(virtualMouse, (Vector2){ 0, 0 }, (Vector2){ (float)GAMESCREENWIDTH, (float)GAMESCREENHEIGHT });

        // Apply the same transformation as the virtual mouse to the real mouse (i.e. to work with raygui)
        //SetMouseOffset(-(GetScreenWidth() - (GAMESCREENWIDTH*scale))*0.5f, -(GetScreenHeight() - (GAMESCREENHEIGHT*scale))*0.5f);
        //SetMouseScale(1/scale, 1/scale);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        // Draw everything in the render texture, note this will not be rendered on screen, yet
        BeginTextureMode(target);
            ClearBackground(RAYWHITE);  // Clear render texture background color

            // DrawText("If executed inside a window,\nyou can resize the window,\nand see the screen scaling!", 10, 25, 20, WHITE);
            // DrawText(TextFormat("Default Mouse: [%i , %i]", (int)mouse.x, (int)mouse.y), 300, 25, 20, GREEN);
            // DrawText(TextFormat("Virtual Mouse: [%i , %i]", (int)virtualMouse.x, (int)virtualMouse.y), 30, 55, 20, YELLOW);
            draw_title(&font);
        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK);     // Clear screen background

            // Draw render texture to screen, properly scaled
            DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
                           (Rectangle){ (GetScreenWidth() - ((float)GAMESCREENWIDTH*scale))*0.5f, (GetScreenHeight() - ((float)GAMESCREENHEIGHT*scale))*0.5f,
                           (float)GAMESCREENWIDTH*scale, (float)GAMESCREENHEIGHT*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }

    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}
