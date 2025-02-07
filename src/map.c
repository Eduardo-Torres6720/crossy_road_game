#include <allegro5/allegro.h>

#include "../include/map.h"

#define MAP_HEIGHT 12
#define MAP_WIDTH 9
#define DISPLAY_HEIGHT 900

extern ALLEGRO_BITMAP *gram;
extern ALLEGRO_BITMAP *road;

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0}
};


void draw_map() {
    int bitmap_width = 96;  // Largura de cada bitmap
    int bitmap_height = 96; // Altura de cada bitmap

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            int bitmap_id = map[y][x]; // id do bitmap a matriz          
            int bitmap_x = x * bitmap_width; // Posição x do bitmap na tela
            int bitmap_y = DISPLAY_HEIGHT - ((y+1) * bitmap_height); // Posição y do bitmap na tela

            if (bitmap_id == 0) {
                al_draw_bitmap(gram, bitmap_x, bitmap_y, 0);
            } else if (bitmap_id == 1) {
                al_draw_bitmap(road, bitmap_x, bitmap_y, 0);
            }
        }
    }
}