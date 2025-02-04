#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/graphics.h"

#include <stdio.h>

#define DISPLAY_HEIGHT 900
#define DISPLAY_WIDTH 864
#define MAP_WIDTH 9
#define MAP_HEIGHT 12

ALLEGRO_DISPLAY *display;
ALLEGRO_BITMAP *sprite;
ALLEGRO_BITMAP *gram;
ALLEGRO_BITMAP *road;

int positionx;
int positiony;

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

int al_init_graphics() {
    if(!al_init()) {
        return 1;
    } else if(!al_init_image_addon()) {
        return 1;
    } else {
        display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
        sprite = al_load_bitmap("../assets/parado_costa.png");
        gram = al_load_bitmap("../assets/grama.png");
        road = al_load_bitmap("../assets/estrada.png");
        return 0;
    }
}

void position_sprite() {
    int chicken_width = al_get_bitmap_width(sprite);
    int chicken_height = al_get_bitmap_height(sprite);

    positionx = chicken_width * 4;
    positiony = DISPLAY_HEIGHT - chicken_height;
}

void cleanup_display() {
    al_destroy_bitmap(sprite);
    al_destroy_display(display);
    al_destroy_bitmap(gram);
    al_destroy_bitmap(road);
}

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
