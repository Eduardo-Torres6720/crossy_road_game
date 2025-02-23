#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#include "../include/chicken.h"
#include "../include/car.h"
#include "../include/scoreboard.h"

extern Chicken chicken_struct;

extern ALLEGRO_BITMAP* numbers[10]; // Array to hold the number bitmaps

void render_score(int score, int x, int y) {
    char score_str[32];

    snprintf(score_str, sizeof(score_str), "%d", score); // Convert the score to a string

    for (int i = 0; score_str[i] != '\0'; i++) {
        int digit = score_str[i] - '0'; // Convert character to integer (0-9)
        al_draw_bitmap(numbers[digit], x, y, 0); // Draw the digit
        x += al_get_bitmap_width(numbers[digit]); // Move x to the right for the next digit
    }
}



