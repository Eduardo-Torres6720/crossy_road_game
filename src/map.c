#include <allegro5/allegro.h>

#include <stdlib.h>
#include <stdio.h>

#include "../include/map.h"

#define MAP_HEIGHT 12
#define MAP_WIDTH 9
#define DISPLAY_HEIGHT 900

extern ALLEGRO_BITMAP *gram;
extern ALLEGRO_BITMAP *road;

int map[MAP_HEIGHT] = {
    1, 1, 2, 2, 1, 2, 2, 1, 1, 2, 2, 2
};


void draw_map() {
    int bitmap_width = 96;  // Largura de cada bitmap
    int bitmap_height = 96; // Altura de cada bitmap

    for (int y = 0; y < MAP_HEIGHT; y++) {
        int bitmap_id = map[y]; // id do bitmap a matriz          
        for (int x = 0; x < MAP_WIDTH; x++) {
            int bitmap_x = x * bitmap_width; // Posição x do bitmap na tela
            int bitmap_y = DISPLAY_HEIGHT - ((y+1) * bitmap_height); // Posição y do bitmap na tela

            if (bitmap_id == 1) {
                al_draw_bitmap(gram, bitmap_x, bitmap_y, 0);
            } else if (bitmap_id == 2) {
                al_draw_bitmap(road, bitmap_x, bitmap_y, 0);
            }
        }
    }
}