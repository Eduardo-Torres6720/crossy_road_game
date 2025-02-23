#include <allegro5/allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/map.h"
#include "../include/car.h"
#include "../include/tree.h"
#include "../include/chicken.h"
#include "../include/log.h"

#define MAP_HEIGHT 12
#define MAP_WIDTH 9
#define DISPLAY_HEIGHT 900

extern ALLEGRO_BITMAP *gram;
extern ALLEGRO_BITMAP *road;
extern ALLEGRO_BITMAP *car;
extern ALLEGRO_BITMAP *tree;
extern ALLEGRO_BITMAP *water;
extern ALLEGRO_BITMAP *scoreboard;
extern ALLEGRO_BITMAP *tronco;

extern int positiony_car;

extern Car cars[MAP_HEIGHT][3];
extern Tree trees[MAP_HEIGHT][2];
extern Chicken chicken_struct;

int bitmapType = 2;
int bitmapPrevious;
int num = 0;

int cam_y = 0;

int map[MAP_HEIGHT] = {
    1, 1
};

void random_map() {
    int i;

    if (bitmapType == 1 && num == 0) { 
        num = (rand() % 7) + 1;
        bitmapPrevious = bitmapType;
        bitmapType = 2; 
    } 
    else if (bitmapType == 2 && num == 0) { 
        int chance = rand() % 4;

        if (chance == 0) { 
            num = (rand() % 2) + 1;
            bitmapPrevious = bitmapType;
            bitmapType = 3;
        } else { 
            num = (rand() % 4) + 1;
            bitmapPrevious = bitmapType;
            bitmapType = 1; 
        }
    } 
    else if (bitmapType == 3 && num == 0) { 
        num = (rand() % 4) + 1;
        bitmapPrevious = bitmapType;
        bitmapType = 1; 
    }

    if (bitmapType == 3 && bitmapPrevious == 1) {
        bitmapType = 1;
    }

    if (bitmapPrevious == 3 && num > 2) {
        num = 2;
    }

    if (bitmapPrevious == 1 && num > 4) {
        num = 4;
    }

    for (i = 0; i < MAP_HEIGHT; i++) {
        if (map[i] == 0 && num > 0) {
            map[i] = bitmapPrevious;
            num = num - 1;
        }
    }
}

void draw_map() {
    int bitmap_width = 96;
    int bitmap_height = 96;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        int bitmap_id = map[y];
        int bitmap_y = DISPLAY_HEIGHT - ((y + 1) * bitmap_height);

        for (int x = 0; x < MAP_WIDTH; x++) {
            int bitmap_x = x * bitmap_width;

            if (bitmap_id == 1) {
                al_draw_bitmap(gram, bitmap_x, bitmap_y, 0);
                if (x == 0 || x == 8) {
                    trees[y][x / 8].initial_x = bitmap_x;
                    trees[y][x / 8].final_x = bitmap_x + bitmap_width;
                    trees[y][x / 8].position_y = bitmap_y;
                    al_draw_bitmap(tree, bitmap_x, bitmap_y, 0);
                }
            } 
            else if (bitmap_id == 2) {
                al_draw_bitmap(road, bitmap_x, bitmap_y, 0);
            } 
            else if (bitmap_id == 3) {
                al_draw_bitmap(water, bitmap_x, bitmap_y, 0);
            }
        }

        if (bitmap_id == 3) {
            if (!logs[y].exists) {
                set_log(y);
            }
            al_draw_bitmap(tronco, logs[y].initial_x, bitmap_y, 0);
            move_log(&logs[y]);
        }

        int random_number_car = (rand() % 3) + 1;
        if (bitmap_id == 2 && !cars[y][0].exists) {
            for (int i = 0; i < random_number_car; i++) {
                cars[y][i].position_y = bitmap_y;
                cars[y][i].exists = true;
            }
        }
    }
}


void display_follow_player() {
    if(chicken_struct.positiony < 96 * 4) {
        cam_y = 96 + cam_y;
        chicken_struct.positiony = chicken_struct.positiony + 96;
        for(int i = 1; i < MAP_HEIGHT; i++) {
            map[i - 1] = map[i];
            for(int j=0; j<3; j++) {
                cars[i - 1][j] = cars[i][j];
                if(cars[i-1][j].exists) {
                    cars[i-1][j].position_y = 96 + cars[i-1][j].position_y;
                } 
            }
            for(int j=0; j<2; j++) {
                trees[i-1][j] = trees[i][j];
            }
        }
        map[11] = 0;
        for(int j=0; j<3; j++) {
            cars[11][j].exists = false;
            cars[11][j].defined_values = false;
        }
    } else if (chicken_struct.positiony == 96) {
        cam_y = 0;
    }
}