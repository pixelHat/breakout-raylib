#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bricks.h"
#include "textures.h"
#include "utils.h"
#include "sounds.h"
#include "constants.h"

void Brick_draw(Brick* brick, Rectangle* squads) {
    if (brick->in_play) {
        DrawTextureRec(globalTextures.paddle, squads[(brick->color) * 4], brick->position, WHITE);
    }
}

void Brick_hit(Brick* brick) {
    PlaySound(globalSounds.brick_hit_2);

    if (brick->tier > -1) {
        if (brick->color == 1) {
            brick->tier--;
            brick->color = 5;
        } else {
            brick->color--;
        }
    } else {
        if (brick->color == 0) {
            brick->in_play = false;
        } else {
            brick->color--;
        }
    }

    if (!brick->in_play) {
        PlaySound(globalSounds.brick_hit_1);
    }
}

Bricks create_map(int level) {
    int number_of_rows = randomInt(1, 4);
    int number_of_cols = randomInt(7, 12);

    if (number_of_cols % 2 == 1) {
        number_of_cols++;
    }

    int highest_tier = MIN(3, floor(level / 5));
    int highest_color = MIN(5, floor(level % 5 + 3));

    Bricks bricks = (Bricks) {
        .bricks = (Brick*) malloc(sizeof(Brick) * number_of_rows * number_of_cols),
        .size = 0
    };

    for (int y = 0; y < number_of_rows; y++) {
        bool skip_pattern = randomInt(1, 2) == 1;
        bool alternate_pattern = randomInt(1, 2);
        int alternate_color1 = randomInt(1, highest_color);
        int alternate_color2 = randomInt(1, highest_color);
        int alternate_tier1 = randomInt(0, highest_tier);
        int alternate_tier2 = randomInt(0, highest_tier);
        bool skip_flag = randomInt(1, 2) == 1;
        bool alternate_flag = randomInt(1, 2) == 1;
        int solid_color = randomInt(1, highest_color);
        int solid_tier = randomInt(0, highest_tier);

        for (int x = 0; x < number_of_cols; x++) {

            if (skip_flag && skip_pattern) {
                skip_flag = !skip_flag;
                continue;
            } else {
                skip_flag = !skip_flag;
            }

            int tier = 0;
            int color = 0;

            if (alternate_flag && alternate_pattern) {
                color = alternate_color1;
                tier = alternate_tier1;
                alternate_flag = !alternate_flag;
            } else {
                color = alternate_color2;
                tier = alternate_tier2;
                alternate_flag = !alternate_flag;
            }

            if (alternate_pattern) {
                color = solid_color;
                tier = solid_tier;
            }

            bricks.bricks[bricks.size++] = (Brick) {
                .position = (Vector2) {
                    x * 32 + 8 + (13 - number_of_cols) * 16,
                    (y + 1) * 16
                },
                .width = 32,
                .height = 16,
                .tier = tier,
                .color = color,
                .in_play = true
            };
        }
    }
    return bricks;
}
