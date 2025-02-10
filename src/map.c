#include <allegro5/allegro.h>

#include <stdlib.h>
#include <stdio.h>

#include "../include/map.h"

#define MAP_HEIGHT 12
#define MAP_WIDTH 9
#define DISPLAY_HEIGHT 900

extern ALLEGRO_BITMAP *gram;
extern ALLEGRO_BITMAP *road;

extern int positionx;
extern int positiony;
int bitmapType = 2;
int bitmapPrevious;
int num = 0;

int cam_y = 0;

int map[MAP_HEIGHT] = {
    1, 1
};

void random_map() {
    int i;

    if(bitmapType == 1 && num == 0) {
        num = (rand() % 4)+1;
        bitmapPrevious = bitmapType;
        bitmapType = 2;
        fprintf(stderr, "%da", num);
    } else if(bitmapType == 2 && num == 0) {
        num = (rand() % 7)+1;
        bitmapPrevious = bitmapType;
        bitmapType = 1;
        fprintf(stderr, "%db", num);
    }
    
    for(i = 0; i < MAP_HEIGHT; i++) {
        if(map[i] == 0 && num > 0) {
            map[i] = bitmapPrevious;
            num = num - 1;
        }
    }
          
}


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

void display_follow_player() {
    if(positiony < 96 * 4) {
        cam_y = 96 + cam_y;
        positiony = positiony + 96;
        for(int i = 1; i < MAP_HEIGHT; i++) {
            map[i - 1] = map[i];
        }
        map[11] = 0;
    } else if (positiony == 96) {
        cam_y = 0;
    }
}